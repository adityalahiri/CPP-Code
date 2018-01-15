#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void func(ll sum, ll num,ll n, ll arr[], ll x){
  //for(ll i = num; i>=1; i--){
      while(true){

        if(arr[num]!=1 && num!=x)
          break;
        //cout<<sum<<"y"<<num<<endl;
        num--;

      }
      arr[num]=1;
      if(sum-num >= 0 && num!=x && (sum-num)!=x && (sum-num<n) && (sum-num!= num) && arr[sum-num]!=1){
        arr[sum-num]=1;
        return;
      }

      else if(sum-num == x || arr[sum-num] == 1){

        arr[num] = 0;
        num--;
        /*if(sum-num >= 0 && num!=x && (sum-num)!=x && (sum-num<n) && (sum-num!= num) && arr[sum-num]!=1){
          arr[num] = 1;
          arr[sum-num] = 1;
        }*/

        func(sum,num--,n,arr,x);

        }

      else if(sum-num>=n){
        //cout<<sum-num<<" ";
        func(sum-num, n, n, arr, x);
      }

    /*  else if((sum - num) >=0 && (sum-num) <n){

        if(arr[sum-num] == 1){
          arr[num] = 0;
          func(sum,num--,n,arr,x);
      }

    }*/

}

int main(){

  ll num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    ll x = 0, n = 0;
    cin>>x>>n;

    float sf = ((n)*(n+1))/2;
    long long int s = ((n)*(n+1))/2;

    sf = (sf - x)/2.0;
    s = (s - x)/2;


    if(s != ceil(sf) || n == 2){ // if 2 el then always imp

      cout<<"impossible"<<endl;
      continue;

    }

    //ll original = 0;
    //ll paired = 0;
    ll arr[n+1]={0};
    arr[x]=2;
    func(s, n, n, arr, x);
    for(ll i=1; i<=n; i++) cout<<arr[i];
    cout<<"\n";

}
}
