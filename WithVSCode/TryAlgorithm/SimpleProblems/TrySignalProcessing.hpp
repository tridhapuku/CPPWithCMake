#ifndef TRY_SIGNALPROCESSING_HPP
#define TRY_SIGNALPROCESSING_HPP


#include <iostream>
#include <complex>
#include <vector>

using namespace std;
namespace SimpleProblems{
    namespace SignalProcessing{

        vector<complex<double>>  fft1(std::vector<std::complex<double>> &a);
        void TestForFFT();

        //zero-crossing detector
        int zeroCrossingDetector(vector<double>& a );
        void TestForZeroCrossingDetector();

        //fir-filter 
        vector<int> GetFIRResponse(vector<int>& filter, vector<int>& impulse);
        void TestForFIRFilter();

        
        void MainForSignalProcessing();
    }
}






#endif