#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin>>N;

    int A[N];

    for(int i = 0;i<N; i++)
        cin>>A[i];

    int steps = 0;
    int temp = 0;

    while (true) {
        ++steps;
        bool isSorted = true;
        for (int i = 0; i < N-1; i++)
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                isSorted = false;
        }
        /*for(int i = 0;i<N; i++)
        cout<<A[i];
        cout<<endl;*/
    if (isSorted) break;
    N--;
}

cout<<steps;

    return 0;
}

