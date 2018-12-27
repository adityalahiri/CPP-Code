#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int n = 0;
  cin>>n;

  ll arr[n] = {0};

  for(int i = 0; i<n; i++)
    cin>>arr[i];

  sort(arr, arr+n, greater<int>());

  for(int i = 0; i<n; i++){

    float temp = 0.0;
    temp = sqrt(arr[i]);
    int up = ceil(temp);
    int down = floor(temp);
    if((up*up) != arr[i] || (down*down) != arr[i] ){

      cout<<arr[i]<<endl;
      break;

    }

  }

}
