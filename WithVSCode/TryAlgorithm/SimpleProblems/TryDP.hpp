#ifndef TRY_DP_HPP
#define TRY_DP_HPP

#include <string>
#include <vector>
using namespace std ;

namespace SimpleProblems{
namespace DP{
    // public:
        void MainForDPProblems();

    //P1 --Longest Common Subsequence
    // private:
        int getLCS(string &str1, string &str2);
        void TestForLCS();

    //P2 -- Longest Increasing Subsequence
    int getLIS(vector<int> &a);
    void TestForLIS();
    
  }
}

#endif