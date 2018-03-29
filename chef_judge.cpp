#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0;
    cin>>n;

    int sum1 = 0, sum2 = 0;
    int max1 = 0, max2 = 0;

    for(int i = 0; i<n; i++){

      int a = 0;
      cin>>a;

      if(a>max1)
        max1 = a;

      sum1+=a;

    }

    for(int i = 0; i<n; i++){

        int a = 0;
        cin>>a;

        if(a>max2)
          max2 = a;

        sum2+=a;

    }

    sum1-=max1;
    sum2-=max2;

    if(sum1<sum2)
      cout<<"Alice"<<endl;
    else if(sum2<sum1)
      cout<<"Bob"<<endl;
    else
      cout<<"Draw"<<endl;

  }

}
