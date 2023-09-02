

#include <iostream>
// #include 
#include "TryLL.hpp"

using namespace TryDataStructure;
using namespace TryDataStructure::TryLL;

using namespace std;

typedef class SingleLLNode SingleLLNode;
namespace{


}

void TryDataStructure::TryLL::SingleLLNode::ModifyPrivate()
{
    cout << "Private variable is " << x << endl;
    x = 10;
    cout << "Private variable is " << x << endl; 
}

SingleLLNode* TryDataStructure::TryLL::insertElementAtPosSingleLL(SingleLLNode* startNode,int newData, int pos){
    
    //check if pos = 0 , < 0, >0 , >len
    SingleLLNode* tempNode = startNode;
    
    //if pos < 0 : not supported
    if(pos < 0) {
         cout << "Negative Pos not supported\n";
         return tempNode;
    }

    //Form new Node
    SingleLLNode* NewNode = new SingleLLNode;
    NewNode->data = newData;
    NewNode->next = nullptr;

    //if pos = 0, just assign the first ptr
    if(pos == 0){
        NewNode->next = tempNode;
        tempNode = NewNode;
        return tempNode;
    }
    
    //if pos > 0 : insert at the desired place
    int countOfPos = 1;
    bool flag = 0;
    //next node of tempNode is desired position 
    while (tempNode->next != nullptr)
    {
        if(countOfPos == pos){
            //
            //assign next of NewNode to older list next
            //assign next of tempNode to NewNode 
            NewNode->next = tempNode->next;
            tempNode->next = NewNode;
            flag = 1;
            break;     
        }
        countOfPos++;
        tempNode = tempNode->next;
    }

    if(flag == 1)
    {
        //element already inserted:
        return startNode;
    }

    //Even if the last is null ie, insertion is possible at the end
    if(tempNode->next == nullptr && countOfPos == pos && flag == 0){
        NewNode->next = tempNode->next;
        tempNode->next = NewNode;
        return startNode;
    }
    
    //else: pos asked is more than length -- warning 
    cout << "pos is " << pos << " length is " << countOfPos + 1 << "\n";
    cout << "Insertion beyond size+1 attempted -- not possible";
    return startNode;
}

SingleLLNode *TryDataStructure::TryLL::deleteElementAtPosSingleLL(SingleLLNode *startNode, unsigned int pos)
{
    //check if the startNode is non-empty 
    if (startNode == nullptr)
    {
        cout << "Empty list\n";
        return startNode;
    }
    
    //check if pos < 0 --
    //delete from beginning -- pos == 0
    SingleLLNode* tempNode = startNode;
    if (pos == 0)
    {
        tempNode = TryLL::deleteFromFrontSingleLL(startNode);
        return tempNode;
    }
    
    //delete from any other position > 0 
    unsigned int currentPos = 1;
    bool flag = 0;
    while( tempNode->next != nullptr){
        if(currentPos == pos){
            SingleLLNode* tempNode2 = tempNode->next->next;
            delete tempNode->next;
            tempNode->next = tempNode2;
            flag =1;
            break;
        }
        currentPos = currentPos + 1;
        tempNode = tempNode->next;
    }

    //to delte last element
    // if(tempNode->next == nullptr && currentPos == pos && flag == 0){
    //     delete tem
    // }
    // delete from pos > length -- warning message
    if (flag == 1)
    {
        return startNode;
    }
    else{
        cout << "PosTo delte is " << pos << " greater than length " << currentPos;
        return startNode;
    }
    
    return startNode;
}

SingleLLNode *TryDataStructure::TryLL::deleteFromFrontSingleLL(SingleLLNode *startNode)
{
    SingleLLNode* tempNode = startNode->next;
    // tempNode = tempNode->next;
    delete startNode;
    return tempNode;
}

void TryDataStructure::TryLL::PrintSingleLL(SingleLLNode* startNode){
    //print all the nodes data
    SingleLLNode* tempNode = startNode;
    cout << "Printing Single LL \n";
    while(tempNode != nullptr){
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }

    cout << "\n";
}

void TryDataStructure::TryLL::TestForSingleLL(){
    //create new Single LL
    SingleLLNode* Node0 = new SingleLLNode(0);
    Node0->ModifyPrivate();
    
    //Add few nodes to linked list
    TryLL::insertElementAtPosSingleLL(Node0, 1, 1);
    TryLL::insertElementAtPosSingleLL(Node0, 2, 2);

    //Negative Test Cases:
    TryLL::insertElementAtPosSingleLL(Node0, 3, 3);
    TryLL::insertElementAtPosSingleLL(Node0, 8, 8);
    Node0 = TryLL::insertElementAtPosSingleLL(Node0, 100, 0);
    Node0 = TryLL::insertElementAtPosSingleLL(Node0, 102, 2);

    //print
    TryLL::PrintSingleLL(Node0);

    //delete few nodes 
    Node0 = TryLL::deleteFromFrontSingleLL(Node0);
    PrintSingleLL(Node0);
    Node0 = TryLL::deleteElementAtPosSingleLL(Node0, 1);
    PrintSingleLL(Node0);
    Node0 = TryLL::deleteElementAtPosSingleLL(Node0, 3);
    PrintSingleLL(Node0);
    Node0 = TryLL::deleteElementAtPosSingleLL(Node0, 3);
    PrintSingleLL(Node0);

}


void TryDataStructure::TryLL::MainForLL(){
    TryLL::TestForSingleLL();

}


