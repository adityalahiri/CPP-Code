// declare everything long long. Can include vectors, queues, etc and use them directly.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;
    cin>>num_times;

    while(num_times--){
        long long num = 0;
        cin>>num;
        long long sum = 0;

        for(int i = 1; i*i <=num; i++){
            if(num%i == 0 && i*i != num){
                sum = sum + i + num/i;
            }
            else if(num%i == 0){
                sum = sum + i;
            }
            else{
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
