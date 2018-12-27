#include<bits/stdc++.h>

using namespace std;

int main(){

  int n = 0, k = 0;
  cin>>n>>k;

  std::vector<int> v;

  for(int i = 0; i<n; i++){

    int t = 0;
    cin>>t;

    v.push_back(t);

  }

  int page = 1;

  int ans = 0;

  for(int i = 0; i<n; i++){

    int this_chap = v[i];
    int problem_chap = 1;

    while(this_chap > k){

      if(page>=problem_chap && page<(problem_chap+k))
          ans++;

      this_chap=this_chap - k;
      page++;
      problem_chap+=k;

    }

    if(page>=problem_chap && page<=v[i])
        ans++;
    page++;

  }

  cout<<ans<<endl;

}
