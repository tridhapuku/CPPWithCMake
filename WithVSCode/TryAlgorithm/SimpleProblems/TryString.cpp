
#include <iostream>
#include <vector>
#include <complex>
#include <chrono>
// #define _USE_MATH_DEFINES
// #include <cmath>
#include <string>
#include <fstream>

#include "TryString.hpp"

using namespace std;
using namespace SimpleProblems::TryString;
using namespace std::chrono;


string InputCode= R"(def main() { 
    )";

string EndCode = R"(
  var b = 2;
  var d = 4;

  var c = delay(a, b);
  var e = delay(c, d);
  print(e);
}
)";

void SimpleProblems::TryString::GenerateVectorOfLen(int NoOfElements)
{
    int startElem = 10, increment = 10;
    int tempElem = startElem;

    ofstream TestFile("testfile1.py");

    TestFile << "var a = [ " ;
    for (size_t i = 0; i < NoOfElements - 1; i++)
    {
        /* code */
        
        TestFile << tempElem << "," ;
        tempElem = tempElem + increment;

    }

    TestFile << tempElem << " ];" ;
    
}

void SimpleProblems::TryString::TestForGenerateVectorOfDesiredLen()
{
    GenerateVectorOfLen(20000);
}

void SimpleProblems::TryString::GenerateCompleteCode(int NoOfElements, string fileName)
{
    int startElem = 10, increment = 10;
    int tempElem = startElem;

    //open the file & write to the file
    ofstream outFile(fileName);

    //write Init code to the file
    outFile << InputCode << "\n";
    outFile << "\tvar a = [ " ;

    //get the variable-loop
    //write to the file
    for (size_t i = 0; i < NoOfElements - 1; i++)
    {
        /* code */
        
        outFile << tempElem << "," ;
        tempElem = tempElem + increment;

    }

    outFile << tempElem << " ];" ;
    outFile << "\n";

    //append the end-code
    outFile << EndCode ;

    //close the file
    outFile.close();
}

void SimpleProblems::TryString::TestForGenCompleteCode()
{
    //call the function
    GenerateCompleteCode(1000000, "delay1MBack2Back.py");
}

void SimpleProblems::TryString::GenerateVectorOfLenWith1Elem(int NoOfElements, string fileName)
{

    //open the file & write to the file
    ofstream outFile(fileName);

    //write Init code to the file
    outFile << InputCode << "\n";
    outFile << "\tvar a = [1,  " ;

    //get the variable-loop
    //write to the file

    for (size_t i = 1; i < NoOfElements -1; i++)
    {
        /* code */
        
        outFile << "0 " << "," ;
        // tempElem = tempElem + increment;

    }

    outFile << "0 " << " ];" ;
    outFile << "\n";

    //append the end-code
    outFile << EndCode ;

    //close the file
    outFile.close();
   
}

void SimpleProblems::TryString::TestForGenVectorOfLenWith1Elem()
{
    GenerateVectorOfLenWith1Elem(51, "testA.py");
}

void SimpleProblems::TryString::MainForString()
{
    // TestForGenerateVectorOfDesiredLen();
    // TestForGenCompleteCode();
    TestForGenVectorOfLenWith1Elem();
}
