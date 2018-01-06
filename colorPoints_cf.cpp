#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  std::vector<char> v;

  string s;
  cin>>s;

  for(ll i = 0; i<s.length(); i++)
    v.push_back(s[i]);


  int moves = 0;

  while(!v.empty()){

    int flag = 0;

    for(ll i = 0; i<v.size()-1; i++){
        if(v[i]!=v[i+1]){
            flag = 1;
            break;
        }
      }

    if(flag == 0)
      break;

    char temp;

    for(ll i = 0; i<v.size()-1; i++){

      temp = v[i+1];

      if(v[i]!=v[i+1])

    }

  }

}
