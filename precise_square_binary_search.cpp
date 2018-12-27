#include <bits/stdc++.h>

using namespace std;

int main(){

  float n = 0.0;
  cin>>n;

  float l = 0.0, u = n-1.0, mid = 0.0;
  float prec = pow(10,-3);

  while(u - l >= prec){

    mid = (u+l)/2.0;

    if((mid*mid) < n)
      l = mid;
    else
      u = mid;

  }

  cout<<mid;

}
