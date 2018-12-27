#include<bits/stdc++.h>

using namespace std;

int dfs_level(int root, int x, int num_nodes, std::vector<int> adj[]){

    int level[num_nodes + 1] = {0};
    int visited[num_nodes + 1] = {0};

    int ans = 0;

    queue<int> q;
    q.push(root);
    visited[root] = 1;
    level[root] = 0;

    while(!q.empty()){

      int curr = q.front();
      //cout<<curr<<" yolo "<<endl;
      q.pop();

      for(int i = 0; i<adj[curr].size(); i++){

        if(visited[adj[curr][i]] == 0){

          int t = adj[curr][i];
          visited[t] = 1;
          level[t] = level[curr] + 1;
          q.push(t);

          if(level[t] == x)
            ans++;

        }

      }

    }

    return ans;

}

int main(){

  int num_nodes = 0, num_edges = 0;
  cin>>num_nodes>>num_edges;

  std::vector<int> adj[num_nodes+1];

  for(int i = 1; i <= num_edges; i++){

    int a = 0, b = 0;
    cin>>a>>b;

    adj[a].push_back(b);
    adj[b].push_back(a);

  }

  int m = 0;
  cin>>m;

  while(m--){

    int s = 0, x = 0;
    cin>>s>>x;

    cout<<dfs_level(s,x,num_nodes,adj)<<endl;

  }

}
