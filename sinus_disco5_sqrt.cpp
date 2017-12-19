#include <bits/stdc++.h>
using namespace std;

const int MM = 1200000;
typedef long long lli;
lli m,n,k,p1,p2,p3,f,p[MM],cyc[MM],vis[MM];

int main(){ // remove during scanf
    // Have you solved the problem completely?

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> p[i];

    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
        lli cur = p[i];
        lli cnt = 1;
        while(cur != i)
        {
            vis[cur] = 1;
            cur = p[cur];
            cnt++;
        }
        cyc[cnt]++;
    }
    for(int i=2; i<=n; i += 2)
        if(cyc[i]%2)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
