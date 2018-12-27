#include<bits/stdc++.h>

using namespace std;

int main(){

    int num_tests = 0;
    cin>>num_tests;

    while(num_tests--){

        int n = 0, m = 0;
        cin>>n>>m;

        vector< vector<int> > v(n);
        vector< vector<int> > ans(n);

        int one = 0;

        for(int i = 0; i<n;i++){

                string s;
                cin>>s;

            for(int j = 0; j<m; j++){

                int t = (int)s[j]-48;

                v[i].push_back(t);

                if(t==1){

                    one = 1;
                    ans[i].push_back(0);

                }
                else{

                    ans[i].push_back(-1);

                }

            }

        }

        for(int i = 0; i< n; i++){

            for(int j = 0; j<m; j++){

                if(ans[i][j]==0)
                    continue;
                
                int flag = 0;
                
                for(int k = 0; k<n;k++){

                    if(v[k][j]){

                        flag = 1;
                        break;
                    
                    } 

                }

                if(flag){

                    ans[i][j] = 1;
                    continue;

                }

                for(int k = 0; k<m; k++){

                    if(v[i][k]){

                        flag = 1;
                        break;

                    }

                }

                if(flag)
                    ans[i][j] = 1;
                else{

                    if(one)
                        ans[i][j] = 2;
                    else  
                        ans[i][j] = -1;

                }   
                    

            }

        }


        // printing

        for(int i =0; i<n; i++){

            for(int j = 0; j<m; j++)
                cout<<ans[i][j]<<" ";

            cout<<endl;

        } 

    }

}