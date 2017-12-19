#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n = 0;

    cin>>n;

    long long temp_data = (n*(n-1))/2;

    if(n%2){

         cout<<temp_data;

    }
    else{

        cout<<((n-2)/2 + temp_data);

    }

    return 0;
}

