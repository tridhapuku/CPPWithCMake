#ifndef TRY_DATASTRUCT_TREES_H
#define TRY_DATASTRUCT_TREES_H

namespace TryDataStructure{
    namespace TryTrees{

        class node{
            public:
                int data;
                node* left;
                node* right;
        };

        class multi_node{
            public:
                int data;
                std::vector<multi_node*> children;
        };

        multi_node* NewNodes(int *child_data, int NoOfChildren, int data);

        void LevelWiseTraversalMultiTree(multi_node* root);

        void LevelWiseTraversalMultiTreeStack(multi_node* root);
        void TestForLevelWiseTraversalMultiTree();

        node* NewNode(int data);
        int size(node *node1);
        int sizeSelf(node *node1);
        void PrintAllNodesInorder(node* node1);
        void PrintAllNodesPreOrder(node* node1);

        void LevelWiseTraversal(node* node1);

        
        int HeightOfTree(node* node1);

        void insertNewNodeInFullBT(node* root,int data);
        void mainForTryTrees();

    }
}


#endif