#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, m = 0;
    cin>>n>>m;

    std::vector<int> adj[n+1];

    for(int i = 0; i<m; i++){

      int a = 0, b = 0;
      cin>>a>>b;

      adj[a].push_back(b);
      adj[b].push_back(a);

    }

    int distance[n+1] = {0};
    int visited[n+1] = {0};

    queue<int> q;
    q.push(1);

    distance[1] = 0;
    visited[1] = 0;

    while(!q.empty()){

      int curr = q.front();
      q.pop();

      for(int i = 0; i<adj[curr].size(); i++){

        int child = adj[curr][i];

        if(visited[child] == 0){

          visited[child] = 1;
          distance[child] = distance[curr] + 1;
          q.push(child);

        }

      }

    }

    cout<<distance[n]<<endl;

  }

}
