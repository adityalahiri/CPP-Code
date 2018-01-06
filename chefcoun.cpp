#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll n = 0;
    cin>>n;

    int left = n-99990;

    for(ll i = 0; i<70000; i++)
      cout<<42953<<" ";

    for(ll i = 0; i<29990; i++)
        cout<<42955<<" ";

    int p = 5;

    for(ll i = 0; i<left; i++)
      cout<<p++<<" ";

    cout<<endl;

  }


}
