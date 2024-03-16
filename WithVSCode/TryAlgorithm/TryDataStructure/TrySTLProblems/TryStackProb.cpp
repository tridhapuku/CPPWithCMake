
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include "TryStackProb.hpp"

using namespace std;

void TryDataStructure::TryStackProb::Prob1_MatchingSymbols(string str1)
{
    // string

    map<char, char> mapForChars;
    mapForChars = {{'(', ')'},
                   {'{', '}'},
                   {'[', ']'}};

    // mapForChars operations
    // for (auto x : mapForChars)
    // {
    //     /* code */
    //     cout << "key : " << x.first << " value: " << x.second << endl;
    // }

    // set for closing braces
    set<char> setForClosingBraces{')', '}', ']'};

    // if str1 is empty return
    // else: check for first char --
    // if clsoing Braces -- return error
    // else push on stack
    // iterate till no characters left
    //  if char in map then push on stack
    // else if char in set -- pop from stack
    // match popped_item from stack with char
    // if no match -- error
    stack<char> stackForChar;
    bool flag = 0;
    int lengthOfInput = 0;
    cout << "Input str is " << str1 << endl;
    for (char c : str1)
    {
        // cout << "char no " << lengthOfInput << " char: " << c << endl;
        lengthOfInput++;
        if (mapForChars.contains(c))
        {
            stackForChar.push(c);
        }
        else if(setForClosingBraces.contains(c))
            {
                // closing braces found
                if (stackForChar.empty())
                {
                    flag = 1;
                    cout << "Stack empty --Length Parsed : " << lengthOfInput << " char: " << c << endl;
                    break;
                }
                
                char popFromStack = stackForChar.top();
                stackForChar.pop();
                if (c != mapForChars[popFromStack])
                {
                    flag = 1;
                    cout << "Error in matching parenthesis --Length Parsed : " << lengthOfInput << " char: " << c << endl;
                    break;
                }
            }
        else{
            flag =1;
            cout << "Error in matching parenthesis: Unknown character "
                 << c << endl;
            break;
        }
    }

    if(stackForChar.empty() == false)
    {
        cout << "Stack not empty-- Missing parenthesis \n";
        return;
    }

    if (flag == 0 && stackForChar.empty())
    {
        cout << "Matching parenthesis -- Length Parsed : " << lengthOfInput << endl;
    }
    else {
        cout << "See failure above\n";
    }
}

void TryDataStructure::TryStackProb::Test_ForProblems()
{
    string str1 = "([{)])";
    vector<string> vectStr { str1, " " , "}" , "{}", "[]{}("};
    for (auto &&str1 : vectStr)
    {
        Prob1_MatchingSymbols(str1);
    }
    
    
}

void TryDataStructure::TryStackProb::MainForStackProb()
{
    Test_ForProblems();
}
