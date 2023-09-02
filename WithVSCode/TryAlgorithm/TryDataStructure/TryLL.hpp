#ifndef TRY_DATASTRUCT_LL_H
#define TRY_DATASTRUCT_LL_H


namespace TryDataStructure{
    namespace TryLL{
            //for Single LL
    class SingleLLNode{
        private:
            int x =5;

        public:
            int data;
            SingleLLNode* next = nullptr;
            SingleLLNode(){};
            SingleLLNode(int data1): data(data1) {}
            void ModifyPrivate();
    };
        
        //Single LL Based Operations
        void PrintSingleLL(SingleLLNode* startNode);
        SingleLLNode* insertElementAtPosSingleLL(SingleLLNode* startNode,int newData, int pos);
        SingleLLNode* deleteElementAtPosSingleLL(SingleLLNode* startNode,unsigned int pos);

        //Delete Helper functions
        SingleLLNode* deleteFromFrontSingleLL(SingleLLNode* startNode);
        // SingleLLNode* del
        //Main User Interface Functions
        
        //Problem
        void TestForSingleLL();
        void MainForLL();
   
    }
}








#endif