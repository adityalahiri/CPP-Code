#include<bits/stdc++.h>

using namespace std;

int main(){

  int n = 0, m = 0;
  cin>>n>>m;

  int visited[n+1] = {0};

  std::vector<int> v[n+1];

  for(int i = 1; i<=m; i++){

    int a = 0, b = 0;
    cin>>a>>b;

    v[a].push_back(b);
    v[b].push_back(a);

  }

  int x = 0;
  cin>>x;

  stack<int> s;
  s.push(x);
  visited[x] = 1;

  while(!s.empty()){

    int curr = s.top();
    s.pop();

    for(int i = 0; i<v[curr].size(); i++){

      if(visited[v[curr][i]] == 0){

          s.push(v[curr][i]);
          visited[v[curr][i]] = 1;

      }
    }

  }

  int ans = 0;

  for(int i = 1; i<=n ; i++)
    if(visited[i]==0)
      ans++;

  cout<<ans<<endl;


}
