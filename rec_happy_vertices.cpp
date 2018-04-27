#include<bits/stdc++.h>

using namespace std;

int ans = 0;

void dfs(int s, int visited[], std::vector<int> adj[]){

  visited[s] = 1;

  for(int i = 0; i<adj[s].size(); i++){

    if(visited[adj[s][i]]==0){

      if(adj[adj[s][i]].size() > adj[s].size())
        ans++;

      dfs(adj[s][i],visited,adj);

    }

  }

}

void dfs_parent(int visited[], std::vector<int> adj[], int n){

  for(int i = 1; i<=n; i++){

    if(visited[i] == 0)
      dfs(i,visited,adj);

  }

}

int main(){

  int n = 0, m = 0;
  cin>>n>>m;

  std::vector<int> adj[n+1];

  for(int i = 1; i<=m; i++){

    int a = 0, b = 0;
    cin>>a>>b;

    adj[a].push_back(b);
    adj[b].push_back(a);

  }

  int visited[n+1] ={0};

  dfs_parent(visited,adj,n);

  cout<<ans<<endl;

}
