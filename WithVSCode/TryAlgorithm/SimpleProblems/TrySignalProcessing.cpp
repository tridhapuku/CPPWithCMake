
#include <iostream>
#include <vector>
#include <complex>
#include <chrono>
// #define _USE_MATH_DEFINES
// #include <cmath>

#include "TrySignalProcessing.hpp"

using namespace std;
using namespace SimpleProblems::SignalProcessing;
using namespace std::chrono;

//helper functions
namespace {

    void PrintVector(vector<int>& a);



    void PrintVector(vector<int> &a)
    {
        cout << "\nPrinting vector \n";

        for (size_t i = 0; i < a.size(); i++)
        {
           cout << a[i] << " ";
        }
        cout << "\n";
    }

}

const double pi = 3.14159265358979323846;

vector<complex<double>> SimpleProblems::SignalProcessing::fft1(std::vector<std::complex<double>> &samples)
{
    //Get length of array
    int N = samples.size();

    //Base case -- return
    if(N == 1)  {return samples;}

    //if not base case, Divide  into 2 halves- odd & even
    int M = N/2;
    vector<complex<double>> Xeven (M,0); //x0,x2,x4 ...
    vector<complex<double>> Xodd (M,0); //x1,x3,x5 ...

    for (int i = 0; i <M; i++)
    {
        Xeven[i] = samples[2*i]; //Xeven = x0, x2, x4
        Xodd[i] = samples[(2*i) + 1]; //Xodd = x1, x3, x5
    }
    
    //recursively perform fft on even & odd parts
    vector<complex<double>> Feven(M,0);
    Feven = fft1(Xeven);
    vector<complex<double>> Fodd(M,0);
    Fodd = fft1(Xodd);

    //combine the results of even & odd part
    vector<complex<double>> freqbins(N,0);

    for (int k = 0; k < N/2; k++)
    {
        //for each split set, we need to multiply a k-dependent complex 
        //number by the odd subsum
        complex<double> cmplxexponential = polar(1.0, -2*pi*k/N) *Fodd[k];
        freqbins[k] = Feven[k] + cmplxexponential;

        //everytime u add pi, exponential changes sign
        freqbins[k+ N/2] = Feven[k] - cmplxexponential;
    }
    
    return freqbins;
}

void SimpleProblems::SignalProcessing::TestForFFT()
{
    
    vector<complex<double>> data {1.0, 2.0, 3.0, 4.0};
    vector<complex<double>> result(4,0);
    int N = 10000000;
    vector<complex<double>> data1 (N,0);
    vector<complex<double>> result1 (N,0);

    for (size_t i = 0; i < N; i++)
    {
        data1[i] = i + 1;
    }
    

    int indx = 0;

    for (auto &&i : data)
    {
        cout << "data[" << indx << "]= " << i << "\n";
        indx++;
    }

    cout << "After calculating fft " << endl;
    //claculate time for 
    auto beg = high_resolution_clock::now();
    // result = fft1(data);
    result1 = fft1(data1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - beg);
    // result1 = fft1(data1);
    // Displaying the elapsed time
    std::cout << "Elapsed Time In us: " << duration.count() << endl;
    std::cout << "Elapsed Time In s: " << duration.count()/1000000 << endl;

    // indx = 0;
    // for (auto &&val : result)
    // {
    //    cout << "data[" << indx << "]= " << val << "\n";
    //     indx++; 
    // }

    // indx=0;
    // for (auto &&val : result1)
    // {
    //    cout << "data[" << indx << "]= " << val << "\n";
    //     indx++; 
    // }
    
    
}

int SimpleProblems::SignalProcessing::zeroCrossingDetector(vector<double> &a)
{
    //
    int prev = 5; //prev =5 default , 1 = positive & 2 = negative
    int countOfZeroCross = 0;
    //iterate through elements
    //Update prev if positive or negative elem is found
    //Increase count for sign-change , also 
    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        double GetElem = a[i];
        if(prev == 5 && GetElem > 0)
            prev = 1; 
        else if( prev == 5 && GetElem < 0)
            prev = 2;
        else if( prev == 1 && GetElem < 0)
        {
            countOfZeroCross++;
            prev = 2;
        }
        else if( prev == 2 && GetElem > 0)
        {
            countOfZeroCross++; prev = 1;
        }
    }
    
    
    return countOfZeroCross;
}


void SimpleProblems::SignalProcessing::TestForZeroCrossingDetector()
{
    //
    // vector<double> a { -1, 0 , 1, 0, 1 };
    vector<double> a { 1,2,3.3,-3.3,3,-4,-5,-6,4,0,0,0,-1};

    cout << "zero-Cross-Count: "  << zeroCrossingDetector(a) << "\n";
}

vector<int> SimpleProblems::SignalProcessing::GetFIRResponse(vector<int>& input, vector<int>& filter)
{
    int inputLen = input.size();
    int filterLen = filter.size();

    //boundary case
    int OutLen = inputLen + filterLen - 1;

    vector<int> y(OutLen , 0);

    //iterate for each of the o/p
        // iterate for each of the filter 
            //check if input index is valid 
            // add it to tempSum 
            // also, if input index < 0 -- break 

    for (size_t i = 0; i < OutLen; i++)
    {
        int tempSum = 0;
        cout << "y[" << i << "]= " ; 
        for (size_t k = 0; k < filterLen; k++)
        {
            if( (i - k) < 0 )
                break;

            // if( i - k > inputLen - 1)
            //     continue;

            if( i - k <= inputLen - 1)
                tempSum = tempSum + filter[k] * input[i-k];
        }
        y[i] = tempSum;
        
    }
    // PrintVector(y);
    return y;
}

vector<int> SimpleProblems::SignalProcessing::GetFIRResponseSymm1(vector<int> &input, vector<int> &filter)
{
    
    int inputLen = input.size();
    int filterLen = filter.size();

    //boundary case
    int OutLen = inputLen + filterLen - 1;

    vector<int> y(OutLen , 0);
    //y[n] = sum(h[k] .{ x[n-k] + x[n-(L-1-k)]}) + h[L-1/2].x[n-(L-1)/2] , k=0 to L-1/2
    // N = lenY , M = lenX ,  L = lenH

    //for n=0 to N
    // sum = 0, temp =0
    // for k = 0 to L-1/2
        //if 0 <= n-k < M
            //val1 = x[n-k] else, val1 = 0
        // if 0 <= n+k - (L-1) < M
            // val2 = x[n+k-(L-1)] else, val2 = 0
        //temp = val1 + val2
        // sum = sum + h[k] . temp

    //middle-one
        // if 0 <= n - (L-1)/2 < M
            // sum2 = sum + h[L-1/2] . x[n-(n - (L-1)/2)]
        // y[n] = sum2
    int midFilter = filterLen/2;
    cout << "filterLen " << filterLen << "\n";
    cout << "midFilter " << midFilter << "\n";

    for (size_t n = 0; n < OutLen; n++)
    {
        int sum = 0 ;
        for (size_t k = 0; k < midFilter; k++)
        {
            int val1 = 0, val2 = 0 , temp = 0; 
            //if 0 <= n-k < M
                //val1 = x[n-k] else, val1 = 0
            if (n-k >= 0 && n-k < inputLen)
            {
                val1 = input[n-k];
            }

            // if 0 <= n+k - (L-1) < M
                // val2 = x[n+k-(L-1)] else, val2 = 0
            if (n+k-(filterLen -1) >=0 && n+k-(filterLen -1) < inputLen)
            {
                val2 = input[n+k-(filterLen -1)];
            }
            temp = val1 + val2;
            sum = sum + temp * filter[k];
        }
       //middle-one
        // if 0 <= n - (L-1)/2 < M
            // sum2 = sum + h[L-1/2] . x[n- (L-1)/2)] 
        int midFilterIndx = (filterLen -1 )/2;
        cout << "midFilterIndx" << midFilterIndx << "\n";
        int val3 = 0;
        if (n - midFilterIndx >= 0 && n - midFilterIndx < inputLen)
        {
            val3 = input[n - midFilterIndx];
        }

        y[n] = sum + val3 * filter[midFilterIndx];  
    }
    // PrintVector(y);


    return y;
}

void SimpleProblems::SignalProcessing::TestForFIRFilter()
{
    //
    vector<int> input { 2, 1, 3, 2, 4, 10, 11, 13, -2, -1,100};
    // vector<int> input { 1};
    // vector<int> filter {1, -1, 1, 2, 8, 2, 1, -1, 1};
    // vector<int> filter {1, -1, 1,4,1,-1,1};
    vector<int> filter {1, -1, 1,-1,1};

    vector<int> y = SignalProcessing::GetFIRResponse(input, filter);
    vector<int> y1 = SignalProcessing::GetFIRResponseSymm1(input, filter);
    PrintVector(y);
    PrintVector(y1);
}

std::vector<double> SimpleProblems::SignalProcessing::applyEqualization(const std::vector<double> &input_signal, const std::vector<double> &gain_settings, const std::vector<std::vector<double>> &filter_coefficients)
{
    //output signal -- same length as input

    //apply gain for each element of the input

    //apply filter coefficients using convolution


    //accumulate filtered band to output signal


    //normalize o/p signal by no of bands
    
    return std::vector<double>();
}

std::vector<int> SimpleProblems::SignalProcessing::filter(vector<int> b, vector<int> a, vector<int> x)
{
    vector<int> y(x.size(),1);
    y[0] = b[0] * x[0];
    cout << "\nindx =0 " << " sum= " << y[0] << "\n";
    for(int i=1; i<x.size() ; i++){
        int sum = b[0] * x[i];
        for(int j=1; j<=i && j < b.size(); j++){
            sum = sum + b[j]*x[i-j] - a[j] *y[i-j];
        }
    y[i] = sum;
    cout << "indx = " << i << " sum= " << sum << "\n";
    }
    return y;
}

void SimpleProblems::SignalProcessing::TestFilterOperation()
{
    std::vector<int> a {1 ,2, 3,4};
    vector<int> b {3,4,5,10};
    vector<int> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    vector<int> y = filter(b,a,x);

    PrintVector(y);
}

void SimpleProblems::SignalProcessing::MainForSignalProcessing()
{
    // SimpleProblems::SignalProcessing::TestForFFT();
    // SimpleProblems::SignalProcessing::TestForZeroCrossingDetector();
    SignalProcessing::TestForFIRFilter();
    // SignalProcessing::TestFilterOperation();
}
