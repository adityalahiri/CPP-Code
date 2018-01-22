#include <bits/stdc++.h>

using namespace std;

int main(){

  int n = 0;
  cin>>n;

  int arr[n] = {0};

  for(int i = 0; i<n; i++)
    arr[i] = i; //asc. order

  int x = 0;
  cin>>x;

  int l = 0, u = n, mid = 0; // why is u = n-1

  while (l <= u) {
    mid = (l+u)/2;
    //cout<<mid<<" ";
    /* code */
    if(arr[mid] == x)
      break;
    else if(x < arr[mid])
      u = mid - 1;
    else
      l = mid + 1;
  }

  if(l <= u)
      cout<<"Found at "<<mid;
  else
    cout<<"Not found"<<endl;

}
