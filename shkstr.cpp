#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_data = 0;
  cin>>num_data;

  std::vector< pair<string,int> > v;

  for(int i = 0; i<num_data; i++){

    string s;
    cin>>s;

    v.push_back(make_pair(s,i));

  }

//  sort(v.begin(),v.end());

  int num_queries = 0;
  cin>>num_queries;

  map<string,vector< pair< string,int > > > m;

  while(num_queries--){

    int n = 0;
    cin>>n;

    string s;
    cin>>s;

    std::vector<pair< string,int> > starting;

    while(starting.size()==0){

      std::map<string,std::vector<pair <string,int > > >::iterator it;
      it = m.find(s);

      if(it!=m.end()){

        std::vector<pair<string,int> > vs;
        vs = it->second;

        for(int i = 0; i<vs.size(); i++){
          int flag = 0;
          string a = vs[i].first;
          int b = vs[i].second;

          if(b<n){

            starting.push_back(make_pair(a,b));
            flag = 1;
            break;

          }

        }
        if(flag)
          break;

      }

      int i = 0;
      while(i<v.size()){

        string curr = v[i].first;
        int index = v[i].second;

        if(index>=n){
          i++;
          continue;
        }
        i++;

        if(curr.compare(0, s.length(), s) == 0){
          starting.push_back(make_pair(curr,index));
        }
      }

      if(starting.size()==0)
        s.pop_back();

    }
    if(m.find(s)!=end)
      m.insert(s,starting);//store in map once you compute all that start with s

    cout<<starting[0].first<<endl;
 }
}

    //sort(starting.begin(),starting.end());
    //cout<<"Yo "<<s<<endl;
    //cout<<least<<endl;
 /*for(int i = 1; i<starting.size(); i++){

        //if(std::lexicographical_compare(starting[i].begin()+s.size()-1,starting[i].end(),least.begin()+s.size()-1,least.end()));
          //    least = starting[i];
        string lsb = least.substr(s.size());
        string rn = starting[i].substr(s.size());
        if(rn.compare(lsb) < 0)
          least = starting[i];
    }

    cout<<starting[0]<<endl;*/
