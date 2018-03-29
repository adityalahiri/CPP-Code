#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int num_tunnels = 0;
    cin>>num_tunnels;

    //int data[num_tunnels] = {0};
    long double maxi = 0.0;

    for(int i = 0; i<num_tunnels; i++){
      long double t = 0;
      cin>>t;
      if(t>maxi)
        maxi = t;
      }

    int c = 0;
    int d = 0, s = 0;
    cin>>c>>d>>s;

    /*float ans = 0.0, travel_time = 0.0, each_car2_delay = 0.0;
    travel_time = d/s;
    //cout<<travel_time;
    ans = ans + data[0]*(c-1); */ // initial inevitable delay at toll 1

  /*  for(int i = 0; i<num_tunnels - 1; i++){

      float just_next_delay = float(data[i+1]);
      float car1_leaves_next_at = just_next_delay + travel_time;
      float car2_reaches_next_at = data[i] + travel_time; // would this keep accumulating

      each_car2_delay = car1_leaves_next_at - car2_reaches_next_at;

      if(each_car2_delay > 0)
        cout<<each_car2_delay<<endl;
        ans = ans + each_car2_delay*(c-1);

    }*/
    
    printf("%.6Lf\n",maxi*(c-1) );


  }

}
