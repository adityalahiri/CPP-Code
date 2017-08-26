#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_days = 0;
    cin>>num_days;

   multimap <long, long> stock_data;
   long long temp = 0;

    for(int i = 0;i<num_days; i++){
        cin>>temp;
        stock_data.insert(std::make_pair(temp,i)); // multi maps are sorted by keys automatically
    }

    long long total_amount = 0;
    cin>>total_amount;
    //initial_amount = total_amount;

    long long num_bought = 0, max_day = 0;

    map <long, long> :: iterator itr;
    // the map screws up if same value of key for two values?!

    for (itr = stock_data.begin(); itr != stock_data.end(); itr++)
    {
        max_day = itr->first * (itr->second + 1);
        long max_stocks_day_possible = 0;
        long feasible = total_amount - max_day;
        if(feasible < 0){
            //cout<<"broke!";
            max_stocks_day_possible = total_amount / itr->first;
            num_bought = num_bought + max_stocks_day_possible;
            break;
        }
        else{
            total_amount = total_amount - (itr->first * (itr->second + 1));
            num_bought = num_bought + itr-> second + 1;
        }
    }

    cout <<num_bought<< endl;

    return 0;
}
