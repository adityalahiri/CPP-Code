#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_data = 0;
  cin>>num_data;

  int data[num_data+1]; // 1 indexing
  data[0] = 0;

  for(int i = 1; i<(num_data+1); i++)
    cin>>data[i];

  int flag_max = 0;
  int flag_min = 0;

  int leaves_start = (num_data/2) + 1;

  //checking if max_heap

  for(int i = (num_data); i>1; i--){

    //cout<<data[i]<<endl;

    int parent = data[i/2];
    int node = data[i];

    if(node>parent)
      flag_max = 1;

  }

  //checking if min_heap

  for(int i = (num_data); i>1; i--){

    //cout<<data[i]<<endl;

    int parent = data[i/2];
    int node = data[i];

    if(node<parent)
      flag_min = 1;

  }

  if(!flag_max)
    cout<<"MAXHEAP"<<endl;
  else if(!flag_min)
    cout<<"MINHEAP"<<endl;
  else
    cout<<"NONE"<<endl;

}
