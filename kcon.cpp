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

    ll overall_max = 0;

    ll current_max_1 = 0;
    ll overall_max_1 = 0;

    for(ll i = 0; i<n; i++){

      if((current_max_1 + data[i%n]) >= overall_max_1){

        //cout<<concat_data[i]<<" ";
        current_max_1+=data[i%n];
        overall_max_1 = current_max_1;

      }
      else if((current_max_1 + data[i%n]) > 0){

        current_max_1+=data[i%n];
        //cout<<"yo"<<current_max<<" ";

      }
      else{

        current_max_1 = 0;

      }

    }

    ll current_max_2 = 0;
    ll overall_max_2 = 0;

    for(ll i = 0; i<n*2; i++){

      if((current_max_2 + data[i%n]) >= overall_max_2){

        //cout<<i<<" "<<data[i%n]<<" ";
        current_max_2+=data[i%n];
        overall_max_2 = current_max_2;

      }
      else if((current_max_2 + data[i%n]) > 0){

        current_max_2+=data[i%n];
        //cout<<"yo"<<current_max_2<<" ";

      }
      else{
        //cout<<i<<"else "<<data[i%n]<<" ";
        current_max_2 = 0;

      }

    }

    ll current_max_3 = 0;
    ll overall_max_3 = 0;

    for(ll i = 0; i<n*3; i++){

      if((current_max_3 + data[i%n]) >= overall_max_3){

        //cout<<i<<" "<<data[i%n]<<" ";
        current_max_3+=data[i%n];
        overall_max_3 = current_max_3;

      }
      else if((current_max_3 + data[i%n]) > 0){

        current_max_3+=data[i%n];
        //cout<<"yo"<<current_max_3<<" ";

      }
      else{
        //cout<<i<<"else "<<data[i%n]<<" ";
        current_max_3 = 0;

      }

    }

    if(overall_max_3 <= overall_max_2){
      if(overall_max_2 > overall_max_1 && k>1)
        overall_max = overall_max_2;
      else
        overall_max = overall_max_1;

    }
    else if( (overall_max_3-overall_max_2) != (overall_max_2 - overall_max_1) ){

      if(overall_max_2 > overall_max_1 && k == 2)
        overall_max = overall_max_2;
      else if(k == 1)
        overall_max = overall_max_1;
      else{

        ll diff = overall_max_3 - overall_max_2;
        ll to_add = (k-2)*diff;
        overall_max = overall_max_2 + to_add;

      }


    }

    else if(overall_max_2 > overall_max_1){

      ll diff = overall_max_2 - overall_max_1;//HAVE TO MODIFY THIS
      ll to_add = (k-1)*diff;
      //cout<<"op"<<to_add;
      overall_max = overall_max_1 + to_add;
      //cout<<"yp"<<overall_max;


    }
    else{

      overall_max = overall_max_1;

    }
    //cout<<"f"<<overall_max_1<<" "<<overall_max_2<<" "<<overall_max_3<<" "<<overall_max<<endl;

    cout<<max(overall_max, sum*k)<<endl;

  }

}
