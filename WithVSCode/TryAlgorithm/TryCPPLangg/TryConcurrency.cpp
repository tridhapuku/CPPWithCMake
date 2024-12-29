

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
    cout << "Calling from child thread 1" << endl;
    
}

void TryCPPLangg::TryConcurrency::ThreadTask1(){
    cout << "Calling from child thread 2" << endl;
    
}

void TryCPPLangg::TryConcurrency::TestForThreadTask(){
    const unsigned int numberOfProcessors{ thread::hardware_concurrency() };
    cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;

    // while(1){
        if (numberOfProcessors > 1)
        {
            thread myThread{ThreadTask};
            thread myThread1{ThreadTask1};
            // thread myThread2{ThreadTask};
            cout << "Output from main" << endl;
            myThread.join();
            myThread1.join();
            // myThread2.join();
        }
        else{
            cout << "CPU does not have multiple cores." << endl;
        }

    cout << "this is parrent process\n ";

    // }

}
void TryCPPLangg::TryConcurrency::MainForConcurrency(){
    // TryCPPLangg::TryConcurrency::TrySysInfo();
    TryConcurrency::TestForThreadTask();
}