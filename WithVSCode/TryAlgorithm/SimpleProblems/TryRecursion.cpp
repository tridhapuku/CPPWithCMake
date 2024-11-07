
// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>
#include "TryRecursion.hpp"

using namespace SimpleProblems::TryRecursion;

namespace{
     int Gcount = 0;

    void PrintVector(vector<int>& a);



    void PrintVector(vector<int> &a)
    {
        // cout << "\nPrinting vector \n";

        for (size_t i = 0; i < a.size(); i++)
        {
           cout << a[i] << " ";
        }

        if(a.size() == 0)
            cout << "{}" << endl;

        cout << "\n";
    }
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

#define N1 3
void SimpleProblems::TryRecursion::TestForGenAllBinStrOfN()
{
    int N = 3;

    int arr[N1];
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



void SimpleProblems::TryRecursion::PrintAllSubsequence(int indx, vector<int> &arr, vector<int> &subArr , int N)
{
    if(indx >= N){
        PrintVector(subArr);
        return;
    }

    //add an element to the subArr
    subArr.push_back(arr[indx]);
    PrintAllSubsequence(indx + 1, arr, subArr, N);

    //don't take the element --
    subArr.pop_back();
    PrintAllSubsequence(indx + 1, arr, subArr, N);
}

void SimpleProblems::TryRecursion::TestPrintAllSubSeq()
{
    vector<int> arr{3,1,2};
    vector<int> subArr;

    PrintAllSubsequence(0, arr, subArr, arr.size());
    
}

int SimpleProblems::TryRecursion::CountAllSubseq(int indx, vector<int> &arr, int sum, int target, int N)
{
    //base case
    if(indx >= N){
        if(sum == target)
            return 1;
        else
            return 0;
    }

    //recursive case 
    //update sum with adding 1 more elem
    sum = sum + arr[indx];
    int l = CountAllSubseq(indx + 1, arr , sum , target, N);

    //update sum for dropping next elem
    sum = sum - arr[indx];
    int r = CountAllSubseq(indx + 1, arr, sum , target, N);

    return l + r;
}

void SimpleProblems::TryRecursion::TestCountAllSubseq()
{
    vector<int> arr{1,2,1};
    int target = 4; 
    int count = CountAllSubseq(0, arr, 0, target, arr.size());

    cout << "countOfSubSeq= " << count << endl;
}

int SimpleProblems::TryRecursion::NonAdjacentElemSum(int indx, vector<int> &arr)
{
    cout << "indx= " << indx << endl;
    if(indx == 0) return arr[indx];
    if(indx <0) return 0;

    int pickElemAtIndxI = INT_MIN;
    pickElemAtIndxI = NonAdjacentElemSum(indx-2 , arr) + arr[indx];
    int NonPickElem = NonAdjacentElemSum(indx-1 , arr);

    cout << "indx= " << indx << " pickElemAtIndxI= " << pickElemAtIndxI ;
    cout <<  " NonPickElem= " << NonPickElem  << endl;
    int max1 = (pickElemAtIndxI >= NonPickElem) ? pickElemAtIndxI : NonPickElem;
    return max1;
    // return std::max(pickElemAtIndxI , NonAdjacentElemSum);
}

void SimpleProblems::TryRecursion::TestNonAdjacentElemSum()
{
    vector<int> arr{2,7,6,2};
    
    int maxSum = NonAdjacentElemSum( arr.size() - 1, arr);
    cout << "maxSum= " << maxSum << endl;
}

void SimpleProblems::TryRecursion::MainForRecursion()
{
    // TestForGenAllBinStrOfN();
    // TestPrintNto1Backtrack();
    // TestPrintAllSubSeq();
    // TestCountAllSubseq();
    TestNonAdjacentElemSum();
}