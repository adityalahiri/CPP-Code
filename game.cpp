#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_data = 0;
  cin>>num_data;

  std::vector<int> v;

  for(int i = 0; i<num_data; i++){

    int t = 0;
    cin>>t;

    v.push_back(t);

  }

  sort(v.begin(), v.end());

  if(num_data%2 == 0){

    cout<<v[(num_data/2)-1]<<endl;

  }
  else{

    cout<<v[num_data/2]<<endl;

  }

}
