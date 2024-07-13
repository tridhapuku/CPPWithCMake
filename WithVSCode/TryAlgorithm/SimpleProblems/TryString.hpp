#ifndef TRY_STRING_HPP
#define TRY_STRING_HPP

#include <iostream>
using namespace std;

namespace SimpleProblems{
    namespace TryString{


        //Generate a vector of 100 elements
        void GenerateVectorOfLen(int NoOfElements);
        void TestForGenerateVectorOfDesiredLen();

        //Generate complete code with largeNoOfValues
        void GenerateCompleteCode(int NoOfElements, string fileName);
        void TestForGenCompleteCode();

        //Generate a vector for FIR filter a 
        void GenerateVectorOfLenWith1Elem(int NoOfElems, string fileName);
        void TestForGenVectorOfLenWith1Elem();

        
        void MainForString();
    }
}


#endif