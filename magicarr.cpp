#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int num_dishes = 0;
    cin>>num_dishes;

    std::vector< pair<int, int> > sweet;
    std::vector<int> v[num_dishes];

    for(int i = 0; i<num_dishes; i++){

      int m = 0;
      cin>>m;

      for(int j = 0; j<m; j++){

        int t = 0;
        cin>>t;

        v[i].push_back(t);


      }

    }



    for(int i = 0; i<num_dishes; i++){

      
      if(v[i].size() == 1){

        pair<int, int> p = make_pair(v[i][0],v[i][0]);
        sweet.push_back(p);
        continue;

      }

      pair<int, int> p = make_pair(v[i][0],v[i][v[i].size()-1]);

      for(int j = 0; j<v[i].size()-1;j++){

        int curr_1 = v[i][j+1];
        int curr_2 = v[i][j];

        int p_1 = p.first;
        int p_2 = p.second;

        if( (curr_1 - curr_2) > (p_1 - p_2) ){

          p.first = curr_1;
          p.second = curr_2;

        }


      }

      sweet.push_back(p);

    }

    //calc sweetness now

    int max_sweet = 0;


    for(int i = 0; i<sweet.size()-1; i++){

      int mi = sweet[i].second;
      int mx = sweet[i+1].first;

      max_sweet = max_sweet + (mx-mi)*(i+1);

    }

    cout<<max_sweet<<endl;

  }

}
