#include<bits/stdc++.h>

using namespace std;

int main(){

  int n = 0, m = 0;
  cin>>n>>m;

  pair< int, int > data[n+1][m+1];

  for(int i = 1; i<=n; i++){

      for(int j = 1; j <= m;j++){

        char s;
        cin>>s;

        if(s == '.') // 9 for dot
          data[i][j] = make_pair(9,0);

        else if(s == '*'){
          data[i][j] = make_pair(10,0);

        }

        else{

          data[i][j] = make_pair(int(s)-48, 0);
          //cout<<int(s)<<endl;
        }

      }

  }

  for(int i = 1; i<=n; i++){

    for(int j = 1; j<=m; j++){

      pair<int, int> p = data[i][j];

      if(p.first == 10){

        if(i+1 <= n)
          data[i+1][j].second++;

        if(i-1 >=1)
          data[i-1][j].second++;

        if(i+1 <=n && j+1 <= m)
          data[i+1][j+1].second++;

        if(j+1<=m)
          data[i][j+1].second++;

        if(i-1 >=1 && j+1 <=m)
          data[i-1][j+1].second++;

        if(j-1 >= 1)
          data[i][j-1].second++;

        if(i-1 >=1 && j-1 >=1)
          data[i-1][j-1].second++;

        if(i+1 <=n && j-1 >=1)
          data[i+1][j-1].second++;

      }

    }

  }

  int flag = 0;

  for(int i = 1; i<=n; i++){

    for(int j =1; j<=m; j++){

      pair<int, int> p = data[i][j];

      int sym = p.first;
      int val = p.second;

      if(sym>=1 && sym<=8){

//        cout<<sym<<" "<<val<<endl;

        if(val!=sym){

          flag = 1;
          break;

        }


      }

      if(sym == 9){

        if(val != 0){

          flag =1;
          break;

        }


      }


    }

  }

  if(flag)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;

}
