#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll N,P;
    cin>>N>>P;

    if((N==P && N==2) || P == 1 || P == 2){

      cout<<"impossible"<<endl;
      continue;

    }

    string s[P];

    s[0] = 'a';
    s[P-1] = 'a';

    for(ll i = 1; i<P-1; i++)
      s[i] = 'b';

    for(ll i = 0; i<N; i+=P){
      for(ll i = 0; i<P; i++)
        cout<<s[i];
    }

    cout<<endl;

  }

}
