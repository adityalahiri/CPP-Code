#include<bits/stdc++.h>

using namespace std;

int main(){

    int n = 0;
    cin>>n;

    vector<int> v[n+1];

    for(int i = 1; i<n; i++){

        int a = 0, b = 0;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);

    }

    int d[n+1];
    int visited[n+1]= {0};

    int level = 0;
    cin>>level;
    
    stack<int> s;
    s.push(1);
    d[1] = 1;

    while(!s.empty()){


        int c = s.top();
        s.pop();
        visited[c] = 1;

        for(int j=0;j<v[c].size();j++){
            
            if(!visited[v[c][j]]){
            
                s.push(v[c][j]);
                d[v[c][j]] = d[c] + 1;

            }

        }
        
    }

    int nodes  = 0;
    for(int i =1; i<=n;i++){

        if(d[i]==level)
            nodes++;

    }

    cout<<nodes<<endl;

}