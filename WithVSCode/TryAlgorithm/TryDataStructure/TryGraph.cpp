


#include <iostream>
// #include 
#include "TryGraph.hpp"

using namespace TryDataStructure;
using namespace TryDataStructure::TryGraph;

Graph::Graph(int N){
  this->NoOfVertices = N;
  adj.resize(N);
}

void Graph::addEdge(int m, int n){
  adj[m].push_back(n);
}

void Graph::BFS(int startNode){
  //init visited 
  //push the first node on que
  //pop till the que is empty
  //mark the node as visited 
  //iterate through the list of all neighbours and if not visited 
  //push on the que
  vector<bool> visited(NoOfVertices, false);

  queue<int> que1;

  que1.push(startNode);

  while (!que1.empty()) {
      int getNode = que1.front();
      que1.pop();   
      cout << getNode << " -> " ;
      for(auto neighbour: adj[getNode])
      {
        if(visited[neighbour] == false)
        {
          visited[neighbour] = true;
          que1.push(neighbour);
        }
          
      }
  }
}

void TryDataStructure::TryGraph::TestForGraphBFS()
{
  //        1 ---- 3
  //     /  |      |
  //   0    |      |
  //     \  |      |
  //        2  --- 4 

  Graph G(5);

  G.addEdge(0, 1);
  G.addEdge(0, 2);
  G.addEdge(1, 2);
  G.addEdge(1, 3);
  G.addEdge(2, 4);
  G.addEdge(3, 4);

  G.BFS(0);
}

void TryDataStructure::TryGraph::MainForGraph()
{
    TryGraph::TestForGraphBFS();
}
