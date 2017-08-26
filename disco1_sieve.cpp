#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long MM = 1000000;
    long long arr [MM] = {0};


    for(int i=1; i<MM; i++){
        for(int j=i; j<MM; j+=i){ // generating all multiples of i instead of finding out its factors
            arr[j] += i;
        }
    }

    long long num_terms = 0;
    cin>>num_terms;

    while(num_terms--){
        long long num = 0;
        cin>>num;
        cout<<arr[num]<<"\n";
    }
    return 0;
}
