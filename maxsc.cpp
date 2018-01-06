#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0;
    cin>>n;

    if(n == 1){

      ll temp = 0;
      cin>>temp;
      cout<<temp<<endl;
      continue;

    }

    std::vector<ll> v[n];

    for(int i = 0; i<n; i++){

      for(int j = 0; j<n; j++){

        ll temp = 0;
        cin>>temp;

        v[i].push_back(temp);

      }

      std::sort (v[i].begin(), v[i].end()); // ascending order sort

    }

    ll max_sum = 0;
    int flag = 0;
    int max_i = n-1;
    int max_iminus = n-1;

    for(int i = n-1; i>0; i--){

      if(v[i][n-1] <= v[i-1][0]){

        flag = 1;
        cout<<-1<<endl;
        break;

      } // if max el of seq i is <= min el of i-1th seq then not possible

      int found = 0;


      while(!found && max_i >= 0){

        for(int j = n-1; j>=0; j--){

          if(v[i][max_i] > v[i-1][j]){

            max_iminus = j;
            found = 1;
            break;

          }

        }
        if(!found && i == n-1)//for the first time only can I adjust
          max_i--;

        if(!found){

          flag = 1;
          break;

        }

      }

      if(flag == 1){

        cout<<-1<<endl;
        break;

      }
      if(i == n-1){
        //cout<<v[i][max_i]<<" "<<v[i-1][max_iminus]<<endl;
        max_sum = max_sum + v[i][max_i] + v[i-1][max_iminus];
        //i--;

      }
      else
        max_sum = max_sum + v[i-1][max_iminus];

      max_i = max_iminus;
      max_iminus = n-1;

    }

    if(!flag)
      cout<<max_sum<<endl;

  }

}
