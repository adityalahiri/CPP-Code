#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_elements = 0;
    cin>>num_elements;

    long long sum = 0;

    long long array_data[num_elements];

    for(long long i = 0;i < num_elements; i++){
        cin>>array_data[i];
        sum += array_data[i];
    }

    if(sum % 2 == 0)
        cout<<0<<endl;
    else if(num_elements == 1){
        cout<<-1<<endl;
    }
    else{
        cout<<1<<endl;
    }

    return 0;
}
