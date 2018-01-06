#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{

  int V;

  std::vector<int> *adj;

  //private by default

  void DFSUtil(int v, bool visited[], int parent[], int dest);
public:
  int cycle_flag = 0, reached = 0;
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
  adj[w].push_back(v);

}

void Graph::DFSUtil(int v, bool *visited,int *parent,int dest){
  //cout<<v+1<<" ";
  visited[v] = true;


  for(int i = 0; i < adj[v].size(); i++){

    parent[adj[v][i]] = v;

    if(dest == adj[v][i]){

      reached = 1;
      break;
      //cout<<"r"<<v+1;
      // 2 is itself a part of a cycle!!!
      // i am fucked if either of src or dest is a part of the cycle 

    }

    if(!visited[adj[v][i]])
      DFSUtil(adj[v][i], visited, parent,dest);
    else{

      if(parent[v] != adj[v][i]){
        cycle_flag = 1;

        //cout<<"yo"<<parent<<" "<<adj[v][i]<<"bo ";

      }

    }

  }

}

void Graph::DFS(int v, int dest){

  bool *visited = new bool[V];
  int *parent = new int[V];

  for (int i = 0; i < V; i++){
        visited[i] = false;
        parent[i] = 0;
  };

  parent[0] = -1;

  DFSUtil(v, visited,parent,dest);

  if(reached && !cycle_flag)
    //cout<<1<<" "<<reached<<" "<<cycle_flag<<endl;
    cout<<1<<endl;
  else
    //cout<<0<<" "<<reached<<" "<<cycle_flag<<endl;
    cout<<0<<endl;

}

int main()
{
    // Create a graph given in the above diagram
    int N, M, Q;
    cin>>N>>M>>Q;

    Graph g(N);

    for(int i = 0; i<M; i++){
      int x,y;
      cin>>x>>y;
      g.addEdge(x-1,y-1);

    }

    for(int i = 0; i<Q; i++){

      g.cycle_flag = 0;
      g.reached = 0;
      int x,y;
      cin>>x>>y;
      g.DFS(x-1,y-1);

    }

    return 0;
}
