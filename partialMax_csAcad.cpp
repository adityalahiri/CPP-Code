#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{

  int V;
  std::vector<int> *adj;
  int cycle_flag = 0;
  int reached = 0;

  //private by default

  void DFSUtil(int v, bool visited[], int parent, int dest);
public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFS(int v, int dest);

};

Graph::Graph(int V){

  this->V = V;
  adj = new vector<int>[V];

}

void Graph::addEdge(int v, int w){

  adj[v].push_back(w);

}

void Graph::DFSUtil(int v, bool *visited,int parent, int dest){

  visited[v] = true;
  cout<<v<<endl;
  parent = v;

  for(int i = 0; i < adj[v].size(); i++){

    if(adj[v][i] == dest){
      reached = 1;
      break;
    }

    if(!visited[adj[v][i]])
      DFSUtil(adj[v][i], visited, parent,dest);
    else{

      if(parent != adj[v][i]){
        cycle_flag = 1;
        break;
      }

    }

  }

}

void Graph::DFS(int v, int dest){

  bool *visited = new bool[V];

  for (int i = 0; i < V; i++)
        visited[i] = false;

  DFSUtil(v, visited, -1, dest);

  if(reached && !cycle_flag)
    cout<<1;
  else
    cout<<0;

}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
  //  g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2,3);

    return 0;
}
