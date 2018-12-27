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

    std::vector<char> v;

    ll printed = 0, last_a = -1, last_b = -1, last_star = -1;

    while(printed < s.length()){

      ll greater = max(a,b);

      if(greater == a){

        if(printed < x){

          v.push_back('a');
          printed++;
          a--;
          last_a = 1;
          if(last_b != -1)
            last_b++;
          if(last_star != -1)
            last_star++;

        }

        else if((last_b <= x && last_b != -1) || (last_star <= x && last_star != -1)){

          v.push_back('a');
          printed++;
          a--;
          last_a = 1;
          if(last_b != -1)
            last_b++;
          if(last_star != -1)
            last_star++;


        }

        else if(b){

          v.push_back('b');
          printed++;
          b--;
          last_b = 1;
          if(last_a != -1)
            last_a++;
          if(last_star != -1)
            last_star++;

        }

        else{

          v.push_back('*');
          last_star = 1;
          if(last_a != -1)
            last_a++;
          if(last_b != -1)
            last_b++;

        }

      }

      //greater is b
      else{
        if(printed < y){

          v.push_back('b');
          printed++;
          b--;
          last_b = 1;
          if(last_a != -1)
            last_a++;
          if(last_star != -1)
            last_star++;

        }

        else if((last_a <= y && last_a != -1) || (last_star <= y && last_star != -1)){

          v.push_back('b');
          printed++;
          b--;
          last_b = 1;
          if(last_a != -1)
            last_a++;
          if(last_star != -1)
            last_star++;


        }

        else if(a){

          v.push_back('a');
          printed++;
          a--;
          last_a = 1;
          if(last_b != -1)
            last_b++;
          if(last_star != -1)
            last_star++;

        }

        else{

          v.push_back('*');
          last_star = 1;
          if(last_a != -1)
            last_a++;
          if(last_b != -1)
            last_b++;

        }
      }
    }

    for(ll i = 0; i<v.size(); i++)
      cout<<v[i];

    cout<<endl;
  }

}
