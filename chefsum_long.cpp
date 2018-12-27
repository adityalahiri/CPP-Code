#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;
    cin>>num_times;

    while(num_times--){

        long long num_numbers = 0;
        cin>>num_numbers;

        multimap <long long int, long long int> data;

        for(int i = 0; i < num_numbers; i++){

            long long int temp = 0;
            cin>>temp;
            data.insert(pair <long long int, long long int> (temp, i));

        }

        multimap <long long int, long long int> :: iterator itr;

        itr = data.begin();

        cout<<itr->second + 1<<endl;
    }

    return 0;
}
