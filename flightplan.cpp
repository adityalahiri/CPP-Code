#include<bits/stdc++.h>

using namespace std;

int main(){

    int n = 0, m = 0, c = 0, t = 0;
    cin>>n>>m>>c>>t;

    std::vector<int> adj[n+1];

    int visited[n+1] = {0};
    int parent[n+1] = {0};

    for(int i = 0; i<m; i++){

      int u = 0;
      int v = 0;

      cin>>u>>v;

      adj[u].push_back(v);
      adj[v].push_back(u);

    }

    int src = 0, dest = 0;
    cin>>src>>dest;

    queue<int> q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty()){

      int curr = q.front();
      q.pop();

      sort(adj[curr].begin(), adj[curr].end());

      for(int i = 0; i<adj[curr].size(); i++){

        int ele = adj[curr][i];

        if(!visited[ele]){

          visited[ele] = 1;
          q.push(ele);
          parent[ele] = curr;

        }

      }

    }

    std::vector<int> path;

    //go in parent array from dest to src while not reached src

    int curr = dest;
    path.push_back(dest);

    while(curr!=src){

      curr = parent[curr];
      path.push_back(curr);

    }

    std::cout << path.size() << '\n';

    for(int j = path.size()-1; j>=0; j--)
      cout<<path[j]<<" ";

    cout<<endl;

}
