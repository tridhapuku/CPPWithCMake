#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric> //For std::accumulate 

#include "TryRandomQues.hpp"
using namespace SimpleProblems;
using namespace std;

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
    int len1 = 10;
    int len2 = 10;
    


    int indx1 = 0, indx2=0 , indxResArr=0;
    int ResArr[100] = {0} ;

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

void PrintMapElements(map<int,int> map1){

    // map<int,int>::iterator it;

    // for(it = map1.begin(); it != map1.end(); it) 
    for(auto pair:map1)
    {
        cout << "key: " << pair.first << " value: " << pair.second << "\n";
    }
}

vector<int> RandomProblems::Return2Sum(int *arr1, int len,int sum){
    vector<int> Results2 ;
    map<int,int> mapForIndexes;

    for (int i = 0; i < len; i++)
    {
        /* code */
        int FirstNo = arr1[i];
        int complementOf1stNo = sum - FirstNo;

        if(mapForIndexes.find(FirstNo) != mapForIndexes.end()){
            PrintMapElements(mapForIndexes);
            Results2.push_back(mapForIndexes[FirstNo]);
            Results2.push_back(i);   
            return Results2;
        }
        else{
            mapForIndexes[complementOf1stNo] = i;
        }

    }
    
    return {-1, -1};
    

}
void SimpleProblems::RandomProblems::TestReturn2Sum()
{
    int arr1[] = {1,4,9,5,7};
    int len = 5 , sum = 12;

    vector<int> GetResult {-1,-1};

    GetResult = Return2Sum(arr1, len, sum);

    if(GetResult[0] == -1 )
    {
        cout << " 2 sum no not found\n";
    }
    else{
        cout << "2 sum nos found!!!!: " ;
        cout << "1stNo= " << arr1[GetResult[0]] << 
                " 2ndNo= " << arr1[GetResult[1]] << "\n";
    }

}

void Print2DVect(vector<vector<int>> &Input)
{
    cout << "Printing 2D-Matrix \n";
    for (size_t i = 0; i < Input.size(); i++)
    {
        cout << "\n";
        for (size_t j = 0; j < Input[i].size(); j++)
        {
            cout << Input[i][j] << " -> " ;
        }
        // cout << " Input[i].size() " << Input[i].size() << "\n";
    }
    
}

vector<vector<int>> SimpleProblems::RandomProblems::TryConvolution(vector<vector<int>> Input, vector<vector<int>> Kernel)
{
    int IP_NoOfRows = Input.size();
    
    if(IP_NoOfRows <= 0)
    { 
        cout << "Empty Input Matrix" << "\n";
        // return ;
    }
    int IP_NoOfCols = Input[0].size();
    

    int K_NoOfRows = Kernel.size();

    if(K_NoOfRows <= 0)
    { 
        cout << "Empty Kernel Matrix" << "\n";
        // return ;
    }
    int K_NoOfCols = Kernel[0].size();

    int OP_NoOfRows = IP_NoOfRows - K_NoOfRows + 1;
    int OP_NoOfCols = IP_NoOfCols - K_NoOfCols + 1;

    // //NoOfCOls for OP
    vector<int> vectof1Col(OP_NoOfCols , 0);
    vector<vector<int>> OP (OP_NoOfRows , vectof1Col);
    
    for (int op_x = 0; op_x < OP.size(); op_x++)
    {
        for (int op_y = 0; op_y < OP[op_x].size(); op_y++)
        {
            int sum = 0 , ip_x = op_x , ip_y = op_y;
            for (int k_x = 0; k_x < K_NoOfRows; k_x++)
            {
                for (int k_y = 0; k_y < K_NoOfCols; k_y++)
                {
                    sum = sum + Input[ip_x + k_x][ip_y + k_y] * Kernel[k_x][k_y];
                }
            }
           OP[op_x][op_y] = sum; 
        }
    }
    
    // Print2DVect(OP);
    
    return OP;
}

void SimpleProblems::RandomProblems::TestConvolution()
{
    //Kernel
    vector<vector<int>> Input = {
        {1,1,1}, {1,1,1}, {1,1,1}
    };

    int IP_NoOfCols = Input[0].size();
    int IP_NoOfRows = Input.size();
    cout << "IP_NoOfCols " << IP_NoOfCols << "\n" ;
    cout << "IP_NoOfRows " << IP_NoOfRows << "\n" ;

    vector<vector<int>> Kernel = {
        {1,1}, {1,1}
    };

    int K_NoOfRows = 2; //Kernel.size();
    int K_NoOfCols = 2; //Kernel[0].size();

    int OP_NoOfRows = IP_NoOfRows - K_NoOfRows + 1;
    int OP_NoOfCols = IP_NoOfCols - K_NoOfCols + 1;

    //NoOfCOls for OP
    vector<int> vectNoOfCols(OP_NoOfCols , 0);

    vector<vector<int>> OP (OP_NoOfRows , vectNoOfCols);
    cout << "OP_NoOfCols " << OP_NoOfCols << "\n" ;
    cout << "OP_NoOfRows " << OP_NoOfRows << "\n" ;

    Print2DVect(OP);
    
    for (int op_x = 0; op_x < OP.size(); op_x++)
    {
        for (int op_y = 0; op_y < OP[op_x].size(); op_y++)
        {
            int sum = 0 , ip_x = op_x , ip_y = op_y;
            for (int k_x = 0; k_x < K_NoOfRows; k_x++)
            {
                for (int k_y = 0; k_y < K_NoOfCols; k_y++)
                {
                    sum = sum + Input[ip_x + k_x][ip_y + k_y] * Kernel[k_x][k_y];
                    // ip_y++;
                }
                // ip_x++;
            }
           OP[op_x][op_y] = sum; 
        }
    }
    
    Print2DVect(OP);
}

void SimpleProblems::RandomProblems::KLargest(vector<int> &v, int N, int K)
{
    //Steps 
    //given a vector with size N & input K 
    //Code
    // Add elements to a priority queue
    // Keep on adding elements till K 
    //if element added is > K 
    // remove the item from the priority queue
    //add this item 
    
}

void SimpleProblems::RandomProblems::TestKLargest()
{

}


int sumOfProdOfError(vector<int> &vect1, vector<int> &vect2)
{
    int sum = 0;
    for (int i = 0; i < vect1.size(); i++)
    {
        sum = sum + vect1[i] * vect2[i];
    }
    
    return sum;
}

void SimpleProblems::RandomProblems::LinearRegression(vector<int> input, vector<int> output, double &m, double &c)
{
    cout << "Initial m= " << m << "c= " << c << "\n";
    //Pseudo-code 
        // Decide NoOfIterations = 1000 , LearningRate = 0.01
        // Iterate for NoOfIterations
            // iterate for all input
            // get the error vector
            // calculate partial_derivate of m 
            //calcualte partial_derivative of c
            // update m 
            //update c

    int NoOfIterations = 2; 
    double LearningRate = 0.01;
    vector<int> error(input.size() , 0) ;
    double partial_derivative_m , partial_derivative_c;
    int len = input.size();
    double divisor = 1.0/len;

    vector<int> temp(len, 1);
    
    // Iterate for NoOfIterations
    for (int i = 0; i < NoOfIterations; i++)
    {
        cout << "\n *** Iteration " << i  << "\n";
        // iterate for all input
        // get the error vector
       for(int j=0; j < input.size(); j++)
       {
         int pred = m * input[j] + c;
         error[j] = pred - output[j];
         cout << "error[" << j <<"]= " << error[j] << " " ;
       }
      
        // calculate partial_derivate of m 
        //calcualte partial_derivative of c
      cout << "\n 1/len= " << divisor << "\n";
      partial_derivative_m = divisor * sumOfProdOfError(error , input);
      partial_derivative_c = divisor * sumOfProdOfError(error, temp);
      cout << "\n partial_der_m= " << partial_derivative_m << " sumOfProd" << sumOfProdOfError(error,input) ;
      cout << " partial_der_c= " << partial_derivative_c << " sumOfProd" << sumOfProdOfError(error,temp) ;
        // update m 
        //update c
      m = m - LearningRate * partial_derivative_m;
      c = c - LearningRate * partial_derivative_c;
    }
    
    //Printing the results
    cout << "\nFinal m= " << m << "c= " << c << "\n";

}

void SimpleProblems::RandomProblems::TestLinearRegression()
{
    vector<int> input{1,2,3,4,5};
    vector<int> output{1,2,3,4,5};

    double m = 0.1, c=0;

    LinearRegression(input , output, m , c); 
}

bool SimpleProblems::RandomProblems::CheckIfBSTUsingRecursion(treeNode *node)
{
    //M1: using recursion
    //check if the node has children !=2 
    //if true return not A BST
    //else return BST

    if(node == nullptr)
    {
        return false;
    }

    if( node->left && node->right)
    {
        CheckIfBSTUsingRecursion(node->left);
        CheckIfBSTUsingRecursion(node->right);
    }
    else{
        return false;
    }

    //M2: without recursion
    return true;
}

typedef struct treeNode treeNode;

void SimpleProblems::RandomProblems::TestForBST()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);

    cout << "tree is BST or not: 0- false, 1- true " << CheckIfBSTUsingRecursion(root) 
            << "\n";

}

int SumVector(vector<int> &a)
{
    int sum = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
        sum = sum + a[i];
    }

    return sum;   
}

int SimpleProblems::RandomProblems::MaxOf2Values(int a, int b)
{
    return ( a >=b ? a : b);
}

void SimpleProblems::RandomProblems::PrintArr(vector<int> &a)
{
    cout << "Printing Arr \n";
    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        cout << a[i] << " ";
    }
    cout << "\n";
    
}

int SimpleProblems::RandomProblems::MaxSubArraySum(vector<int> &a)
{
    vector<int> prevSum = a;

    if( a.size() <= 0)
    {
        cout << "Empty Arr\n";
        return 0;
    }

    int MaxSum = a[0];
    for (size_t i = 1; i < a.size(); i++)
    {
        /* code */
        prevSum[i] = MaxOf2Values(prevSum[i-1] + a[i] , a[i]);
        MaxSum = MaxOf2Values(MaxSum , prevSum[i]);

    }
    
    PrintArr(prevSum);
    return MaxSum;
}

void SimpleProblems::RandomProblems::TestForMaxSubArraySum()
{
    // vector<int> a = { 1, 2, -30, 4, -5, 12}; 
    vector<int> a = { -2, -3, 4, -1, -2, 1, 5, -3 };
    cout << "MaxSubArraySum = " << MaxSubArraySum(a) << "\n";
}

int SimpleProblems::RandomProblems::LengthofLongestIncreasingSeq(vector<int> &a)
{
    //Pseudo-code 
    // Init LISArr with 1 
    //Max = 1
    // iterate for each element from 1
        // iterate for each elem till i
        // compare a[i] & a[j]
        // if a[i] >= a[j] --> getMax(LIS[j] + 1 , LIS[i])
    //  Max = Max(Max , LIS[i])
    vector<int> LISArr (a.size() , 1);
    
    if(a.size() <= 0)
    {
        return 0;
    }

    int GetMax = a[0];

    for (size_t i = 1; i < a.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            /* code */
            if(a[i] >= a[j])
            {
                LISArr[i] = MaxOf2Values(LISArr[j] + 1 , LISArr[i]);
            }
        }
        PrintArr(LISArr);
        GetMax = MaxOf2Values(GetMax , LISArr[i]);
    }
    
    return GetMax;
}

void SimpleProblems::RandomProblems::TestForLIS()
{
    //
    vector<int> a = { 1, 2, -30, 4, -5, 12}; 

    cout << "LengthofLongestIncreasingSeq " << LengthofLongestIncreasingSeq(a) ;
    cout << "\n";
}

int SimpleProblems::RandomProblems::ValueForPassChar(char passChar){
    //Value(passChar)
        //if int(passChar) lies b/w 65-90
            // return int(passChar) - 65
        //else if int(passChar) lies b/w 97-122
            //return int(passChar) - 97
        //else
            // return 0

    int valForPassChar = int(passChar);
    if(valForPassChar >= 65 && valForPassChar <= 90){
        return valForPassChar - 65;
    }
    else if(valForPassChar >= 97 && valForPassChar <= 122){
        return valForPassChar - 97;
    }
    else{
        return -1;
    }
}



string SimpleProblems::RandomProblems::Encrypt(string str1, string password)
{
    //Pseudo-code
    //Loop for each character of str1
        // check if char lies b/w 65-90 or, 97-122
        // if yes: 
            // if char lies b/w 65-90 or, 97-122
                // encrypted[i] = char(int(char) + Value(passChar))
        //if no encrypted[i] = char
        //i++ , k++ if(k == len(passWord)  k = 0)
    
    int lenOfPass = password.size(); 
    
    if(lenOfPass == 0){
        return str1;
    }

    string trimmedPassword = "";
    //trim password to have letters only
    for (size_t i = 0; i < password.size(); i++)
    {
        if(ValueForPassChar(password[i]) != -1){
            trimmedPassword.push_back(password[i]);
        }
    }
    
    cout << "Trimmed-Password: " << trimmedPassword << "\n";
    int lenOfTrimmedPass = trimmedPassword.size();
    if(lenOfTrimmedPass == 0){
        return str1;
    }

    string encrypted = "";
    int k=0;
    //Loop for each character of str1
        // check if char lies b/w 65-90 or, 97-122
        // if yes: 
            // if char lies b/w 65-90 or, 97-122
                // encrypted[i] = char(int(char) + Value(passChar))
        //if no encrypted[i] = char
        //i++ , k++ if(k == len(passWord)  k = 0)
    for (size_t i = 0; i < str1.size(); i++)
    {
        /* code */
        char txtChar = str1[i];
        int valForTxtChar = int(txtChar);

        char passChar = trimmedPassword[k];
        
        if( (valForTxtChar >= 65 && valForTxtChar <= 90) ||  
            (valForTxtChar >= 97 && valForTxtChar <= 122) )
        {   
            char Encryptedchar = char(valForTxtChar + ValueForPassChar(passChar)) ;
            encrypted.push_back(Encryptedchar);
            // cout << "Encrypted: " << Encryptedchar << "\n";
            k++;
            k = k % lenOfTrimmedPass;
        }
        else{
            encrypted.push_back(txtChar);
        }

    }
    
    return encrypted;
}

void SimpleProblems::RandomProblems::TestForEncrypt()
{
    string str1 = "Hello World!"; //"Hello World!"; //"aaaaaa";
    string password = "12~+Abc123" ; //"abc";

    cout << Encrypt(str1, password) ;
}

void RandomProblems::MainForRandomProblems()
{
    // RandomProblems::TestReverseString();

    // RandomProblems::TestFindMissingNo();
    // RandomProblems::TestBalancedParentheses();

    // RandomProblems::TestMerge2SortedArr();
    // RandomProblems::TestNthFibNo();
    // RandomProblems::TestReturn2Sum();
    // RandomProblems::TestConvolution();
    // RandomProblems::TestLinearRegression();
    // RandomProblems::TestForBST();
    // RandomProblems::TestForMaxSubArraySum();

    // RandomProblems::TestForLIS();
    RandomProblems::TestForEncrypt();
}