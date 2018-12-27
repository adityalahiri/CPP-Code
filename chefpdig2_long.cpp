#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;
    cin>>num_times;

    while(num_times--){

        //unsigned long long int N = 0,j = 0; // take input as to_string
        std::string data;
        cin>>data;

        int counter[10];

        for(int i=0;i<10;i++){
            counter[i] = 0;
        }

        /*while(j){
            int temp = j%10;
            j= j/10;
            counter[temp]++;
        }*/
        for(unsigned long long i = 0; i  < data.length(); i++){

            //char temp = (data[i]);
            //int t = temp - 48;
            //cout<<t<<endl;
            int temp = data[i] - 48;
            counter[temp]++;
            //cout<<counter[temp];
        }


       for(int i = 6; i<=8; i++){
            if(i == 6){
                    for(int k = 5; k<=9; k++){
                         if(counter[i] && counter[k] && i!=k){
                         //cout<<char(atoi(strcat(std::to_string(i), std::to_string(k))));
                            cout<<char(stoi(std::to_string(i) + std::to_string(k)));
                        }
                        else if(counter[i]>=2 && (i == k))
                            cout<<char(stoi(std::to_string(i) + std::to_string(k))) ;
                        else
                            {};
            }
        }
            else{
            for(int k = 0; k<=9; k++){
                if(counter[i] && counter[k] && i!=k){
                    //cout<<char(atoi(strcat(std::to_string(i), std::to_string(k))));
                    cout<<char(stoi(std::to_string(i) + std::to_string(k))) ;
                }
                else if(counter[i]>=2 && i == k)
                            cout<<char(stoi(std::to_string(i) + std::to_string(k))) ;
                        else
                            {};
            }
        }
       }
    if(counter[9] && counter[0])
        cout<<"Z";
     cout<<endl;
}
    return 0;
}
