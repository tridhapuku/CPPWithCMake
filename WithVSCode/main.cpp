#include <iostream>

#include "lib/math/operations.hpp"
// #include <boost/random.hpp>
#include "TryAlgorithm/SimpleProblems/TryRandomQues.hpp"
#include "TryAlgorithm/SimpleProblems/TrySignalProcessing.hpp"
#include "TryAlgorithm/SimpleProblems/TryString.hpp"


#include "TryAlgorithm/TryCPPLangg/TrySTL.hpp"
#include "TryAlgorithm/TryCPPLangg/TryOOP.hpp"
#include "TryAlgorithm/TryCPPLangg/TryConcurrency.hpp"
#include "TryAlgorithm/TryCPPLangg/TryTemplate.hpp"
#include "TryAlgorithm/TryCPPLangg/TryCPPConcepts.hpp"

#include "TryAlgorithm/TryDataStructure/TryTrees.hpp"
#include "TryAlgorithm/TryDataStructure/TryLL.hpp"
#include "TryAlgorithm/TryDataStructure/TrySTLProblems/TryStackProb.hpp"

#include "TrySeparateFolder/TryBeginnerProb.hpp"

// #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

void TestLibMath();
void TestExternalLib();
void TryAlgorithm();
void CheckWhichCPPVersion();
void TrySeparateFolder();


void TestLibMath(){
    math::operations op;

    int sum = op.sum(8,4);

    std::cout << "SSum of 8 + 4 : " << sum << std::endl;

}

void TestExternalLib()
{
    // boost::mt19937 rng;
    // double mean = 2.3;
    // double std = 0.34;
    // auto normal_dist = boost::normal_distribution<double> (mean, std);

    // boost::variate_generator<boost::mt19937& , 
    //         boost::normal_distribution<> > random_number_generator(rng,normal_dist);

    // for (int i = 0; i < 2; i++)
    // {
    //     /* code */
    //     auto rand_val = boost::random::random_number_generator(rng);
    //     std::cout<<"Random Val "<<i+1<<" :"<<rand_val<<std::endl;
    // }

    // boost::random::mt19937 rng; 
    // boost::random::uniform_int_distribution<> six(1,6);
    // int x = six(rng);

    // std::cout << "random dice is : " << x << std::endl;

}

void TryAlgorithm()
{
    // SimpleProblems::RandomProblems::MainForRandomProblems();
    SimpleProblems::SignalProcessing::MainForSignalProcessing();
    // SimpleProblems::TryString::MainForString();


    // TryCPPLangg::TrySTL::MainForCPPLangg();
    // TryCPPLangg::TryOOP::MainForOOP();
    // TryCPPLangg::TryConcurrency::MainForConcurrency();
    // TryCPPLangg::TryTemplate::MainForTemplate();
    // TryCPPLangg::TryCPPConcepts::MainForCPPConcepts();

    // TryDataStructure::TryTrees::mainForTryTrees();
    // TryDataStructure::TryLL::MainForLL();
    // TryDataStructure::TryStackProb::MainForStackProb();
}

void TrySeparateFolder(){
    // CodingPractice::BeginnerLevel::MainForBeginnerLever();
}

auto sum(int a, int b){
    return a + b;
}

void CheckWhichCPPVersion()
{
    if(__cplusplus == 202101L )  std::cout << "C++ 23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";
}

int main(int, char**) {
    std::cout << "Hello, world with cmake!\n";
    // std::cout << " 5*2 = " << 5 * 2 << std::endl;
    // std::cout<<"Sum of 3 + 4 :"<<sum(3, 4)<<std::endl;
    std::cout << "New variable is " << CMAKEMACROSAMPLE <<std::endl;
    CheckWhichCPPVersion();
    
    // TestLibMath();
    // TestExternalLib();
    TryAlgorithm();
    // TrySeparateFolder();
    cout << "Last line258" << endl;
    return 0;
}
