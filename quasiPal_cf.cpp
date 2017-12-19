#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string data;

    cin>>data;

    long long int counter = 0;
    char ch;

    for(int i = 0; i<data.length(); i++){

        if(data[i] == '0')
            counter++;
        else
            counter = 0;

    }

    std::string to_join;

    while(counter!=0){
        counter --;
        data = '0' + data;
    }

    int flag = 0;
    for(int i =0; i<data.length()/2; i++){
        if(data[i]!=data[data.length()-i-1]){
            flag =1;
            break;
        }
    }
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";

    return 0;
}
