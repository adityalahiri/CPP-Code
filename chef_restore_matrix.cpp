#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, m = 0;
    cin>>n>>m;

    int data[n][m];

    for(int i = 0; i<n; i++){

      for(int j = 0; j<m; j++){

        cin>>data[i][j];

      }

    }

    for(int i = 0; i<n; i++){

      for(int j = 0; j<m; j++){

        if(data[i][j] == -1){

          if(i == 0 && j == 0)
            data[i][j] = 1;
          else if(i == 0)
            data[i][j] = data[i][j-1];
          else if(j == 0)
            data[i][j] = data[i-1][j];
          else
            data[i][j] = max(data[i-1][j], data[i][j-1]);

        }

      }

    }

    int flag = 0;

    for(int i = 0; i<n; i++){

      for(int j = 0; j<m; j++){

        if(i == 0 && j == 0)
          continue;

        if(i == 0){

          if(data[i][j] < data[i][j-1])
            flag = 1;

        }

        else if(j == 0){

          if(data[i][j] < data[i-1][j])
            flag = 1;

        }

        else{

          if(data[i][j] < data[i-1][j] || data[i][j] < data[i][j-1])
            flag = 1;

        }

      }

    }

    if(flag == 1)
      cout<<-1<<endl;

    else{

      for(int i = 0; i<n; i++){

        for(int j = 0; j<m; j++){

          cout<<data[i][j]<<" ";

        }

        cout<<endl;

      }

    }

  }

}
