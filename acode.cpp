#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string data;

    while(true){
        cin>>data;
        if(data[0] == '0'){
            break;
        }
        long long combinations[data.length() + 1] = {0};
        combinations[0] = 1;
        combinations[1] = 1;
        for(int i = 2; i<data.length() +1;i++){
            if(int(data[i-1])!=48){
                combinations[i] = combinations[i-1];
            }
            else{
                combinations[i] = 0;
            }
            if(std::stoi(std::string() + data[i-2] + data[i-1]) <=26 && std::stoi(std::string() + data[i-2] + data[i-1])>=10){
                combinations[i] += combinations[i-2];
            }
        }
        cout<<combinations[data.length()]<<endl;
    }

    return 0;
}
