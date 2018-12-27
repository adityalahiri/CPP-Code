#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ll n = 0;
    cin>>n;

    queue<ll> petrol_orig;
    queue<ll> dist_orig;

    ll petrol[n] = {0};
    ll dist[n] = {0};

    ll ans_petrol = 0;
    ll ans_dist = 0;

    for(ll i = 0; i<n; i++){

        ll temp_petrol = 0;
        ll temp_dist = 0;

        cin>>temp_petrol;
        cin>>temp_dist;

        petrol_orig.push(temp_petrol);
        petrol[i] = temp_petrol;
        dist_orig.push(temp_dist);
        dist[i] = temp_dist;

    }

    while(petrol_orig.size()){

        ll store = 0;

        ll front_petrol_orig = petrol_orig.front();
        ll front_dist_orig = dist_orig.front();

        if(front_petrol_orig + store < front_dist_orig ){

            petrol_orig.pop();
            petrol_orig.push(front_petrol_orig);

            dist_orig.pop();
            dist_orig.push(front_dist_orig);

        }

        else{

            queue<int> success_petrol;
            queue<int> success_dist;

            int counter = 0;

            while(petrol_orig.size()>0){

                front_petrol_orig = petrol_orig.front();
                front_dist_orig = dist_orig.front();

                if(front_petrol_orig + store >= front_dist_orig){

                        store = store + petrol_orig.front() - dist_orig.front();
                        //cout<<store<<endl;

                        petrol_orig.pop();
                        success_petrol.push(front_petrol_orig);

                        dist_orig.pop();
                        success_dist.push(front_dist_orig);
                      //  cout<<"yo "<<petrol_orig.size()<<endl;
                        //cout<<"bo "<<front_dist_orig<<" "<<front_petrol_orig<<endl;

                }

                else{
                  //cout<<"yolo";
                     while(success_petrol.size()){
                    //    cout<<"yo";
                         ll t_petrol = success_petrol.front();
                         ll t_dist = success_dist.front();

                         success_petrol.pop();
                         success_dist.pop();

                         petrol_orig.push(t_petrol);
                         dist_orig.push(t_dist);

                     }
                    counter = 1;

                    break;

                }
           }

        }

    }

    ll i = 0;
    for(i = 0; i<n; i++){

      if(petrol[i] == ans_petrol && dist[i] == ans_dist)
        break;

    }
    cout<<i<<endl;

}
