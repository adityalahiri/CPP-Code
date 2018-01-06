#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while (num_tests--) {
    /* code */

    string s;
    cin>>s;

    ll a = 0, b = 0, x = 0, y = 0;
    cin>>x>>y;

    for(ll i = 0; i<s.length(); i++){

      if(s[i] == 'a')
        a++;
      else
        b++;

    }

    ll printed = 0;

    std::vector<char> v;

    while(printed < s.length()){

      ll greater = max(a,b);

      if(greater == a){

        ll flag = 0;

        if(v.size() < x){

          if(printed < x)
            flag = 1;

          for(ll i = 0; i<v.size(); i++){

            if(v[i] != 'a'){

              flag = 1;
              break;

            }

          }

        }

        else{

          ll c = 0;

          while(c<x){

            if(v[v.size()-1-c] != 'a'){

              flag = 1;
              break;

            }
            c++;

          }

        }

        if(flag){

          a--;
          v.push_back('a');
          printed++;

        }

        else if(!flag && b){

          b--;
          v.push_back('b');
          printed++;

        }

        else{

          v.push_back('*');

        }
      }

//greater is b

      else{
        //cout<<"b";

        ll flag = 0;

        if(v.size() < y){

          if(printed < y)
            flag =1;
          //cout<<"uo"<<printed<<" ";

          for(ll i = 0; i<v.size(); i++){

            if(v[i] != 'b'){

              flag = 1;
              break;

            }

          }

        }

        else{
          //cout<<"yo";

          ll c = 0;

          while(c<y){

            if(v[v.size()- 1- c] != 'b'){

              flag = 1;
              break;

            }

            c++;

          }

        }

        if(flag){

          b--;
          v.push_back('b');
          printed++;

        }

        else if(!flag && a){

          a--;
          v.push_back('a');
          printed++;

        }

        else{

          v.push_back('*');

        }
      }
    }

    for(ll i = 0; i<v.size(); i++)
      cout<<v[i];

    cout<<endl;
    }
  }
