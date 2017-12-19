#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin>>n;
    int A[n];

    for(int i = 0; i < n; i++)
        cin>>A[i];

    sort(A, A+n);

    for(int i = 0; i < n; i++)
        cout<<A[i];
    cout<<endl;

    sort(A, A+n, greater<int>());

    for(int i =0; i<n; i++)
        cout<<A[i];



}
