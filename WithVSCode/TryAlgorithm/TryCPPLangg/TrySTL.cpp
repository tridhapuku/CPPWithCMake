
#include <iostream>
#include <time.h>
#include <map>
#include <string>
#include <stack>
#include <queue>

#include "TrySTL.hpp"

using namespace std;
using namespace TryCPPLangg;

void TrySTL::TryList(){
    //simple check for list 
    vector<int> g1{2,5,9,11};

    for (int i = 0; i < g1.size(); i++)
    {
        /* code */
        cout << g1[i] << " ";
    }
    
    cout << endl;

    //init for seed
    srand(time(NULL));

    //Add few more elements to vector
    for (int i = 0; i < 4; i++)
    {
        /* code */
        int temp = rand() % 100 ;

        g1.push_back(temp);
    }
    
    for (int i = 0; i < g1.size(); i++)
    {
        /* code */
        cout << g1[i] << " ";
    }



} 

void TrySTL::TryMap(){
    //Map = dictionary of keys & values
    map<string, int> mapStrInt1;

    mapStrInt1["Anand"] = 100;
    mapStrInt1["Bhavya"] = 20;
    mapStrInt1["Dev"] = 103;

    //define an iterator to iterator
    map<string, int> ::iterator it;
    cout << "Keys   &   values" << endl;

    for ( it = mapStrInt1.begin(); it != mapStrInt1.end(); it++)
    {
        /* code */
        cout << it->first << "  &   " << it->second << endl;
    }
    
    cout << mapStrInt1["Anand"] << endl;

    //TryMap for brackets
    map<string, string> mapForBrackets;

    mapForBrackets["("] = ")";
    mapForBrackets["{"] = "}";
    mapForBrackets["["] = "]";

    string str1 = "(";

    if (mapForBrackets.find(str1) != mapForBrackets.end())
    {
        /* code */
        cout << "Key found " << "& Value is " << mapForBrackets[str1] << endl;
    }
    else
    {
        cout << "Key not found\n";
    }
    

}

void TrySTL::TryStack(){
    stack<char> stackStr1;
    string str1 = "abcdefgh";

    for (int i = 0; i < str1.size(); i++)
    {
        /* code */
        stackStr1.push(str1[i]);
    }
    
    // remove last 4 elements from stack 
    vector<string> vectStr1;

    for (int i = 0; i < 4; i++)
    {
        /* code */
        cout << stackStr1.top() << " ";
        stackStr1.pop();
    }
    cout << endl;

    //print elements of stack
    // stack<string> ::iterator it;
    cout << "Output remaining stack elements\n";
    while (!stackStr1.empty())
    {
        /* code */
        cout << stackStr1.top() << " ";
        stackStr1.pop();
    }
    
    cout << "Stack Top when empty is " << stackStr1.top() << endl;
    
}

void TrySTL::TryQueue(){
    queue<int> gquiz;

    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    cout << "The queue gquiz is \n" ;
    while(!gquiz.empty()){
        cout << gquiz.front() << "->";
        gquiz.pop();
    }
    cout << endl;
}


void TrySTL::MainForCPPLangg(){
    // TrySTL::TryList();
    // TrySTL::TryMap();

    // TrySTL::TryStack();
    TrySTL::TryQueue();
}