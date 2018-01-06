#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll N = 0, Q = 0;
  cin>>N>>Q;

  ll data[N+1];

  for(ll m = 1; m<N+1; m++)
    cin>>data[m];

  ll xor_data[N+1] = {0};
  xor_data[0] = 0;

  for(ll m = 1; m<N+1; m++)
      xor_data[m] = xor_data[m-1] ^ data[m];


  while(Q--){

    ll query_type = 0;
    cin>>query_type;

    if(query_type == 1){

      ll i = 0, x = 0;

      cin>>i>>x;

      for(ll m = i; m<N+1; m++)
        xor_data[m] = xor_data[m] ^ data[i] ^ x;

      data[i] = x;

    }

    if(query_type == 2){

      ll i = 0, k = 0, ans = 0;

      cin>>i>>k;

      for(ll m = 1; m <=i; m++)
        if(xor_data[m] == k)
          ans++;

      cout<<ans<<endl;
    }

  }

}
