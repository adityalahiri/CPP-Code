#include<bits/stdc++.h>

using namespace std;

int n = 0;
std::vector<int> v,sorted;

void heapify_one(int index){

  if(index  > (v.size()-2)/2)
    return;

  if(v[index] < v[2*index] && v[index] < v[2*index + 1])
    return;

  if(v[index] > v[2*index]){

    int temp = v[index];
    v[index] = v[2*index];
    v[2*index] = temp;

    heapify_one(2*index);

  }

  else if(v[index] > v[2*index + 1]){

    int temp = v[index];
    v[index] = v[2*index + 1];
    v[2*index + 1] = temp;

    heapify_one(2*index + 1);

  }

}

void heapify_fly(int index){

  if(index == 1)
    return;

  if(v[index] > v[index/2]){

    return;

  }

  else{

    int temp = v[index/2];
    v[index/2] = v[index];
    v[index] = temp;

    heapify_fly(index/2);

  }

}

void display_min(){
  if(v.size()>=2)
  cout<<v[1]<<endl;

}

void remove_min(){

  display_min();

  int temp = v[1];
  sorted.push_back(temp);
  v[1] = v[v.size()-1];

  if(v.size() == 2){
    v.pop_back();
    return;

  }
  v.pop_back();
  heapify_one(1);


}

int main(){

  v.push_back(-1);
  int val = 0;
  cin>>val;

  while(val!=-1){

    v.push_back(val);
    cin>>val;

    heapify_fly(v.size()-1);

  }

/*  for(int i = (n-1)/2; i>=1; i--){

    heapify_one(i); //constructing min heap O(n)

  }*/

  while(v.size()> 1)
    remove_min();
  //cout<<v[v.size()-1]<<endl;

  /*for(int i = 1; i<v.size(); i++)
    cout<<v[i]<<" ";*/

}
