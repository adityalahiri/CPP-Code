#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_workers = 0;
  cin>>num_workers;

  std::vector<int> author;
  std::vector<int> translator;
  std::vector<int> both;

  std::vector<int> all_coins;
  all_coins.push_back(-1);

  for(int i = 0; i<num_workers; i++){

    int c = 0;
    cin>>c;

    all_coins.push_back(c);

  }

  for(int i = 1; i<=num_workers; i++){

    int t = 0;
    cin>>t;

    if(t==1)
      author.push_back(all_coins[i]);
    if(t==2)
      translator.push_back(all_coins[i]);
    if(t==3)
        both.push_back(all_coins[i]);

  }

  sort(author.begin(),author.end());
  sort(translator.begin(), translator.end());
  sort(both.begin(), both.end());

  int ans = INT_MAX;

  if(!both.empty())
    ans = both[0];

  if(!author.empty() && !translator.empty()){

  if(author[0] + translator[0] < ans)
    ans = author[0] + translator[0];

  }

  cout<<ans<<endl;


}
