#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0;
    cin>>n;

    vector<stack<int> > v;

    for(int i = 0; i<n; i++){

      int a = 0;
      cin>>a;

      std::vector<int> temp;

      while(a--){

        int t = 0;
        cin>>t;

        temp.push_back(t);

      }

      stack<int> temp_stack;

      for(int j = temp.size()-1; j >= 0; j--){

        temp_stack.push(temp[j]);

      }

      v.push_back(temp_stack);

    }

    stack<int> popped;

    int total = 0;

    for(int j = 0; j<v.size(); j++)
      total = total + v[j].size();

    while(total--){

      int t = 0;
      cin>>t;

      popped.push(t);

    }

    //work

    int flag = 0;

    while(!popped.empty() && !flag){

      int curr = popped.top();
      popped.pop();

      int found = 0;

      for(int j = 0; j<v.size(); j++){

        if(v[j].empty())
          continue;

        int curr_top = v[j].top();
        //  cout<<"yo "<<curr_top<<" ";

        if(curr_top == curr){

          v[j].pop();
          found = 1;
          break;

        }

      }

      if(!found)
        flag = 1;

    }

    if(flag)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;

  }

}
