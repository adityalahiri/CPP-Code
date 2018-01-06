#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll matches = 0;
    cin>>matches;

    ll a_score = 0, b_score = 0;

    string team_a = "1", team_b = "2", temp = "3";

    ll a_flag = 0, b_flag = 0;

    while(matches--){

    cin>>temp;

    if(!a_flag){
      team_a = temp;
      a_flag++;
      a_score++;
    }

    else if(!b_flag && temp!=team_a){
      team_b = temp;
      b_flag++;
      b_score++;
    }

    else{

    if(temp == team_a)
      a_score++;

    else
      b_score++;
}
}

  if(a_score>b_score)
    cout<<team_a<<" "<<endl;
  else if(b_score>a_score)
    cout<<team_b<<endl;
  else
    cout<<"Draw"<<endl;
  //cout<<a_score<<" "<<b_score<<" ";



  }

}
