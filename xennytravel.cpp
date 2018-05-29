#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

  int n = 0;
  cin>>n;

  std::vector< pair<int,int> > g1[n+1];
  std::vector< pair<int,int> > g2[n+1];
  std::vector< pair<int,int> > g3[n+1];
  std::vector< pair<int,int> > g4[n+1];

  for(int i = 1; i<=n; i++)
  {

    for(int j = 1; j<=n; j++){

      int w = 0;
      cin>>w;

      g1[i].push_back(make_pair(j,w));
      g3[j].push_back(make_pair(i,w));

    }

  }

  for(int i = 1; i<=n; i++)
  {

    for(int j = 1; j<=n; j++){

      int w = 0;
      cin>>w;

      g2[j].push_back(make_pair(i,w));
      g4[i].push_back(make_pair(j,w));

    }

  }



  ll dist1[n+1];
  int vis1[n+1];

  ll dist2[n+1];
  int vis2[n+1];

  ll dist3[n+1];
  int vis3[n+1];

  ll dist4[n+1];
  int vis4[n+1];

  for(int i = 1; i<=n; i++){

    dist1[i] = INT_MAX;
    dist2[i] = INT_MAX;
    dist3[i] = INT_MAX;
    dist4[i] = INT_MAX;

    vis1[i] = 0;
    vis2[i] = 0;
    vis3[i] = 0;
    vis4[i] = 0;

  }

  int u = 0, v = 0;
  cin>>u>>v;

  multiset< pair<int,int> > s;

  //1st djikstra Run

  dist1[u] = 0;
  s.insert(make_pair(0,u));

  while(!s.empty()){

    pair<int,int> curr = *s.begin();
    s.erase(s.begin());

    int curr_dist = curr.first;
    int curr_vertex = curr.second;

    if(vis1[curr_vertex])
      continue;

    vis1[curr_vertex] = 1;

    for(int k = 0; k<g1[curr_vertex].size(); k++){

      pair<int, int> p = g1[curr_vertex][k];
      int v = p.first;
      int w = p.second;

      if(dist1[v] > dist1[curr_vertex] + w){

        dist1[v] = dist1[curr_vertex] + w;
        s.insert(make_pair(dist1[v],v));

      }

    }

  }



  //2nd Run

  multiset< pair<int,int> > s2;

  //1st djikstra Run

  dist2[v] = 0;
  s2.insert(make_pair(0,v));

  while(!s2.empty()){

    pair<int,int> curr = *s2.begin();
    s2.erase(s2.begin());

    int curr_dist = curr.first;
    int curr_vertex = curr.second;

    if(vis2[curr_vertex])
      continue;

    vis2[curr_vertex] = 1;

    for(int k = 0; k<g2[curr_vertex].size(); k++){

      pair<int, int> p = g2[curr_vertex][k];
      int v = p.first;
      int w = p.second;

      if(dist2[v] > dist2[curr_vertex] + w){

        dist2[v] = dist2[curr_vertex] + w;
        s2.insert(make_pair(dist2[v],v));

      }

    }

  }

  dist1[v] = INT_MAX;
  dist2[u] = INT_MAX;

  int dist[n+1];
  int min_dist = INT_MAX;

  for(int i = 1; i<=n; i++){


    dist[i] = dist1[i] + dist2[i];

    if(dist[i] < min_dist)
      min_dist = dist[i];
  }







// rail then road Case
//CANT JUST USE G1 AND G2 again. Got to use G3 which wouldbe reverse of original road wala ie g1
//and g4 which would be original raill wala without reversing it;


multiset< pair<int,int> > s3;

//1st djikstra Run

dist3[u] = 0;
s3.insert(make_pair(0,u));

while(!s3.empty()){

  pair<int,int> curr = *s3.begin();
  s3.erase(s3.begin());

  int curr_dist = curr.first;
  int curr_vertex = curr.second;

  if(vis3[curr_vertex])
    continue;

  vis3[curr_vertex] = 1;

  for(int k = 0; k<g4[curr_vertex].size(); k++){

    pair<int, int> p = g4[curr_vertex][k];
    int v = p.first;
    int w = p.second;

    if(dist3[v] > dist3[curr_vertex] + w){

      dist3[v] = dist3[curr_vertex] + w;
      s3.insert(make_pair(dist3[v],v));

    }

  }

}



//2nd Run

multiset< pair<int,int> > s4;

//1st djikstra Run

dist4[v] = 0;
s4.insert(make_pair(0,v));

while(!s4.empty()){

  pair<int,int> curr = *s4.begin();
  s4.erase(s4.begin());

  int curr_dist = curr.first;
  int curr_vertex = curr.second;

  if(vis4[curr_vertex])
    continue;

  vis4[curr_vertex] = 1;

  for(int k = 0; k<g3[curr_vertex].size(); k++){

    pair<int, int> p = g3[curr_vertex][k];
    int v = p.first;
    int w = p.second;

    if(dist4[v] > dist4[curr_vertex] + w){

      dist4[v] = dist4[curr_vertex] + w;
      s4.insert(make_pair(dist4[v],v));

    }

  }

}

dist3[v] = INT_MAX;
dist4[u] = INT_MAX;

int dist5[n+1];
int min_dist2 = INT_MAX;

for(int i = 1; i<=n; i++){


  dist5[i] = dist3[i] + dist4[i];

  if(dist5[i] < min_dist2)
    min_dist2 = dist5[i];
}


  cout<<min(min_dist,min_dist2)<<endl;

}
