#include<bits/stdc++.h>

using namespace std;

int main(){

  int counter = 0;
  string str;

  while(true){

    counter++;
    cin>>str;

    if(str[0]=='-')
      break;

    stack<char> order_opposite;
    stack<char> open_bracket;

    for(int i = 0; i<str.length(); i++){

      char ch = str[i];

      if(ch == '{'){

        open_bracket.push('{');

      }

      else{

        if(open_bracket.empty()){

          open_bracket.push('}');

        }

        else if(open_bracket.top() == '{'){

          open_bracket.pop();

        }
        else{

          open_bracket.push('}');

        }

    }
  }
    int ans = 0;

    while(!open_bracket.empty()){

      char ch1 = open_bracket.top();
      open_bracket.pop();
      char ch2 = open_bracket.top();
      open_bracket.pop();
      //cout<<ch1<<" "<<ch2;

      if(ch1 == '{' && ch2 == '}')
        ans+=2;
      else
        ans+=1;

    }

    cout<<counter<<". "<<ans<<endl;

  }

}
