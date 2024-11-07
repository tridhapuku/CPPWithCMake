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
        
        //P3 -- Print All Subsequence
        void PrintAllSubsequence(int indx, vector<int> &arr, vector<int> &subArr, int N);
        void TestPrintAllSubSeq();

        //P4-- Count ALl Subsequence
        int CountAllSubseq(int indx, vector<int> &arr, int sum , int target, int N);
        void TestCountAllSubseq();

        //P5 -- MaxSum for non-adjacent Elem
        int NonAdjacentElemSum(int indx, vector<int> &arr);
        void TestNonAdjacentElemSum();

        void MainForRecursion();

    }
}


#endif