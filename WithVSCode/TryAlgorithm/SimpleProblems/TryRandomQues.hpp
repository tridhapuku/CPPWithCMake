#ifndef TRY_RANDOMQUES_HPP
#define TRY_RANDOMQUES_HPP

#include <string>
using namespace std;

namespace SimpleProblems{
namespace RandomProblems{
    //P1
    void ReverseString(string str1);
    void TestReverseString();

    //P2
    void FindMissingNoFrmArr(int *arr, int size);
    void TestFindMissingNo();

    //P3
    void CheckBalancedParentheses(string str1);
    void TestBalancedParentheses();

    //P4
    void Merge2SortedArr(int *arr1, int *arr2, int size1, int size2);
    void TestMerge2SortedArr();

    //P5
    int NthFibNo(int n);
    void TestNthFibNo();

    void MainForRandomProblems();
}
}





#endif