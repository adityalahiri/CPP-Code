#include<bits/stdc++.h>

using namespace std;

int main(){

  // include CASE OF NOT POSSIBLE!

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    stack<int> s;

    int num_data = 0;
    cin>>num_data;

    for(int i = 0; i<num_data; i++){

      int t = 0;
      cin>>t;

      s.push(t);

    }

    stack<int> temp;

    int f = s.top();
    s.pop();
    temp.push(f);
    int flag = 0;

    while(!s.empty()){

      int curr = s.top();

      if(temp.top() > curr){

        int t = temp.top();
        temp.pop();
        s.pop();
        s.push(t);
        temp.push(curr);
        flag = 1;
        break;

      }
      else{

        s.pop();
        temp.push(curr);

      }

    }
    if(!flag){

      cout<<-1<<endl;
      continue;

    }



    stack<int> ans;

    while(!temp.empty()){

        int x = temp.top();
        ans.push(x);
        temp.pop();

    }

    while(!s.empty()){

        int x = s.top();
        ans.push(x);
        s.pop();

    }

    while(!ans.empty()){
      int x = ans.top();
      cout<<x;
      ans.pop();
    }

    cout<<endl;

  }

}
