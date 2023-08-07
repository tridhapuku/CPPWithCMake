
#include <iostream>
#include <string>
#include <memory>

#include "TryMemoryManagement.hpp"

using namespace TryCPPLangg::TryMemoryManagement;
using namespace std;

namespace {

}


void TryCPPLangg::TryMemoryManagement::TestForUniquePtr(){
    // 
    class MyClass{
        public:
            MyClass(){
                cout << "In constructor" << endl;
            }
            ~MyClass(){
                cout << "In destructor" << endl;
            }
        
    };

    // create a unique ptr using make_unique function
    unique_ptr<MyClass> p1 = make_unique<MyClass> ();

    //try copying -- should give error
    // unique_ptr<MyClass> p2 = p1;

    //With move function, we can transfer ownership
    unique_ptr<MyClass> p3 = move(p1);

    
}

void TryCPPLangg::TryMemoryManagement::MainForMemoryManagement(){

    TryCPPLangg::TryMemoryManagement::TestForUniquePtr();

}