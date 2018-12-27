#include <iostream>
#include <bits/stdc++.h>

using namespace std;

std::vector<int> edges[1000];


void bfs(int src, int dest, int n){

    queue<int> q;
    q.push(src);



    int c = 0;

    q.push(src);


    while(!q.empty()){

        int temp = q.front();
        q.pop();

        vector<int> v = edges[temp];

        for(int i=0; i<v.size(); i++){

                q.push(v[i]);
                if(v[i]==dest)
                    c++;

            }

        }
        if(c!=1)
            cout<<0<<" "<<c<<endl;
        else
            cout<<1<<endl;

    }


int main() {
    int nodes,edge,queries;

    cin >>nodes>>edge>>queries;
    for(int i=0; i<edge;i++){
        int a,b;
        cin>>a>>b;
        b--;
        a--;
        edges[b].push_back(a);
    }
    for(int i=0; i<queries; i++){

        int s,d;
        cin>>s>>d;
        bfs(s-1,d-1,nodes);

    }
}
