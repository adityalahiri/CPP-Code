
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll n = 0, k = 0;
    cin>>n>>k;

    ll sum = 0;

    ll data[n] = {0};

    int flag = 0;

    for(ll i = 0; i<n; i++){

      ll temp = 0;
      cin>>temp;

      data[i] = temp;
      sum+=temp;

      if(temp>0)
        flag = 1;
    }

    if(!flag){ // all negative numbers

      sort(data, data+n);
      cout<<data[n-1]<<endl;
      continue;

    }

    /*if(sum > 0){
      cout<<(sum*k)<<endl;
      continue;

    }*/

    //ll size_concat_data = 2*n;

    //ll concat_data[size_concat_data] = {0};

    /*for(ll i = 0; i < n; i++)
      concat_data[i] = data[i];

    for(ll i = n; i<size_concat_data; i++)
      concat_data[i] = data[i-n];*/

    ll current_max = 0;
    ll overall_max = 0;

    for(ll i = 0; i<n*k; i++){

      if((current_max + data[i%n]) >= overall_max){

        //cout<<concat_data[i]<<" ";
        current_max+=data[i%n];
        overall_max = current_max;

      }
      else if((current_max + data[i%n]) > 0){

        current_max+=data[i%n];
        //cout<<"yo"<<current_max<<" ";

      }
      else{

        current_max = 0;

      }

    }

    cout<<max(overall_max, sum*k)<<endl;

  }

}
