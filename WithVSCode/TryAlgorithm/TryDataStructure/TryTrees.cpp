
#include <iostream>
#include <queue>
#include <stack>

#include "TryTrees.hpp"

using namespace std;
using namespace TryDataStructure;
using namespace TryDataStructure::TryTrees;

int CountOfNodes = 0;

multi_node *TryDataStructure::TryTrees::NewNodes(int *child_data, int NoOfChildren, int data)
{
    multi_node* NewMultiNode1 = new multi_node();
    NewMultiNode1->data = data;
    for (int i = 0; i < NoOfChildren; i++)
    {
        /* code */
        multi_node* temp = new multi_node();
        temp->data = child_data[i];
        NewMultiNode1->children.push_back(temp);
    }
    
    return NewMultiNode1;
}

void TryTrees::LevelWiseTraversalMultiTree(multi_node* root)
{
    queue<multi_node*> que1;

    if(!root)
        return;

    que1.push(root);

    while(!que1.empty())
    {
        //pop out node
        //push all children on the que
        multi_node* temp = que1.front();
        cout << temp->data << " ";
        que1.pop();

        for(auto child: temp->children)
        {
            que1.push(child);
        }
    }
}

void TryDataStructure::TryTrees::LevelWiseTraversalMultiTreeStack(multi_node *root)
{
    stack<multi_node*> stack1;

    if(root == nullptr)
        return;

    stack1.push(root);

    while(!stack1.empty())
    {
        //pop nodes from the stack
        multi_node* temp = stack1.top();
        cout << temp->data << " -> ";
        stack1.pop();
        //see if there are any children -- if yes, add them to stack
        for (auto children :temp->children )
        {
            stack1.push(children);
        }
        
    }
}

void TryTrees::TestForLevelWiseTraversalMultiTree()
{
    int arrChild[] = {2,3};
    int dataForRoot = 1;
    int arrChildForNode2[] = {5};
    int arrChildForNode4[] = {6,7,8,9};

    multi_node* Node4 = NewNodes(arrChildForNode4, 4, 4);
    multi_node* Node2 = NewNodes(arrChildForNode2, 1, 2);
    multi_node* Node3 = new multi_node();
    Node3->data = 3;

    multi_node* root = new multi_node();
    root->data = 1;
    root->children.push_back(Node2);
    root->children.push_back(Node3);
    root->children.push_back(Node4);

    TryTrees::LevelWiseTraversalMultiTree(root);

    cout << "\nPrinting using stack\n";
    TryTrees::LevelWiseTraversalMultiTreeStack(root);
}

TryTrees::node *TryTrees::NewNode(int data)
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

void TryDataStructure::TryTrees::insertNewNodeInFullBT(node* root, int data)
{
    //
    node* newNode = TryTrees::NewNode(data);
    if (newNode == nullptr)
    {
        cout << "newNode is null";
        return;
    }

    if(root == nullptr){
        cout << "root is null";
        root = newNode;
        return;
    }

    // node* temp = root;
    queue<node*> que1 ;
    que1.push(root);
    bool flag = 0;

    while(!que1.empty()){
        node* GetNode = que1.front();
        que1.pop();

        if(GetNode->left == nullptr){
            GetNode->left = newNode;
            flag = 1;
            break;
        }
        else if(GetNode->right == nullptr){
            GetNode->right = newNode; flag =1;
            break;
        }
        else{
            que1.push(GetNode->left);
            que1.push(GetNode->right);
        }

    }

    // que1.clear();
    // delete que1;
    
    if (flag == 1)
    {
       cout << "Successfully added node as Full BT\n";
    }
    else{
        cout << "Something went wrong while adding node\n";
    }
    
}

void TryTrees::mainForTryTrees()
{
    node* root = TryTrees::NewNode(4);
    root->left = TryTrees::NewNode(3);
    root->right = TryTrees::NewNode(2);
    root->left->left = TryTrees::NewNode(1);
    // root->right->left = TryTrees::NewNode(5);
    root->right->right = TryTrees::NewNode(6);
    // root->right->left->left = TryTrees::NewNode(7);
    //      4
    //   3     2
    // 1     5    6
    std::cout << "size of root is " << TryTrees::size(root) << std::endl;
    std::cout << "size of root-Self2 is " << TryTrees::sizeSelf(root) << std::endl;
    insertNewNodeInFullBT(root, 7);
    insertNewNodeInFullBT(root, 8);

    cout << "Printing NodesInorder\n" ;
    TryTrees::PrintAllNodesInorder(root); 

    cout << "Printing NodesPreorder\n" ;
    TryTrees::PrintAllNodesPreOrder(root); 

    cout << "Printing Nodes Level Wise\n" ;
    TryTrees::LevelWiseTraversal(root);

    cout << "Height of Tree is " << TryTrees::HeightOfTree(root) << endl;

    TryTrees::TestForLevelWiseTraversalMultiTree();
    cout << "\n";
    
}
