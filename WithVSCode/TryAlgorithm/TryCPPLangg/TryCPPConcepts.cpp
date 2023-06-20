
#include <iostream>
#include <string>

#include "TryCPPConcepts.hpp"

using namespace TryCPPLangg::TryCPPConcepts;
using namespace std;

namespace{
    int add(int a, int b){
        return a + b;
    }

    string add(const string& a , const string& b){
        return a + b;
    }
}

void TryCPPLangg::TryCPPConcepts::TestForFuncOverloading(){
    int result1 = add(5,3);

    string resultStr = add("Hello" , " Everyone");

    cout << "Result 1: " << result1 << endl;
    cout << "Result Str :" << resultStr << endl;
}


void TryCPPLangg::TryCPPConcepts::MainForCPPConcepts(){
    TryCPPConcepts::TestForFuncOverloading();
}
