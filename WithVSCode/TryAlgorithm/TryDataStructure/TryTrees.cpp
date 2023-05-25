
#include <iostream>
#include <queue>

#include "TryTrees.hpp"

using namespace std;
using namespace TryDataStructure;

int CountOfNodes = 0;

TryTrees::node* TryTrees::NewNode(int data)
{
    node* node1 = new node();
    node1->data = data;
    node1->left = nullptr;
    node1->right = nullptr;
    return node1;
}

int TryTrees::size(node *node1) {
    if(node1 == NULL)
        return 0;
    else{
        return 1 + size(node1->left) + size(node1->right);
    }
    
}

int TryTrees::sizeSelf(node *node1) {
    if(node1 == NULL)
        return 0;
    else{
        int temp = 1;
        // CountOfNodes++;

        if(node1->left != NULL){
            // CountOfNodes = CountOfNodes + TryTrees::sizeSelf(node1->left);
            temp = temp + TryTrees::sizeSelf(node1->left);
        }
            
        
        if(node1->right != NULL){
            // CountOfNodes = CountOfNodes + TryTrees::sizeSelf(node1->right);
            temp = temp + TryTrees::sizeSelf(node1->right);
        }
            

        return temp;
    }
    
}

void TryTrees::PrintAllNodesInorder(node* node1){
    if(node1!= NULL)
        cout << node1->data << " ->";

    if(node1->left != NULL)
        TryTrees::PrintAllNodesInorder(node1->left);

    if(node1->right != NULL)
        TryTrees::PrintAllNodesInorder(node1->right);

}

void TryTrees::PrintAllNodesPreOrder(node* node1){
    if(node1== NULL){
        return;
        // cout << node1->data << " ->";
    }
        

    if(node1->left != NULL){
        // cout << node1->data << " ->";
        TryTrees::PrintAllNodesPreOrder(node1->left);
    }

    cout << node1->data << " ->";

    if(node1->right != NULL){
        TryTrees::PrintAllNodesPreOrder(node1->right);
    }
}

void TryTrees::LevelWiseTraversal(node* node1){
    queue<node*> que1;

    if(node1 != NULL)
        que1.push(node1);
    else{
        cout << "Tree is empty\n";
        return; 
    }

    while(!que1.empty())
    {
        node *getNode = que1.front();
        cout << getNode->data << " -> " ;
        que1.pop();

        if(getNode->left != NULL)
        {
            que1.push(getNode->left);
        }
        
        if(getNode->right != NULL)
            que1.push(getNode->right);
    }

    cout << "\n";
}

int TryTrees::HeightOfTree(node* node1){
    if(node1 == NULL)
        return 0;
    else{
        return 1 + std::max(TryTrees::HeightOfTree(node1->left) , 
                    TryTrees::HeightOfTree(node1->right));
    }
    
}


void TryTrees::mainForTryTrees(){
    node* root = TryTrees::NewNode(4);
    root->left = TryTrees::NewNode(3);
    root->right = TryTrees::NewNode(2);
    root->left->left = TryTrees::NewNode(1);
    root->right->left = TryTrees::NewNode(5);
    root->right->right = TryTrees::NewNode(6);
    // root->right->left->left = TryTrees::NewNode(7);

    std::cout << "size of root is " << TryTrees::size(root) << std::endl;
    std::cout << "size of root-Self2 is " << TryTrees::sizeSelf(root) << std::endl;

    cout << "Printing NodesInorder\n" ;
    TryTrees::PrintAllNodesInorder(root); 

    cout << "Printing NodesPreorder\n" ;
    TryTrees::PrintAllNodesPreOrder(root); 

    cout << "Printing Nodes Level Wise\n" ;
    TryTrees::LevelWiseTraversal(root);

    cout << "Height of Tree is " << TryTrees::HeightOfTree(root) << endl;


}

