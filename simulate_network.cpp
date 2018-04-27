#include<bits/stdc++.h>

using namespace std;

int root(int x, int id[]){

  while(x != id[x])
    x = id[x];

  return x;

}

void union_join(int x, int y, int id[], int size[]){
    int p = root(x,id);
    int q = root(y,id);
    if(size[p]>size[q])
    {
        id[q] = id[p];
        size[p]+=size[q];
    }
    else
    {
        id[p] = id[q];
        size[q]+=size[p];
    }
}

void kruskal(pair< int, pair<int,int> > data[], int m,int id[],int size[],vector<int> &cables ){

      for(int i = 0; i<m; i++){

          int u = data[i].second.first;
          int v = data[i].second.second;
          int w = data[i].first;



          if(root(u, id) != root(v,id)){

          union_join(u,v,id,size);
          cables.push_back(w);

      }
    }

}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0, m = 0;
  cin>>n>>m;

  int id[n+1];
  int size[n+1];

  // inititalising id for kruskal

  for(int i = 1; i<=n; i++){
    id[i] = i;
    size[i] = 1;
  }

  pair< int, pair<int,int> > data[m];

  for(int i = 0; i<m; i++){

      int a = 0, b = 0, w = 0;
      cin>>a>>b>>w;

      data[i] = make_pair(w, make_pair(a,b));

  }

  int c = 0;
  cin>>c;

  std::vector<int> cables;

  for(int i = 0; i<c; i++){

    int t = 0;
    cin>>t;

    cables.push_back(t);

  }

  sort(data, data+m);

  kruskal(data,m,id,size,cables);

  sort(cables.begin(), cables.end());

  long long cost = 0;
  for(int i = 0; i<n-1; i++)
    cost = cost + cables[i];

  cout<<cost<<endl;

}
