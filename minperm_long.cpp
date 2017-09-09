#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;

    cin>>num_times;

    while(num_times--){

        long long int n = 0;
        cin>>n;

        long long int data[n] = {0};

        for(int i = 0; i<n; i++){

            data[i] = i + 1;

        }

        if(n%2 == 0){

            for(long long int i = 0;i <= n-2; i+=2){
                long long int temp = 0;
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;

            }

    }

        else{

                for(long long int i = 0;i <= n-3; i+=2){
                long long int temp = 0;
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;

            }
            long long int i = n-2;
            long long int temp = data[i];
            data[i] = data[i+1];
            data[i+1] = temp;

        }

        for(long long int i = 0;i < n; i++){

            cout<<data[i]<<" ";

        }

        cout<<endl;

        }

    return 0;
}
