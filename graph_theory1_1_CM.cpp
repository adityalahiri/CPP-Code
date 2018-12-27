#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, degree = 0,n_copy = 0, sum = 0;
    cin>>n;
    n_copy = n;

    while(n_copy--){

        int temp = 0;
        cin>>temp;
        sum += temp;

    }

    if(n == (sum - sum/2 + 1))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
