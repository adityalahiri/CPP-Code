#include <bits/stdc++.h>
using namespace std;

int arr[11][11]; // if you declare globally, then default init by 0, if in fn then garbage

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int edges;
    cin>>edges;

    for(int i = 0; i < edges; i++){
        int x,y;
        cin>>x>>y;
        arr[x][y] = 1;
        arr[y][x] = 1; // shows that graph is undirected.

    }
    //DFS

    stack<int> st;
    int a,b;
    cin>>a>>b;
    st.push(a);
    int vis[edges];
    for(int k = 0;k<edges; k++)
        vis[k] = 0;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        for(int i = 0;i<edges;i++){
            if(arr[i][cur] and( not vis[i])){
                vis[i] = 1;
                if(i == b)
                    cout<<"A is connected to B";
                st.push(i);
            }
            }
            //st.pop();
        }
    return 0;
    }



