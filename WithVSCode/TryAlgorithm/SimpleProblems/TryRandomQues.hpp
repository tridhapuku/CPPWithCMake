#ifndef TRY_RANDOMQUES_HPP
#define TRY_RANDOMQUES_HPP

#include <string>
#include <vector>
using namespace std ;

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

    //P6
    vector<int> Return2Sum(int *arr1,int len, int n);
    void TestReturn2Sum();

    //P7 - P9 -- Matrix problems
    vector<vector<int>> TryConvolution(vector<vector<int>> Input, vector<vector<int>> Kernel);
    void TestConvolution();

    //P8 -- k largest elements
    void KLargest(vector<int>& v, int N, int K);
    void TestKLargest();

    //P9 -- Linear Regression
    void LinearRegression(vector<int> input, vector<int> output, double &m, double &c);
    void TestLinearRegression();

    //P10 -- check for BST
    struct treeNode{
        treeNode(int data)
        {
            this->data = data;
        }

        int data;
        struct treeNode*left;
        struct treeNode* right;
    };

    bool CheckIfBSTUsingRecursion(struct treeNode* node);
    void TestForBST();


    // P11 --Max subArraySum
    int MaxOf2Values(int a, int b);
    int SumVector(vector<int> &a);
    void PrintArr(vector<int> &a);
    int MaxSubArraySum(vector<int> &a);
    void TestForMaxSubArraySum();

    //P12 --Length of Longest Increasing Subsequence
    int  LengthofLongestIncreasingSeq(vector<int> &a);
    void TestForLIS();

    //P13 -- Encrypt
    //Problems: Encrypt and Decrypt
    string Encrypt(string str1 , string password);
    int ValueForPassChar(char passChar);
    void TestForEncrypt();

    //P14-- ValidParenthesis
    bool isValidParenthesis(string s);
    void TestForParenthesis();

    void MainForRandomProblems();
}
}





#endif