#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  stack<int>s;
  int min_curr = 0;

  while(num_tests--){

    int choice = 0;
    cin>>choice;

    if(choice == 1){ // push

      int x = 0;
      cin>>x;

      if(s.empty()){

          min_curr = x;
          s.push(x);

      }

      else{

        if(x > min_curr && x > 0){

          s.push(x);

        }

        else if(x > min_curr && x<0){

          s.push(abs(x));

        }

        //else if(x < min_curr && x<0)

        else{

          //cout<<"pushing "<<(x-min_curr)<<endl;
          s.push(x - min_curr);
          min_curr = x;

        }

      }

    }

    else if(choice == 2){ // pop

      int x = s.top();

      if( x > 0){

        s.pop();

      }

      else{
        //cout<<"yolo"<<" "<<x<<endl;
        min_curr = min_curr - x;
        s.pop();

      }

    }

    else{

      cout<<"Current minimum is "<<min_curr<<endl;

    }

  }

}
