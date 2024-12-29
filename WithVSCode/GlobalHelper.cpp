
#include <iostream>
#include <vector>
#include <complex>
#include <chrono>
// #define _USE_MATH_DEFINES
// #include <cmath>

#include "GlobalHelper.hpp"

using namespace::GlobalHelper;

void GlobalHelper::PrintVect(vector<int> &a)
{
    cout << "\nPrinting vector \n";

    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}