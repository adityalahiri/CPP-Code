#include<bits/stdc++.h>

using namespace std;

int main(){

    int num_tests = 0;
    cin>>num_tests;

    while(num_tests--){

        int n =0 , k = 0;
        cin>>n>>k;
        map<int,int> m;
        for(int i = 0; i<n; i++){

            int t =0;
            cin>>t;

            if(m[t])
                m[t]+=1;
            else  
                m[t]=1;

        }

        if(k<=(m.size()+1)){

            cout<<-1<<endl;
            continue;
        
        }

        map<int,int> mp;

       

         for (auto iter = m.begin(); iter != m.end(); ++iter){
           k--;
           pair<int,int> p = *iter;
           if(mp[p.first])
            mp[p.first]+=1;
           else
            mp[p.first]=1;
            
            m[p.first]-=1;
        }
        if(k)
        for (auto iter = m.begin(); iter != m.end(); ++iter){
          
           pair<int,int> p = *iter;
           
           if(p.second==3){



           }


            
        }


         while(true){
           auto iter = m.begin();
           if(iter->second<=0){

               m.erase(m.begin());
               continue;

           }
           if(iter->second>=k){
                mp[iter->first]+=k;
                break;
           }
           else{

               mp[iter->first]+=iter->second;
               k-=iter->second;
               m.erase(iter);

           }
        }

        int count = 0;
        vector< pair<int,int> > v;
        for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter){

            if(count==2)
                break;
            if(iter->second>1){

                count++;
                v.push_back(make_pair(iter->first,iter->second));

            }
        }
        long long int area =1;
        
        if(v[0].second>=4)
            area = v[0].first*v[0].first;
        else
            area = v[0].first * v[1].first;


        cout<<area<<endl;

        }

    }

