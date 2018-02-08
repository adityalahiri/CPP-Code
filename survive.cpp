#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, k = 0, s = 0, ans = 0;
    cin>>n>>k>>s;

    int total_need = 0,num_sundays = 0, num_buying_days = 0;

    total_need = k*s;
    num_sundays = s/7;
    num_buying_days = s - num_sundays;

    if(n*num_buying_days < total_need){

      cout<<-1<<endl;
      continue;

    }

    if(total_need%n == 0)
      ans = total_need/n;
    else
      ans = (total_need/n) + 1;

    cout<<ans<<endl;

  }

}
