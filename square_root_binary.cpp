#include <bits/stdc++.h>

using namespace std;

int main(){

  int n = 0;
  cin>>n;

  int l = 0, u = n-1, mid = 0;

  while(l <= u){

    mid = (l+u)/2;

    if((mid*mid) == n)
      break;

    else if((mid*mid) < n && ((mid+1)*(mid+1) > n))
      break;

    else if((mid*mid) < n)
      l = mid + 1;

    else if((mid)*(mid) > n)
      u = mid - 1;

  }

    cout<<mid;


}
