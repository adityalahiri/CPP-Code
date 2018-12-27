#include<bits/stdc++.h>

using namespace std;

int main(){

  std::vector<int> v;
  int num_data = 0;
  cin>>num_data;

  for(int i = 0; i<num_data; i++){

    int t = 0;
    cin>>t;

    v.push_back(t);

  }

  sort(v.begin(), v.end());

  int mi_index = 0;
  int mi = v[mi_index];

  int ma_index = num_data-1;
  int ma = v[ma_index];

  int ops = 0;

  int diff = 0, cum_diff = 0;

  while(mi!=ma){

    diff = ma - mi;
    cum_diff+=diff;
    mi = ma;

    ops = ops + diff;

    ma_index--;
    ma = v[ma_index] + cum_diff;

  }

  cout<<ops<<endl;

}
