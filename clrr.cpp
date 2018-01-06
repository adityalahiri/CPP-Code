#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll N,score;
    cin>>N>>score;

    ll data[N] = {0};

    for(ll i = 0; i<N; i++){

      cin>>data[i];

    }

    ll least_v = 0, flag_least = 0, max_v = 0, flag_max = 0, flag = 0;

    for(ll i = 0; i<N; i++){

      if(data[i] > score && !flag_least){

        flag_least = 1;
        least_v = data[i];

      }

      if(data[i] < score && !flag_max){

        flag_max = 1;
        max_v = data[i];

      }

    }

    for(ll i = 0; i<N; i++ ){

      if(score < data[i]){

        if(data[i] > least_v){

          flag = 1;
          break;

        }
        else
        {

          least_v = data[i];

        }

      }
      else{

        if(data[i] < max_v){

          flag = 1;
          break;

        }
        else{

          max_v = data[i];

        }

      }

    }
    if(flag)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;

  }

}
