#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_numbers = 0;

    cin>>num_numbers;

    long long array_data[num_numbers] = {0};
    long long array_sorted[num_numbers] = {0};

    for(int i = 0; i<num_numbers; i++){
        cin>>array_data[i];
        array_sorted[i]  = array_data[i];
    }

     int n = sizeof(array_data)/sizeof(array_data[0]);

     sort(array_sorted, array_sorted+n);

     long long same = 0;

     for(int i = 0; i<num_numbers; i++){
        if(array_sorted[i] == array_data[i]){
            same++;
        }
     }
     cout<<array_sorted[0]<<endl;
     cout<<num_numbers - same + 1;

    return 0;
}
