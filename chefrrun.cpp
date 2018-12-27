#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll n = 0;
    cin>>n;

    ll ans = 0;

    ll arr[n] = {0};

    for(ll i = 0; i<n; i++){

      cin>>arr[i];

    }


    ll visited[n] = {0};

    for(ll i = 0; i<n; i++){

      //ll temp_visited[n] = {0};
      ll temp = i;

      if(visited[temp] == 1){

        continue;

      }
    //  cout<<"bo";

      ll temp_visited[n] = {0};

      while(temp_visited[temp] != 1){

        if(visited[temp] == 1){

          break;

        }

        temp_visited[temp] = 1;
        temp = (temp + arr[temp] + 1)%n;


      }

      int flag = 0;



      if(i != temp){

        for(int m = 0; m<n; m++)
           temp_visited[m] = 0;


        while(temp_visited[temp] != 1){
          //cout<<"yo";

          if(visited[temp] == 1){
            flag = 1;
            break;

          }

        temp_visited[temp] = 1;
      //  cout<<endl;
        /*for(int m = 0; m<n; m++)
          cout<<temp_visited[m];
        cout<<endl;*/
        temp = (temp + arr[temp] + 1)%n;


        }


      }


      if(!flag) {
        for(int j = 0; j<n; j++){

          visited[j] = visited[j] | temp_visited[j];
          ans += temp_visited[j];

      }
    }

      }

        cout<<ans<<endl;

    }



  }
