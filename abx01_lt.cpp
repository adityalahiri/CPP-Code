#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll precompute[10000000] = {0};


int give_f(ll num){ // always a times

  ll sum = 0;
  ll nu = num;
  //cout<<num<<" ";

  if(num >= 10000000){

  while(nu/10){ // if sum exceeds 9 i send it again

    sum = sum + nu%10;
    nu/=10;

  }

  sum+=nu;

}
  else{

    sum = precompute[num];

  }

  if(sum > 9)
    sum = give_f(sum);

  return sum;
  }

void give_sum(ll num){

  //cout<<num<<" ";

  if(num%10)
    precompute[num] = precompute[num-1] + 1;
  else
    precompute[num] = precompute[num-1] - 8;


}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // precompute sum of digits

  precompute[0] = 0;
  precompute[1] = 1;

  for(ll i = 2; i<10000000; i++)
    give_sum(i);



  ll num_tests = 0;

  cin>>num_tests;

  while( num_tests-- ){

    ll a = 0, n = 0;
    cin>>a>>n;

    ll pre[10];

    for(int i = 0; i<10; i++)
      pre[i] = -1;

    ll c = 1;
    ll current_num  = a;
    ll temp = -1;

    while(c <= n){

      if(temp != -1 && pre[temp] != -1){

        current_num = pre[temp];

        if(c == n)
          break;


      }

      else{

      current_num = give_f(current_num);
      //cout<<"no"<<current_num<<" ";
      if(temp != -1)
        pre[temp] = current_num;

      if(c == n)
        break;

      }

      temp = current_num;
      //cout<<temp<< " ";


      /*for(ll i = 0; i<(a-1); i++)
        current_num = current_num + temp;*/

        current_num = current_num * a;


    //  cout<<"yo"<<current_num<<" ";



      c++;



    }

    cout<<current_num<<endl;

  }

}
