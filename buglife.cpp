#include<bits/stdc++.h>
using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  for(int i = 1; i<=num_tests; i++){

    int n = 0, m = 0;
    cin>>n>>m;

    std::vector<int> adj[n+1];

    for(int j = 0; j<m; j++){

      int a = 0, b = 0;
      cin>>a>>b;

      adj[a].push_back(b);
      adj[b].push_back(a);


    }

    int color[n+1] = {0};

    queue<int> q;

    int flag = 0;

    for(int p = 1; p<=n;p++){

    if(color[p] !=0)
      continue;

    q.push(p);
    color[p] = 1;

    while(!q.empty()){

      int curr = q.front();
      q.pop();

      for(int k = 0; k<adj[curr].size(); k++){

        int child = adj[curr][k];

        if(color[child] == color[curr])
          flag = 1;

        else if(color[child] == 0){

          if(color[curr] == 1)
            color[child] = -1;
          else if(color[curr] == -1)
            color[child] = 1;

          q.push(child);

        }


      }

    }
  }

    if(flag)
        cout<<"Scenario #"<<i<<":"<<endl<<"Suspicious bugs found!"<<endl;
      else
        cout<<"Scenario #"<<i<<":"<<endl<<"No suspicious bugs found!"<<endl;


  }

}
