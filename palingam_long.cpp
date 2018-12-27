#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_times  = 0;
    cin>>num_times;

    char legend[26];
    char ch = 'a';

    for(int i = 0;i<26;i++){
            legend[i] = ch++;
        }


    while(num_times--){

        string one, two;

       cin>>one;
       cin>>two;

        int one_hash[26] = {0};
        int two_hash[26] = {0};

        for(int i =0; i<26; i++){
            for(int j = 0; j<one.length(); j++){
                if(one[j] == legend[i]){
                    one_hash[i] ++;
                }
                if(two[j] == legend[i]){
                    two_hash[i] ++;
                }
            }
        }

        long long counter = 0, local = 0;

        for(int i=0; i<26; i++){
            if(one_hash[i] > 1 && two_hash[i] == 0){
                counter ++;
            }
        }

        for(int i=0; i<26; i++){
            if(one_hash[i] == 1 && two_hash[i] == 0){
                for(int j=0; j<26; j++){
                    if(!(two_hash[j] > 0 && one_hash[j] == 0)){
                        local++;
                    }
                }
                if(local == 26){
                    counter++;
                }
            }
        }

        if(counter){
            cout<<"A"<<endl;
        }
        else{
            cout<<"B"<<endl;
        }

    }

    return 0;
}
