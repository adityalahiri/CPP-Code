#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//typdef longlongint lli;

int main(){

    int t = 0;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        int cost1 = 0, cost2 = 0;
        string temp;
        std::vector<string> s;

        for(int i=0; i < n; i++){
                cin>>temp;
                s.push_back(temp);
            }

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if( (i%2 == 0 && j%2 == 0) || ( i%2 == 1 && j%2 ==1 ) ){

                    if(s[i][j] == 'G')
                        cost1+=3;
                    else
                        cost2+=5;
                }
                else{

                    if(s[i][j] == 'R')
                        cost1+=5;
                    else
                        cost2+=3;

                }
            }
        }

        cout<<min(cost1, cost2);
        cout<<endl;

        }
    }
