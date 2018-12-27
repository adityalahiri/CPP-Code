#include<bits/stdc++.h>

using namespace std;

int main(){

  int n = 0;
  cin>>n;

  std::vector<int> v[n];

  int sum_1 = 0, sum_2 =0;

  for(int i = 0; i<n;i++){

    for(int j = 0; j<n; j++){

      int t = 0;
      cin>>t;

      v[i].push_back(t);

    }

  }

  for(int i = 0; i<n; i++){

    sum_1 = sum_1 + v[i][i];

  }

  int j = n-1;

  for(int i = 0; i<n; i++){

    sum_2 = sum_2 + v[i][j];
    j--;

  }

  cout<<abs(sum_1-sum_2)<<endl;

}
