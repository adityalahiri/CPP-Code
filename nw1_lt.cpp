#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while (num_tests--) {
    /* code */
    int w = 0;
    string s;

    cin>>w;
    cin>>s;

    if(w == 28){
      cout<<"4 4 4 4 4 4 4"<<endl;
      continue;
    }

    int data[7] = {4};

    for(int i = 0; i<7; i++)
      data[i] = 4;

    if( w == 29){

      if(s == "mon")
        data[0]++;
      if(s == "tues")
        data[1]++;
      if(s == "wed")
        data[2]++;
      if(s == "thurs")
        data[3]++;
      if(s == "fri")
        data[4]++;
      if(s == "sat")
        data[5]++;
      if(s == "sun")
        data[6]++;
    }

    else if( w == 30){

      if(s == "mon"){
        data[0]++;
        data[1]++;
    }

      if(s == "tues"){
        data[1]++;
        data[2]++;
      }

      if(s == "wed"){
        data[2]++;
        data[3]++;
      }
      if(s == "thurs"){
        data[3]++;
        data[4]++;
      }
      if(s == "fri"){
        data[4]++;
        data[5]++;
      }
      if(s == "sat"){
        data[5]++;
        data[6]++;
      }
      if(s == "sun"){
        data[6]++;
        data[0]++;
      }

    }
    else{

      if(s == "mon"){
        data[0]++;
        data[1]++;
        data[2]++;
    }

      if(s == "tues"){
        data[1]++;
        data[2]++;
        data[3]++;
      }

      if(s == "wed"){
        data[2]++;
        data[3]++;
        data[4]++;
      }
      if(s == "thurs"){
        data[3]++;
        data[4]++;
        data[5]++;
      }
      if(s == "fri"){
        data[4]++;
        data[5]++;
        data[6]++;
      }
      if(s == "sat"){
        data[5]++;
        data[6]++;
        data[0]++;
      }
      if(s == "sun"){
        data[6]++;
        data[0]++;
        data[1]++;
      }

    }

    for(int i = 0; i<7;i++)
      cout<<data[i]<<" ";

    cout<<endl;

  }

}
