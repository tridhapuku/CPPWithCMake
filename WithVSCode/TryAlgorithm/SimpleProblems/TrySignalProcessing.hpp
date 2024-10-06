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
        vector<int> GetFIRResponseSymm1(vector<int>& filter, vector<int>& impulse);
        vector<int> ReverseInput(vector<int> &input);        
        vector<int> GetFIRResponseYSymm(vector<int>& filter, vector<int>& impulse);

        void TestForFIRFilter();

        //Audio equlaizer
        std::vector<double> applyEqualization(const std::vector<double>& input_signal,
                                      const std::vector<double>& gain_settings,
                                      const std::vector<std::vector<double>>& filter_coefficients);

        void TestForAudioEqualizer();
        
        std::vector<int> filter(vector<int> b, vector<int> a, vector<int> x);
        void TestFilterOperation();
        

        void MainForSignalProcessing();
    }
}






#endif