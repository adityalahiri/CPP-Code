#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_elements = 0;
  cin>>num_elements;

  int arr[num_elements] = {0};

  stack<int> s;
  int ans[num_elements] = {0};

  for(int i = 0; i<num_elements; i++)
    cin>>arr[i];

  for(int i = num_elements - 1; i>=0; i--){

        if(s.empty()){

        s.push(arr[i]);
        ans[i] = -1;

        }

        else{

            if(arr[i] < s.top()){

              ans[i] = s.top();
              s.push(arr[i]);

            }

            else{

              while(arr[i] >= s.top()){

                s.pop();

                if(s.empty())
                  break;

              }

              if(s.empty()){

                ans[i] = -1;
                s.push(arr[i]);

              }

              else{

                ans[i] = s.top();
                s.push(arr[i]);

              }

            }

        }

  }

    for(int i = 0; i<num_elements; i++)
      cout<<ans[i]<<" ";

}
