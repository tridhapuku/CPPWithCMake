#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric> //For std::accumulate 


#include "TryGreedy.hpp"
#include "TryRandomQues.hpp"

using namespace SimpleProblems::Greedy;
using namespace SimpleProblems::RandomProblems;

vector<int> SimpleProblems::Greedy::MaxActivity(vector<int> &start, vector<int> &end)
{
    //steps: assumption end array is sorted 
    // iterate for all the end array 
    // check if end[prev] < start[next] --> add to ans vector 
    vector<int> ans;

    int len = end.size();
    if( len <= 0) return ans;
    ans.push_back(0); 

    //len > 1
    int prev = 0;
    for (size_t i = 0; i < len-1; i++)
    {
        if(end[prev] < start[i+1]){
            ans.push_back(i+1);
            prev = i+1;
        }
        //else don't do anything, just increment indx 
    }
     

    return ans;
}

void SimpleProblems::Greedy::TestForMaxActivity()
{
    // vector<int> start{ 1, 3, 0, 5, 8, 5 };
    // vector<int>   end{ 2, 4, 6, 7, 9, 9 };

    vector<int> start{10, 12, 20};
    vector<int>   end{20, 25, 30};

    auto ans = MaxActivity(start , end);
    GlobalHelper::PrintVect(ans);
}

void SimpleProblems::Greedy::MainForGreedy()
{
    TestForMaxActivity();
}
