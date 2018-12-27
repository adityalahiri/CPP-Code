#include<bits/stdc++.h>

using namespace std;

int main(){

  string s;
  long int n;

  cin>>s;
  cin>>n;

  long int num_rpt = n/s.size();
  long int left = n%s.size();

  long int ans = 0;

  long int num_each = 0;

  for(int i = 0; i<s.size(); i++){

    if(s[i] == 'a')
      num_each++;

  }

  ans = ans + num_rpt*num_each;

  for(int i = 0; i<left; i++){

    if(s[i] == 'a')
      ans++;

  }

  cout<<ans<<endl;

}
