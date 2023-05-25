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

        node* NewNode(int data);
        int size(node *node1);
        int sizeSelf(node *node1);
        void PrintAllNodesInorder(node* node1);
        void PrintAllNodesPreOrder(node* node1);

        void LevelWiseTraversal(node* node1);
        int HeightOfTree(node* node1);

        void mainForTryTrees();

    }
}


#endif