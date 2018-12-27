#include<bits/stdc++.h>

using namespace std;

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

  int ans = 0;

  int visited[n+1] ={0};

  stack<int> s;
  s.push(1);
  visited[1] = 1;

  while(!s.empty()){

    int curr = s.top();
    s.pop();

    for(int i = 0; i < adj[curr].size(); i++){

      int child = adj[curr][i];

      if(visited[child] == 0){

        visited[child] = 1;
        if(adj[child].size() > adj[curr].size())
          ans++;
        s.push(child);

      }

    }

  }

  cout<<ans<<endl;

}
