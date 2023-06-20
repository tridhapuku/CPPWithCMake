

#include <iostream>
#include <thread>

#include "TryConcurrency.hpp"


using namespace std;
using namespace TryCPPLangg::TryConcurrency;


void TryCPPLangg::TryConcurrency::TrySysInfo(){
    // const unsigned int numberOfProcessors{ thread::hardware_concurrency() };
    const unsigned int numberOfProcessors{thread::hardware_concurrency()};
    cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;
}

void TryCPPLangg::TryConcurrency::ThreadTask(){
    cout << "Calling from thread" << endl;
    
}

void TryCPPLangg::TryConcurrency::TestForThreadTask(){
    const unsigned int numberOfProcessors{ thread::hardware_concurrency() };
    cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;

    if (numberOfProcessors > 1)
    {
        thread myThread{ThreadTask};
        cout << "Output from main" << endl;
        myThread.join();
    }
    else{
        cout << "CPU does not have multiple cores." << endl;
    }

}
void TryCPPLangg::TryConcurrency::MainForConcurrency(){
    // TryCPPLangg::TryConcurrency::TrySysInfo();
    TryConcurrency::TestForThreadTask();
}