#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int n = 0;
    cin>>n;

    vector<pair<int,int> > v;

    while(n--){

      int l = 0, r = 0;
      cin>>l>>r;
      pair<int,int> p (l,r);
      v.push_back(p);

    }

      int q = 0;
      cin>>q;

      while(q--){

        int m = 0;
        cin>>m;

        vector<int> data;

        for(int j = 0; j<m; j++){

          int t = 0;
          cin>>t;
          data.push_back(t);

        }

        sort(data.begin(), data.end());

        int ans = 0;

        for(int j = 0; j<v.size(); j++){

          int cnt = 0;

          int left = v[j].first;
          int right = v[j].second;

          // binary search limits in data array and cnt = number of elements within those limits

          std::vector<int>::iterator low,up;
          low = std::upper_bound (v.begin(), v.end(), left); //          ^
          up = std::lower_bound (v.begin(), v.end(), right); //

          if(cnt%2)
            ans++;

        }

        cout<<ans<<endl;

      }



  }

}
