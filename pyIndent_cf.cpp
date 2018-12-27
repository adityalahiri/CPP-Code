#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int n = 0;
  cin>>n;

  int flag = 0;
  ll ans = 1;

  std::vector<char> v;

  ll data[2500] = {0};
  data[0] = 1;
  data[1] = 2;
  for(ll i = 2;i<2500;i++)
    data[i] = 2*data[i-1] +1;


  char temp;
  cin>>temp;

  v.push_back(temp);

  cin>>temp;

  v.push_back(temp);

  n-=2;

  while(n--){

    cin>>temp;

    if(v.back() == 'f'){

      v.push_back(temp);
      continue;

    }

    if(v[v.size()-2] == 'f' && v.back() == 's'){

      flag++;
      v.push_back(temp);
      ans = ans + (data[flag]);

      }

    else{
      ans = ans + (data[flag]);
      v.push_back(temp);

    }

  }

  cout<<ans%1000000007;

}
