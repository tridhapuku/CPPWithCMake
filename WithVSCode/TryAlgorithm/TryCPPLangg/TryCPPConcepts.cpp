
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

//Sample class helper for C++ RTTI
//https://www.geeksforgeeks.org/rtti-run-time-type-information-in-cpp/
namespace {
    // class B {};  //this will give compilation issue

    class B{
        virtual void func() {} //{}
    };

    class D: public B {};

    

}

void TryCPPLangg::TryCPPConcepts::TestForFuncOverloading(){
    int result1 = add(5,3);

    string resultStr = add("Hello" , " Everyone");

    cout << "Result 1: " << result1 << endl;
    cout << "Result Str :" << resultStr << endl;
}


void TryCPPLangg::TryCPPConcepts::TestForRTTI(){
    B* b = new D; //base class pointer
    D* d = dynamic_cast<D*>(b); //derived class pointer

    if(d != NULL)
        cout << "works\n";
    else
        cout << "can't cast b to d\n";

    
}

void TryCPPLangg::TryCPPConcepts::MainForCPPConcepts(){
    // TryCPPConcepts::TestForFuncOverloading();
    TryCPPConcepts::TestForRTTI();
}
