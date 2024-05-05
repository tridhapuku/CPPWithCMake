
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric> //For std::accumulate 


#include "TryDP.hpp"
#include "TryRandomQues.hpp"

using namespace SimpleProblems::DP;
using namespace SimpleProblems::RandomProblems;
using namespace std;

int SimpleProblems::DP::getLCS(string &str1, string &str2)
{
    //take a matrix of size m+1 , n+1
    //init the first row and column as 0
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> LCS2d (m+1, vector<int> (n+1 , 0));

    int maxLCS = 0;
    
    //iterate for i=1 to m 
    //iterate for j=1 to n
        // if the characters match , lcs(i,j) = lcs(i-1,j-1) + 1
        //  & also, check for maxLCS
        // if no match , lcs(i,j) = max[lcs(i-1,j) , lcs(i, j-1)]
    
    for (size_t i = 1; i < LCS2d.size(); i++)
    {
        vector<int> row = LCS2d[i];

        for (size_t j = 1; j < row.size(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                LCS2d[i][j] = LCS2d[i-1][j-1] + 1;
                maxLCS = (maxLCS > LCS2d[i][j]) ? maxLCS : LCS2d[i][j];
            }
            else{
                int val1 = LCS2d[i-1][j] , val2 = LCS2d[i][j-1];
                LCS2d[i][j] = val1 > val2 ? val1 : val2;
            }

            
        }
       RandomProblems::PrintArr(LCS2d[i]); 
    }
    
    return maxLCS;
}

void SimpleProblems::DP::TestForLCS()
{
    string str1 = "xyxynmeabcdef";
    string str2 = "abxyxycdnmef";

    cout << "MaxLCS= " << getLCS(str1 , str2) << "\n"; 
}

int SimpleProblems::DP::getLIS(vector<int> &a)
{
    //init a vector of length m with 1
    vector<int> LIS (a.size() , 1);
    int maxLIS = 0;

    //iterate over the length from i=1 to m
        //also, iterate from 0 to i-1
            //if a[i] > a[j] then LISVect[i] = max(LISVect[i] , LIS[j] + 1)
        //also, update maxLIS
    for (size_t i = 1; i < LIS.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                LIS[i] = LIS[i] > (LIS[j] + 1) ? LIS[i] : (LIS[j] + 1);
            }
        }
       maxLIS = maxLIS > LIS[i] ? maxLIS : LIS[i];

       RandomProblems::PrintArr(LIS); 
    }
    
    return maxLIS;
}

void SimpleProblems::DP::TestForLIS()
{
    vector<int> a = {1,2,3,4,5,6,7, 10, 11, 5,6,7,1,0,2};

    cout << "MaxLIS = " << getLIS(a) << "\n";
}

void SimpleProblems::DP::MainForDPProblems()
{
    // TestForLCS();
    TestForLIS();
}