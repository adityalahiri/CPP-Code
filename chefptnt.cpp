#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0, m = 0, x = 0, k = 0;
    cin>>n>>m>>x>>k;

    string str;
    cin>>str;

    int odd = 0, even = 0;

    for(int i = 0; i<k; i++){

      if(str[i] == 'E')
        even++;

      else
        odd++;

    }

    //cout<<even<<" "<<odd<<endl;

    for(int i = 1; i<=m; i++){

      if(i%2){

        if(odd >= x){

          odd-=x;
          n-=x;
          //cout<<"yo "<<n<<endl;

        }
        else if(odd > 0){

          n-=odd;
          odd = 0;

        }

      }

      else{

        if(even >= x){

          even-=x;
          n-=x;

        }
        else if(even > 0){

          n-=even;
          even = 0;

        }

      }

      if(n<=0)
        break;

    }

    if(n<=0)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;

  }

}
