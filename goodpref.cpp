#include<bits/stdc++.h>

using namespace std;

int main(){

  long long int num_tests = 0;
  cin>>num_tests;

  while (num_tests--) {

    string s;
    cin>>s;

    long long int n = 0;
    cin>>n;

/*    int a = 0, b = 0;

    for(int i = 0; i<s.size(); i++){

      if(s[i] == 'a')
        a++;
      else
        b++;

    }*/

    long long int ans = 0;

  /*  if(a<b){

      int curr_a = 0, curr_b = 0;

      for(int i = 0; i<s.size(); i++){

        if(s[i] == 'a')
          curr_a++;

        else
          curr_b++;

        if(curr_a > curr_b)
          ans++;

      }

      cout<<ans<<endl;
      continue;

    }*/

    long long int this_ans = 0;
    long long int last_ans = 0;

    long long int curr_a = 0, curr_b = 0;
    long long int c = 0;

    while(c<n){

      c++;

      for(long long int i = 0; i<s.size(); i++){

        if(s[i] == 'a')
          curr_a++;

        else
          curr_b++;

        if(curr_a > curr_b)
            this_ans++;

      }

      ans = ans + this_ans;

      if(last_ans == this_ans)
        break;

      last_ans = this_ans;
      this_ans = 0;

    }

    if(c!=n)
      ans = ans + (n-c)*last_ans;

    cout<<ans<<endl;

  }

}
