#include<bits/stdc++.h>
using namespace std;

void bfs_traversal(std::vector<int> v[], int size, int s, int distance[]){

  distance[s] = 0;
  queue<int> q;

  q.push(s);

  while(!q.empty()){

    int curr = q.front();
    q.pop();

    for(int i = 0; i<v[curr].size(); i++){

      if(distance[v[curr][i]] == -1){

        q.push(v[curr][i]);
        distance[v[curr][i]] = distance[curr] + 1;

      }
    }
  }
}


int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, m = 0;
    cin>>n>>m;

    std::vector<int> v[n+1];

    for(int i = 0; i<m; i++){

      int v1 = 0, v2 = 0;
      cin>>v1>>v2;

      v[v1].push_back(v2);
      v[v2].push_back(v1);

    }

    int s = 0;
    cin>>s;

    int distance[n+1] = {0};

    for(int i = 1; i<=n; i++)
      distance[i] = -1;

    bfs_traversal(v,n+1,s, distance);

    for(int i = 1; i<=n; i++){

      if(i!=s){

        if(distance[i]!=-1)
          cout<<distance[i]*6<<" ";
        else
          cout<<-1<<" ";

    }
  }
  cout<<endl;
}

}
