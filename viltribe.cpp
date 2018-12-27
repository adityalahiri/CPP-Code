#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while (num_tests--) {

    string s;
    ll num_a = 0,temp = 0,flag_a = 0,num_b = 0,flag_b = 0;


    cin>>s;

    for(ll i = 0; i<s.length(); i++){

      if(s[i]=='A' && flag_a){

        num_a+=temp;
        num_a++;
        temp = 0;
        flag_a = 1;
        flag_b = 0;


      }



      else if(s[i]=='B' && flag_b){

        num_b+=temp;
        num_b++;
        temp = 0;
        flag_b = 1;
        flag_a = 0;


      }

      else if(s[i]=='B' && !flag_b){

        temp = 0;
        flag_b = 1;
        flag_a = 0;
        num_b++;

      }

      else if(s[i]=='A' && !flag_a){

        temp = 0;
        flag_a = 1;
        flag_b = 0;
        num_a++;

      }

      else if(s[i] == '.'){

        temp++;

      }
      else
      {}


    }


    cout<<num_a<<" "<<num_b<<endl;


  }

}
