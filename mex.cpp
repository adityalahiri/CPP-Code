#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int visited[2000001] = {0};

    for(ll i = 0; i<2000001; i++)
      visited[i] = 0;

    ll N = 0, K = 0;
    cin>>N>>K;

    for(ll i = 0; i<N; i++){

      ll temp = 0;
      cin>>temp;

      visited[temp] = 1;

    }

    if(K == 0){

      for(ll i = 0; i<2000001; i++ ){

        if(!visited[i]){

          cout<<i<<endl;
          break;

        }


      }

    }

    else{

    ll count = 0;

    ll i = 0;

    for(i = 0; i<2000001; i++ ){

      if(count == K && !visited[i])
        break;

      if(!visited[i]){

        count++;


      }

    }

    cout<<i<<endl;

  }
  }

}
