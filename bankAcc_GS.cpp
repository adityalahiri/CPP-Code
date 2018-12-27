#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_times = 0;
    cin>>num_times;

    while(num_times--){

    long long n, k, x, d = 0;
    cin>>n>>k>>x>>d;

    long long array_data[n] = {0};

    for(int i = 0; i<n; i++){
        cin>>array_data[i];
    }

    double sum_trans = 0.0;

    for(int i = 0; i<n; i++){
        sum_trans = sum_trans + std::max(double(k), (x*array_data[i])/100.0);
    }
    if(d < sum_trans){
        cout<<"upfront"<<endl;
    }
    else{
        cout<<"fee"<<endl;
    }
}
    return 0;
}
