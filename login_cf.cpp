#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  string first,last;

  cin>>first;
  cin>>last;

  char ch = last[0];
  int i = 1;

  cout<<first[0];

  for(i = 1; i<first.length(); i++)
      if(first[i] >= ch)
        break;

  for(int j = 1; j<i; j++)
    cout<<first[j];

  cout<<last[0];



}
