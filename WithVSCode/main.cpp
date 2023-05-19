#include <iostream>

#include "lib/math/operations.hpp"
#include <boost/random.hpp>

// #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

void TestLibMath();
void TestExternalLib();


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

    boost::random::mt19937 rng; 
    boost::random::uniform_int_distribution<> six(1,6);
    int x = six(rng);

    std::cout << "random dice is : " << x << std::endl;

}

auto sum(int a, int b){
    return a + b;
}

int main(int, char**) {
    std::cout << "Hello, world with cmake!\n";
    std::cout << " 5*2 = " << 5 * 2 << std::endl;
    std::cout<<"Sum of 3 + 4 :"<<sum(3, 4)<<std::endl;
    std::cout << "New variable is " << CMAKEMACROSAMPLE <<std::endl;

    // TestLibMath();
    TestExternalLib();
    return 0;
}
