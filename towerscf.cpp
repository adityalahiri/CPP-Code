#include<bits/stdc++.h>

using namespace std;

int main(){

  int n = 0, k = 0;
  cin>>n>>k;

  multimap<int,int> data;

  std::vector< pair<int,int> > v;

  for(int i = 0; i<n; i++){

    int t = 0;
    cin>>t;

    data.insert(make_pair(t,(i+1)));

  }

  int diff = INT_MAX;

  while(k--){

    std::multimap<int,int>::iterator it_min = data.begin();
    std::multimap<int,int>::iterator it_mi = data.begin();
    it_mi++;

    int min_ele = (*data.begin()).first;
    int min_ele_index = (*data.begin()).second;
    //cout<<min_ele<<" "<<min_ele_index<<endl;

    std::multimap<int,int>::iterator it_max = data.end();
    it_max--;
    std::multimap<int,int>::iterator it_ma = data.end();
    it_ma--;
    it_ma--;

    int max_ele = (*data.rbegin()).first;
    int max_ele_index = (*data.rbegin()).second;
    //cout<<"boo "<<(*it_mi).first<<endl;

    // CHECK RESULTING DIFF line

    if(max_ele == min_ele)
      break;

    int new_max = max(max(max_ele-1,(*it_ma).first),min_ele+1);
    int new_min = min(min(min_ele+1,(*it_mi).first),max_ele-1);

    int resulting_diff = new_max - new_min;




    //cout<<max_ele<<" "<<max_ele_index<<endl;
    //cout<<diff<<endl;
    //cout<<"yo "<<resulting_diff<<" "<<diff<<endl;
    if(resulting_diff < diff )  {
    //cout<<"yo "<<max_ele_index<<" "<<min_ele_index<<endl;
    diff = resulting_diff;

    data.erase(it_min);
    data.erase(it_max);

    v.push_back(make_pair(max_ele_index,min_ele_index));

    min_ele++;
    max_ele--;

    data.insert(make_pair(min_ele,min_ele_index));
    data.insert(make_pair(max_ele,max_ele_index));

  }

  else
    break;


  }

  cout<<(*data.rbegin()).first - (*data.begin()).first<<" "<<v.size()<<endl;

  for(int i = 0; i<v.size();i++){

    int from = v[i].first;
    int to = v[i].second;

    cout<<from<<" "<<to<<endl;

  }

}
