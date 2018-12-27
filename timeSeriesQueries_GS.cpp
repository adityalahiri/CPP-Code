#include <bits/stdc++.h>
using namespace std;

long long query1(long long value, multimap <long, long> data_key_time){
    //just iterate over time! as soon as value>=v break return time
    //map::find is log n time uses red black tree.
    // map:: find price in data_key_price. Start iter from there and then get min time bec. only those times have price > v

    for (itr = data_key_time.begin(); itr != data_key_time.end(); itr++)
    {
        if(itr-> second >= value)
            return itr-> first;
    }
    return -1;
}

long long query2(long long value, multimap <long, long> data_key_time){
    multimap <long, long> :: iterator itr;
    long long max = 0;
    long long counter = 0;

    for (itr = data_key_time.begin(); itr != data_key_time.end(); itr++)
    {
        if(itr->first >= value && counter == 0){
            counter ++;
        }
        if(counter){
            if(itr->second > max){
            max = itr->second;
            }
        }
    }
    if(max == 0 ){
        return -1;
    }
    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_records, num_queries = 0;
    cin>>num_records>>num_queries;

    multimap <long, long> data_key_time;

    long long time_stamp[num_records];
    long long price_stock[num_records];

    for(int i = 0; i<num_records; i++)
        cin>>time_stamp[i];

    for(int i = 0; i<num_records; i++)
        cin>>price_stock[i];

    for(int i = 0; i<num_records; i++){
       data_key_time.insert(std::make_pair(time_stamp[i],price_stock[i]));
    }

    while(num_queries--){
        int query_type = 0;
        long long value = 0;

        cin>>query_type>>value;

        if(query_type == 1){
            cout<<query1(value, data_key_time)<<endl;
        }
        else{
            cout<<query2(value, data_key_time)<<endl;
        }

    }

    return 0;
}
