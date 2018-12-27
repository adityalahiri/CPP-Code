#include<bits/stdc++.h>

using namespace std;

int ans = 0;

void sum_comb(vector<int> arr,int i,int sum ){

  if(sum == 0){

    ans++;
    return;

  }

  if(sum<0)
    return;

  while(i < arr.size() && sum - arr[i] >=0){

    sum_comb(arr,i+1,sum-arr[i]);

  //  sum += arr[i];

    i++;


  }

}

int main(){

  int x = 0, n = 0;
  cin>>x>>n;

  std::vector<int> arr;

  int curr = 0;
  int i = 1;

  while(true){

    curr = pow(i,n);
    if(curr>x)
      break;
    arr.push_back(curr);
    i++;

  }

  //for(int k = 0; k<arr.size();k++)
    //cout<<arr[k]<<endl;
  sum_comb(arr,0,x);
  cout<<ans<<endl;



}
