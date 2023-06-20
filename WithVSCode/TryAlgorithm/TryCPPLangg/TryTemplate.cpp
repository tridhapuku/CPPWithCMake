
#include <iostream>
#include <string>
#include <memory>
#include "TryTemplate.hpp"

using namespace std;
using namespace TryCPPLangg::TryTemplate;



template <typename T>
T TryCPPLangg::TryTemplate::Add(const T& a, const T& b){
    return a + b;
}

void TryCPPLangg::TryTemplate::TestForTemplateAdd(){
    const int number1{ 1 };
    const int number2{ 2 };
    const int result{Add(number1 , number2)};

    string str1 {"I am good"};
    string str2 {"How are you"};
    string resultStr { Add(str1, str2)};

     
    cout << "The result of adding" << endl;
    cout << number1 << endl;
    cout << "to" << endl;
    cout << number2 << endl;
    cout << "is" << endl;
    cout << result;

    cout << "Result string is " << resultStr << endl;

}

void TryCPPLangg::TryTemplate::ContextForUniquePtr(){
        class A {
        public: 
            void show() { std::cout << "A;: show" << endl ;}

    };

    unique_ptr<A> p1(new A);
    p1->show();

    //memory address of p1
    cout << p1.get() << endl;

    //transfers ownership to p2
    unique_ptr<A> p2 = move(p1);

    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<A> p3 = move(p2);

    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
 
}

void TryCPPLangg::TryTemplate::TestForUniquePtr(){

    ContextForUniquePtr();

    
}

void TryCPPLangg::TryTemplate::MainForTemplate(){
    // TryCPPLangg::TryTemplate::TestForTemplateAdd();
    TryCPPLangg::TryTemplate::TestForUniquePtr();
}
