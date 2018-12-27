#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    while (!cin.eof()){

        int min_matches = 0, i =0;
        int score_chef = 0, score_opp = 0;

        for(i = 0; i < 20; i++){
            //updating scores
            if(i%2 == 0){ // signifies a chef move

                if(s[i] == '1')
                    score_chef++;

            }

            else{

                if(s[i] == '1')
                    score_opp++;

            }

            if(score_chef > score_opp && i > 9 &&  i%2 == 1 ){
                cout<<"TEAM-A "<<i+1<<endl; // instand death win for chef
                break;
            }

            if(score_chef < score_opp && i > 9 ){
                 cout<<"TEAM-B "<<i+1<<endl; // instand death win for opp
                break;
            }

            if(score_chef > score_opp && i<10){ // unassailable lead for chef

                if(score_chef - score_opp > ( (10-i)/2.0 ) ){
                    cout<<"TEAM-A "<<i+1<<endl;
                    break;
                }

            }

            if(score_opp > score_chef && i<10){ // unassailable lead for opp

                if(score_opp - score_chef >= ceil( (10-i)/2.0 ) ){
                     cout<<"TEAM-B "<<i+1<<endl;
                    //cout<<score_opp - score_chef<<" "<<i<< " "<<ceil((10-i)/2.0 ) ;
                    break;
                }

            }


        if(i==19){
            cout<<"TIE"<<endl;
            break;
        }
      }
      cin>>s;
    }
}
