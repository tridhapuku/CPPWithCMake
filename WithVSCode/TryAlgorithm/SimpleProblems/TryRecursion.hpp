#ifndef TRY_RECURSION_HPP
#define TRY_RECURSION_HPP


#include <iostream>
#include <complex>
#include <vector>


using namespace std;
namespace SimpleProblems{
    namespace TryRecursion{ 


        //P1 -- GenerateAllStringsOfNBits
        void GenerateAllBinaryStringsOfNBits(int arr[],int N, int i);
        void TestForGenAllBinStrOfN();

        //P2 -- Print N to 1
        void PrintNto1Backtrack(int n, int N);
        void TestPrintNto1Backtrack();
        
        void MainForRecursion();

    }
}


#endif