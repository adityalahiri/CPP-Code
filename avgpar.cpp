// even and odd pair then no need to check for av in array
// sorted
// pair ke donon numbers ke beech me Binary search for the average

#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int ans = 0;

    int num_elements = 0;
    cin>>num_elements;

    std::vector<int> v;

    for(int i = 0; i<num_elements; i++){

      int t = 0;
      cin>>t;

      v.push_back(t);

    }

    sort(v.begin(), v.end());

  /*  for(int i = 0; i<num_elements; i++)
      cout<<v[i]<<" ";
    cout<<endl;*/

    for(int i = 0; i<num_elements; i++){

      for(int j = i+1; j<num_elements; j++){

        if( (v[i]%2 == 1 && v[j]%2 == 0) || (v[i]%2 == 0 && v[j]%2 == 1) )
          continue;

        if((v[i] + v[j]) % 2 == 0 ){
        if(binary_search(v.begin() + i, v.begin() + j, ( (v[i]+v[j]) / 2 ))){

//          cout<<v[i]<<" "<<v[j]<<endl;
          ans++;
      }
    }

      }

    }

    cout<<ans<<endl;

  }

}
