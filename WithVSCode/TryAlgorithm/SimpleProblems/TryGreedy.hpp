#ifndef TRY_GREEDY_HPP
#define TRY_GREEDY_HPP

#include <string>
#include <vector>
#include "../../GlobalHelper.hpp"

using namespace std ;

namespace SimpleProblems{
    namespace Greedy{
        using namespace GlobalHelper;
        //P1- Activity Selection Problem
        vector<int> MaxActivity(vector<int> &start, vector<int> &end);
        void TestForMaxActivity();

        void MainForGreedy();
    }
}

#endif