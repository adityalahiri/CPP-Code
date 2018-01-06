#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll num_data = 0;
    cin>>num_data;

    ll data[num_data] = {0};

    for(ll i = 0; i<num_data; i++)
      cin>>data[i];

    std::vector<int> v;

    ll two = 0, ans = 0, zero = 0;

    for(ll i = 0; i<num_data; i++){
      int t = data[i]%4;

      if(t==2){

        two++;

      }
      else if(t==0)
        zero++;
      else
        v.push_back(t);

    }

    if(v.empty() && zero ){

      if(two%2){

        cout<<-1<<endl;
        continue;

      }
      else{

        cout<<two/2<<endl;
        continue;
    }

    }

    if(v.empty() && zero == 0){

      if(two%2){

        cout<<-1<<endl;
        continue;

      }
      else {

        cout<<two/2<<endl;
        continue;
      //  cout<<ans<<"u";

      }
    }

    ll flag = 0,temp = 0,i = -1,one = 0,three = 0;

    sort(v.begin(), v.end());
    while(v[++i] == 1)
      one++;
    i = v.size();
    while(v[--i] == 3)
      three++;


    //cout<<two;
    if(two%2){
      int flag = 0;

      if(three>one)
        flag = 1;


      if(one>=2 && !flag){

        one-=2;
        ans+=2;

      }

      else if(three>=2 && flag){

        three-=2;
        ans+=2;

      }

      else{

      cout<<-1<<endl;
      continue;

    }
  }


      ans = ans + two/2;
    // cout<<ans<<"u";


    if((one == max(one,three)) && (((one - three) %4) == 0) ){

      ll a = one-three;
      ll b = a/4;

      ans = ans + (3*b);

      one = one - a;

    }

    if((three == max(one,three)) && (((three- one) %4) == 0) ){
      //cout<<"yo";
      ll a = three - one;

      ll b = a/4;

      ans = ans + (3*b);

      three = three - a;

    }





    //cout<<"u"<<ans<<"u"<<one<<"u";
    if(one != three)
      cout<<-1<<endl;
    else
      cout<<(ans + (one))<<endl;

  }

}
