


#include <iostream>
// #include 
#include "TryGraph.hpp"

using namespace TryDataStructure;
using namespace TryDataStructure::TryGraph;

namespace{
     int Gcount = 0;

    void PrintVector(vector<int>& a);



    void PrintVector(vector<int> &a)
    {
        // cout << "\nPrinting vector \n";

        for (size_t i = 0; i < a.size(); i++)
        {
           cout << a[i] << " ";
        }

        if(a.size() == 0)
            cout << "{}" << endl;

        cout << "\n";
    }
}


Graph::Graph(int N){
  this->NoOfVertices = N;
  adj.resize(N);
}

void Graph::addEdge(int m, int n){
  adj[m].push_back(n);
  adj[n].push_back(m);
  adjlist[m].push_back(n);
  adjlist[n].push_back(m);
}

void TryDataStructure::TryGraph::Graph::addDirectedEdge(int m, int n)
{
  adj[m].push_back(n);
  adjlist[m].push_back(n);
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

void TryDataStructure::TryGraph::Graph::BFS2(int startNode)
{
  //vector for visited node
  //stack for node
    // push startNode on stack
  //iterate till stack is not empty
    // get from stack 
    // print the value
    //iterate for all the childre
    //if children is not visited 
      //add to the stack
    
  vector<bool> visited (NoOfVertices , false);
  stack<int> stack1;

  stack1.push(startNode);
  cout << "Printing Graph Nodes \n" ;
  while(!stack1.empty())
  {
    int getStackElem = stack1.top();
    cout << getStackElem << " ";
    visited[getStackElem] = true;
    stack1.pop();
    for (auto &&i : adj[getStackElem])
    {
        if(visited[i] == false)
        {
          stack1.push(i);
        }
    }
    

  }

} 

vector<int> TryDataStructure::TryGraph::BFS3(int startNode, Graph &G)
{
    //get adjacency list
    vector<vector<int>> adjlist1 = G.adjlist;

    //visited 
    vector<bool> visited(G.getNoOfNodes() , false);

    //que
    queue<int> que1;
    que1.push(startNode);
    //make sure while pushing a node to queue -- we mark it as visited
    visited[startNode] = true;

    //vector for ans 
    vector<int> vectForIteratedNodes;

    while(!que1.empty()){
      int getNode = que1.front();
      que1.pop(); 
      
      vectForIteratedNodes.push_back(getNode);

      for(auto child: adjlist1[getNode]){
        if(!visited[child]){
          visited[child] = true;
          que1.push(child);
        }
      }
    }

    return vectForIteratedNodes;
}

void TryDataStructure::TryGraph::TestForGraphBFS()
{
  //        1 ---- 3
  //     /  |      |
  //   0    |      |
  //     \  |      |
  //        2  --- 4 

  Graph G(5);
  G.adjlist.resize(5);

  G.addEdge(0, 1);
  G.addEdge(0, 2);
  G.addEdge(1, 2);
  G.addEdge(1, 3);
  G.addEdge(2, 4);
  G.addEdge(3, 4);

  // G.BFS(0);
  G.BFS2(0);
  cout << endl;
  vector<int> graphNodesList =  BFS3(0, G);
  PrintVector(graphNodesList);

}

void TryDataStructure::TryGraph::dfs(int i, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stack1)
{
   visited[i] = true;
   stack1.push(i);

   for(auto neigh:adj[i]){
      if(!visited[neigh]) {
        dfs(neigh , adj, visited, stack1 );
      }
   }

  //  stack1.push(i);
}

vector<int> TryDataStructure::TryGraph::topologicalSort(vector<vector<int>> &adj)
{
    int N = adj.size();
    vector<bool> visited(N ,false);
    stack<int> stack1;
    vector<int> anslist;  

    //iterate for all the nodes
    //if not visited then call dfs
    // dfs should give a stack of visited nodes
    for (size_t i = 0; i < N; i++)
    {
      if(!visited[i]){
        dfs(i, adj, visited, stack1 );
      }
    }

    //iterate through stack and store in vector
    while(!stack1.empty()){
      anslist.push_back(stack1.top());
      stack1.pop();
    }

    return anslist;
}



void TryDataStructure::TryGraph::TestForTopogicalSort()
{
  //        1 ----->3
  //      /\ |      |
  //   0     |      |
  //     \/ \/      \/
  //         2  --->4 

  Graph G(5);
  G.adjlist.resize(5);

  G.addDirectedEdge(0, 1);
  G.addDirectedEdge(0, 2);
  G.addDirectedEdge(1, 2);
  G.addDirectedEdge(1, 3);
  G.addDirectedEdge(2, 4);
  G.addDirectedEdge(3, 4);


  vector<int> anslist = topologicalSort(G.adjlist);
  PrintVector(anslist); //0 1 3 2 4
}

void TryDataStructure::TryGraph::MainForGraph()
{
    // TryGraph::TestForGraphBFS();
    TryGraph::TestForTopogicalSort();
}
