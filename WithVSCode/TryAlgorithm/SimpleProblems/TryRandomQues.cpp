#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

#include "TryRandomQues.hpp"
using namespace SimpleProblems;

void RandomProblems::ReverseString(string str1){
    int len = str1.size();
    string strResult ;
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        /* code */
        strResult.push_back(str1[i]);
    }
    
    cout << "Reversed Str is " << strResult << endl;
}

void RandomProblems::TestReverseString(){
    string str1 = "abcd";
    ReverseString(str1);
}


void RandomProblems::FindMissingNoFrmArr(int *arr, int len){
    //find the sum of arr elems 
    //difference from 2 to 1 will be the missing no

    int i = 0;
    int sumOfArrElems = 0;
    for ( i = 0; i < len; i++)
    {
        /* code */
        sumOfArrElems = sumOfArrElems + arr[i];

    }

    //use the formula to calculate sum of n elems
    int sumFrmNFirstElems = len * (len + 1) / 2;

    int MissingNo = sumFrmNFirstElems - sumOfArrElems;

    cout << "sum of arr: " << sumOfArrElems << " sumNElems: " << sumFrmNFirstElems ;
    cout << "\n Missing No = " << MissingNo << endl;

}

void RandomProblems::TestFindMissingNo(){
    int arr1[5] = {0,1,3,4,5};
    int len = 5;

    RandomProblems::FindMissingNoFrmArr(arr1, len);

}

void RandomProblems::CheckBalancedParentheses(string str1){

    map<char, char> mapForBrackets;
    mapForBrackets[')'] = '(';
    mapForBrackets['}'] = '{';
    mapForBrackets[']'] = '[';

    vector<char> vectOfLeftBrac {'(' , '{' , '['};
    stack<char> stackForBrackets;
    bool flag = false;

    for (int i = 0; i < str1.size(); i++)
    {
        /* code */
        if (std::find(vectOfLeftBrac.begin(), vectOfLeftBrac.end(), str1[i]) != 
        vectOfLeftBrac.end())
        {
            stackForBrackets.push(str1[i]);
        }
        else
        {
            // if(stackForBrackets.empty())
            // {
            //     flag = true;
            //     break;
            // }

            char getFrmStack = stackForBrackets.top();
            stackForBrackets.pop();
            cout << "getFrmStack is " << getFrmStack << endl;
            if ( getFrmStack == mapForBrackets[str1[i]])
            {
               continue;
            }
            else{
                flag = true;
                break;
            }
            
            
        }
        
    }

    if (flag == true || !stackForBrackets.empty())
    {
       cout << " Unbalanced brackets \n";
    }
    else{
        cout << "Balanced Brackets \n";
    } 
}

void RandomProblems::TestBalancedParentheses(){
    string str1 = "{{}}[]([]){";

    RandomProblems::CheckBalancedParentheses(str1);
}


void RandomProblems::Merge2SortedArr(int *arr1, int *arr2 , int size1, int size2)
{
    
    // int len1 = sizeof(arr1)/sizeof(arr1[0]);
    // int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int len1 = size1;
    int len2 = size2;
    


    int indx1 = 0, indx2=0 , indxResArr=0;
    int ResArr[len1 + len2] = {0} ;

    int smallerLen = (len1 > len2) ? len2 : len1;
    int totalLen = len1 + len2;

    // for (int i = 0; i < totalLen; i++)
    // {
        while(indx1 < len1 && indx2 < len2)
        {
            if (arr1[indx1] <= arr2[indx2])
            {
                ResArr[indxResArr] = arr1[indx1];
                indx1++;
            }
            else{
                ResArr[indxResArr] = arr2[indx2];
                indx2++;
            }

            indxResArr++; 
        }
        // else{
        //     break;
        // }
   
    // }

    //For remaining elements for arr1
    for (int i = indx1; i < len1; i++)
    {
        ResArr[indxResArr] = arr1[indx1];
        indx1++;
        indxResArr++;
    }

    //add remaining elements for arr2
    for (int i = indx2; i < len2; i++)
    {
        ResArr[indxResArr] = arr2[indx2];
        indx2++;
        indxResArr++;
    }

    int lenOfResArr = len1 + len2;

    for (int i = 0; i < lenOfResArr; i++)
    {
        cout << ResArr[i] << " ";
    }

    cout << endl;
    
    
    

}


void RandomProblems::TestMerge2SortedArr(){
    int arrX[] = {3,6,2,1};

    cout << "size of arrX = " << sizeof(arrX)/ sizeof(arrX[0]) << endl;

    int arr1[] = { 1,2, 3 ,5,100};

    int arr2[] = { 1, 2, 4, 5, 6, 7 , 8, 101};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    RandomProblems::Merge2SortedArr(arr1 , arr2 , size1, size2);
}


int RandomProblems::NthFibNo(int n){
    vector<int> vectFib { 0, 1};

    if( n <= 0)
    {
        cout << " n <= 0 not allowed" << endl;
        return -1;
    }

    if( n >= 1 && n <= 2 )
        return vectFib[n-1];

    int i = 2;
    int sum = 0;

    while(i <= n)
    {
      sum = vectFib[i-1] + vectFib[i-2];  
      vectFib.push_back(sum);
      i++;
    }
    return vectFib[n-1];
}

void RandomProblems::TestNthFibNo(){

    int n = 16;

    for (size_t i = 1; i <= n; i++)
    {
        cout << RandomProblems::NthFibNo(i) << " ";
    }
    
    cout << endl;
}
void RandomProblems::MainForRandomProblems(){
    // RandomProblems::TestReverseString();

    // RandomProblems::TestFindMissingNo();
    // RandomProblems::TestBalancedParentheses();

    // RandomProblems::TestMerge2SortedArr();
    RandomProblems::TestNthFibNo();

} 