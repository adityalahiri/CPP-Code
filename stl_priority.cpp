#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_data = 0;
  cin>>num_data;

  std::vector<int> v;

  for(int i = 0; i<num_data; i++){

    int val = 0;
    cin>>val;

    v.push_back(val);

  }

  priority_queue<int> max_pq;
  priority_queue <int, std::vector<int>, greater<int> > min_pq;

  for(int i = 0; i <num_data; i++ ){

    max_pq.push(v[i]);
    min_pq.push(v[i]);

  }

  int flag1 = 0, flag2 = 0;

  for(int i = 0; i<(num_data/2)-1; i++){

    int min_ele = min_pq.top();

    cout<<v[i]<<endl;

    cout<<min_ele<<endl;

    int max_ele = max_pq.top();

    cout<<max_ele<<endl;

    min_pq.pop();
    max_pq.pop();

    if(min_ele != v[i])
      flag1 = 1;
    if(max_ele != v[i])
      flag2 = 1;

  }

  if(!flag1)
    cout<<"MINHEAP"<<endl;
  else if(!flag2)
    cout<<"MAXHEAP"<<endl;
  else
    cout<<"NONE"<<endl;



}
