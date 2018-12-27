#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, a = 0, b = 0;
    cin>>n>>a>>b;

    float fa = 0, fb = 0;

    for(int i = 0; i<n; i++){

      int t = 0;
      cin>>t;

      if(t==a)
        fa++;
      if(t==b)
        fb++;

    }

    float ans = float(fa/n);
    ans = ans*float(fb/n);
    printf("%.8f\n",ans );

  }

}
