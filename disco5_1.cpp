#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //nC3 if n>3
    //n - vertices , m- edges // n*(n-1)*(n-2)/6

    long long int n, m = 0;
    long long int u,v = 0;
    long long int subgraphs = 0;

    cin>>n>>m;

    long long array_data[n] = {0};

    for(long long int i = 0; i < n; i++)
        array_data[i] = 0;

    while(m--){

        cin>>u>>v;
        array_data[u-1]++;
        array_data[v-1]++;

    }

    for(long long int i = 0; i < n; i++){

        if(array_data[i]>=3){

            subgraphs = subgraphs + ((array_data[i] * (array_data[i] -1) * (array_data[i] -2))/6  );

        }

    }

      cout<<subgraphs%1000000007;

    return 0;
}
