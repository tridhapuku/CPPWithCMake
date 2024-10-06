
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include "TryRecursion.hpp"

using namespace SimpleProblems::TryRecursion;

namespace{
     int Gcount = 0;
}

void printArr(int arr[], int N){

    for (int i=0; i < N ; i++)
    {
        cout << arr[i] << " " ;
    } 
    cout << "\n";
}

void SimpleProblems::TryRecursion::GenerateAllBinaryStringsOfNBits(int arr[], int N, int i)
{
    if(i == N){
        Gcount = Gcount + 1;
        printArr(arr, N);
        return;
    }
    else{
        arr[i] = 0;
        GenerateAllBinaryStringsOfNBits(arr , N , i+1);

        arr[i] = 1;
        GenerateAllBinaryStringsOfNBits(arr, N, i+1);

        // arr[i] = 2;
        // GenerateAllBinaryStringsOfNBits(arr, N, i+ 1);

    }

}

void SimpleProblems::TryRecursion::TestForGenAllBinStrOfN()
{
    int N = 3;

    int arr[N];
    cout << "count = " << Gcount << "\n";
    GenerateAllBinaryStringsOfNBits(arr , N, 0);
    cout << "count = " << Gcount << "\n";
}

// N to 1 using backtrack ==> N should be called first at the end of recurion
// => the numbers should increase during recursion call 
void SimpleProblems::TryRecursion::PrintNto1Backtrack(int n, int N)
{
   if(n > N){
     return;
   }
        
    //else, increment and call the same func
    PrintNto1Backtrack(n +1 , N);
    cout << n << "\n";
    
}

void SimpleProblems::TryRecursion::TestPrintNto1Backtrack()
{
    cout << "Testing backtrack printing\n" ;

    PrintNto1Backtrack(1,10);
}

void SimpleProblems::TryRecursion::MainForRecursion()
{
    // TestForGenAllBinStrOfN();
    TestPrintNto1Backtrack();
}