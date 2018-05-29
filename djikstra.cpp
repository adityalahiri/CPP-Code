#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int n = 0, m = 0;
  cin>>n>>m;

  vector< pair<int,int> > data[n+1]; // 1 indexing. Will store edge and weights in adj list format

  int distance[n+1]; // keeps distance from source vertex
  int visited[n+1]; // 0 signifies not out of priority queue yet(ie doesnt not have min dis for it yet), 1 opposite.

  // initialising

  for(int i = 1; i<=n; i++){

    distance[i] = INT_MAX; // setting all initial min dist as infinity
    visited[i] = 0;  // setting all nodes unvisited.

  }

  // taking graph edge inputs

  for(int i = 0; i<m; i++){

    int u = 0, v = 0, w = 0;
    cin>>u>>v>>w;

    data[u].push_back(make_pair(v,w));

  }

  // multiset is the prioirty queue. Once you have min dist for some you pop it out of here and mark it
  //visited. Visited is the cloud that has all processed guys.
  // think like intially everyone is in mutliset with distance infi except src with d = 0

  multiset< pair <int,int> > dj;
  // multiset is value,key pair. Sorted auto by value. Unique key.
  // If key repeats then previous one over written.
  // value here is curr min dist of a vertex from src, key is the vertex

  // beginning from src
  distance[1] = 0;
  dj.insert(make_pair(0,1));

  while(!dj.empty()){

      pair<int,int> curr = *dj.begin();
      dj.erase(dj.begin()); // popping out the vertex with min distance

      int dist = curr.first;
      int vertex = curr.second;

      if(visited[vertex])
        continue;

      visited[vertex] = 1;

      for(int i = 0; i<data[vertex].size(); i++){

        pair<int, int> p = data[vertex][i];
        int wt = p.second;
        int curr_vertex = p.first;

        if(distance[curr_vertex] > wt + distance[vertex]){ // relaxation.

          int new_dist = wt + distance[vertex];
          distance[curr_vertex] = new_dist;//update new relaxed smaller dist in parent dist array
          // need to do this to get current min distances in O(1)
          dj.insert(make_pair(new_dist,curr_vertex));

        }

      }


  }

  for(int k = 2; k<=n; k++)
    cout<<distance[k]<<" ";
  cout<<endl;


}
