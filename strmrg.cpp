#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll n = 0, m = 0;
    cin>>n>>m;

    string ai;
    string bi;
    cin>>ai;
    cin>>bi;

    std::vector<char> a;
    std::vector<char> b;

    std::vector<char> a1;
    std::vector<char> b1;

    for(ll i = 0; i<ai.length(); i++){

      a.push_back(ai[i]);

    }

    for(ll i = 0; i<bi.length(); i++){

      b.push_back(bi[i]);

    }
    //cout<<"yo";

    std::vector<char> v;
    int counter = 0;

    while(v.size() != (m+n)){

      if(v.empty()){ // first time adding arbitrarily from a

        v.push_back(a[0]);
        a.erase(a.begin());
        continue;

      }

      if(!a.empty() && (v[v.size()-1] == a[0])){//cant arbit start with a

          v.push_back(a[0]);
          a.erase(a.begin());

        }

      else if(!b.empty() && (v[v.size()-1] == b[0])){

          v.push_back(b[0]);
          b.erase(b.begin());

        }


      else if(!a.empty()){

        v.push_back(a[0]);
        a.erase(a.begin());

      }

      else if(!b.empty()){

      v.push_back(b[0]);
      b.erase(b.begin());

      }
    }

    ll ans = 0;

    for(ll i = 0; i<v.size()-1; i++){

      if(v[i] != v[i+1])
        ans++;

    }


    // if start with b


    for(ll i = 0; i<ai.length(); i++){

      a1.push_back(ai[i]);

    }

    for(ll i = 0; i<bi.length(); i++){

      b1.push_back(bi[i]);

    }
    //cout<<"yo";

    std::vector<char> v1;

    while(v1.size() != (m+n)){

      if(v1.empty()){ // first time adding arbitrarily from a

        v1.push_back(b1[0]);
        b1.erase(b1.begin());
        continue;

      }

      if(!b1.empty() && (v1[v1.size()-1] == b1[0])){

          v1.push_back(b1[0]);
          b1.erase(b1.begin());

        }

      else if(!a1.empty() && (v1[v1.size()-1] == a1[0])){//cant arbit start with a

          v1.push_back(a1[0]);
          a1.erase(a1.begin());

        }



      else if(!a1.empty()){

        v1.push_back(a1[0]);
        a1.erase(a1.begin());

      }

      else if(!b1.empty()){

      v1.push_back(b1[0]);
      b1.erase(b1.begin());

      }
    }

    ll ans1 = 0;

    for(ll i = 0; i<v1.size()-1; i++){
      //cout<<v1[i];
      if(v1[i] != v1[i+1])
        ans1++;

    }
    //cout<<v1[v1.size()-1];
    //cout<<ans1+1<<"yo"<<ans+1<<"yo";


    cout<<min(ans+1,ans1+1)<<endl;

  }

}
