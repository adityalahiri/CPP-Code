#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin>>input;

    char legend[10];
    char digit = '0';

    int freq[10] = {0};

    for(int i = 0; i<10; i++){
        legend[i] = digit++;
    }

    for(int j = 0; j<10; j++){
        for(int i = 0; i<input.length(); i++){
            if(input[i] == legend[j] ){
                freq[j]++;
            }
        }
    }
    int counter = 0;
    int n = freq[0];
    for(int i = 1; i<10; i++){
        if(freq[i] != n){
            counter++;
        }
    }

    if(counter){
        cout<<0;
    }
    else{
        cout<<1;
    }

    return 0;
}
