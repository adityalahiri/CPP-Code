#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){

    lli num_tests;
    cin>>num_tests;

    while(num_tests--){

      lli N = 0, A = 0;
      cin>>N>>A;

      if(A == 1 && N == 1)
        cout<<1<<" "<<"a";

      else if(A == 1){

        cout<<N<<" ";
        for(lli i = 0; i<N; i++)
          cout<<"a";

      }

      else if(A == 2){

        if(N == 1)
          cout<<1<<" "<<"a";
        else if(N == 2)
          cout<<1<<" "<<"ab";
        else if(N == 3)
          cout<<2<<" "<<"abb";
        else if(N == 4)
          cout<<2<<" "<<"aabb";
        else if(N == 5)
          cout<<3<<" "<<"aaabb";
        else if(N == 6)
          cout<<3<<" "<<"aaabbb";
        else if(N == 7)
          cout<<3<<" "<<"aaababb";
        else if(N == 8)
          cout<<3<<" "<<"aaababbb";
        else{

          cout<<4<<" ";

          char c[7] = "babbaa";
          lli k = N/6;

          for(lli i = 0; i<k; i++)
            cout<<c;

          k = N%6;

          for(lli i = 0; i<k;i++)
            cout<<c[i];



        }

      }

      else{

      cout<<1<<" ";

      lli k = N/3;

			for(lli i=0; i<k; i++)
				cout<<"abc";

      if(N%3 == 1)
				cout<<"a";
			else if(N%3 == 2)
				cout<<"ab";

      }

      cout<<endl;

    }


}
