#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_times = 0;
    cin>>num_times;

    while(num_times--){
        long long max_transactions = 0, num_days = 0;
        cin>>max_transactions>>num_days;

        long long array_data[num_days];

        for(int i = 0;i < num_days; i++){
            cin>>array_data[i];
        }

        long long dp_array[max_transactions][num_days];
        long long int transactions_done = 0;


        for(int i = 0; i<num_days; i++){
            long long max_so_far = 0;
            int day_bought = 0;

            for(int j = 0; j<i;j++){
                if((array_data[i] - array_data[j]) > max_so_far){
                    max_so_far = array_data[j] - array_data[i];
                    day_bought = j;
                }
            }
            //how to iterate over num_trans and how to check for 0 th trans uska -1 kya hoga
        }

    }

    return 0;
}
