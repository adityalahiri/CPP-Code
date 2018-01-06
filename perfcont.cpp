#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll N = 0, P = 0;
    cin>>N>>P;

    int cake = 0, hard = 0;

    while(N--){

      ll temp = 0;
      cin>>temp;

      if(temp >= P/2)
        cake++;

      if(temp <= P/10)
        hard++;

    }

    if(cake == 1 && hard == 2)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;

  }

}
