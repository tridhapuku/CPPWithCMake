

#ifndef TRY_DATASTRUCT_GRAPH_H
#define TRY_DATASTRUCT_GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

namespace TryDataStructure{
    namespace TryGraph{
        
class Graph{
    private:
        int NoOfVertices;
        vector<list<int>> adj;
        

  public:
    Graph(int N);
    vector<vector<int>> adjlist;
    
    int getNoOfNodes(){ return NoOfVertices; }
    void addEdge(int m, int n);
    void addDirectedEdge(int m, int n);

    void BFS(int startNode);

    void BFS2(int startNode);

};

        //striver
        vector<int> BFS3(int startNode, Graph &G);    
        void TestForGraphBFS();

        //striver - G6- DFS using recursion
        
        //striver - G7 - No of Provinces : https://takeuforward.org/data-structure/number-of-provinces/
        int NoOfProvinces(int start, Graph &G);

        //
        vector<int> topologicalSort(vector<vector<int>>& adj);
        void dfs(int i, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &stack1 );
        void TestForTopogicalSort();

        void MainForGraph();
    }
}





#endif