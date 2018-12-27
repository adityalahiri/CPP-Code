//kruskal pair of wieght and edge where edge itself is a pair of the vertices involved
//id array implements disjoint set. id[i] stores the class that i belongs to
//id[x] = x for the one single representative element of the class.
// root fn finds the representative element for the class in which the parameter element belongs
// still confused abut root fn. nahh. Two lines can be compressed into one dw.


#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll root(int x, ll id[]){

  while(x != id[x]){

    x = id[id[x]];

  }

  return x;

}

void union_join(int x, int y, ll id[]){

  ll p = root(x,id);
  ll q = root(y,id);

  id[p] = id[q];

}

int kruskal(pair< ll, pair<int, int> > data[], ll id[], int m){

  ll cost = 0;

  for(int i = 0; i<m; i++){

    int u = data[i].second.first;
    int v = data[i].second.second;
    ll w = data[i].first;

    if(root(u,id) != root(v,id)){

      union_join(u,v,id);
      cost = cost + w;

    }

  }

  return cost;

}

int main(){

  int t = 0;
  cin>>t;

  while(t--){

  int n = 0, m = 0;
  cin>>n>>m;

  pair< ll, pair<int, int> > data[m];

  for(int i = 0; i < m; i++){

    int a = 0, b = 0, w = 0;
    cin>>a>>b;

    data[i] = make_pair(1, make_pair(a,b));

  }

  ll id[n+1];

  for(ll i = 1; i<=n; i++)
      id[i] = i;

  //sort(data,data+m);

  cout<<kruskal(data,id,m)<<endl;

}

}
