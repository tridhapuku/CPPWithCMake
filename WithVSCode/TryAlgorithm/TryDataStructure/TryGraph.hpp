

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
  int NoOfVertices;
  vector<list<int>> adj;

  public:
    Graph(int N);

    void addEdge(int m, int n);

    void BFS(int startNode);

    void BFS2(int startNode);

};
        
        
        void TestForGraphBFS();
        
        void MainForGraph();
    }
}





#endif