#include<bits/stdc++.h>

using namespace std;

int data[100000];

int main(){

  data[0] = 0;
  for(int i = 1; i<100000; i++){

    data[i] = data[i-1] + i;

  }

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int ans = 1;

    int x = 0;
    cin>>x;

    int lower = lower_bound(data, data+100000 , x) - data;

    if(x == data[lower])
      ans = ans + lower -1;

    else{

      int method_one = ans + lower - 1 + (data[lower] - x);
      int method_two = ans + lower - 2 + (x - data[lower-1]);

      ans = min(method_one, method_two);

    }

    cout<<ans<<endl;

  }

}
