#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int visited[10001] = {0};

    for(int i = 0; i<10000; i++){

      visited[i] = 0;

    }

    int a = 0, b = 0, c = 0, d = 0;

    cin>>a;
    visited[a]++;
    cin>>b;
    visited[b]++;
    cin>>c;
    visited[c]++;
    cin>>d;
    visited[d]++;

    int two = 0, four = 0;

    for(int i = 1; i<10000; i++){

      if(visited[i] == 2)
        two++;
      if(visited[i] == 4)
        four++;

    }

    if(two == 2 || four == 1 ){

      cout<<"YES"<<endl;

    }
    else{

      cout<<"NO"<<endl;

    }
  }

}
