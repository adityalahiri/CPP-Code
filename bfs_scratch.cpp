#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    std::vector<int> v[5];

    v[0].push_back(2);// one that comes first gets priority if same length of path!!!
    v[0].push_back(1);

    v[1].push_back(0);
    v[1].push_back(4);
    v[1].push_back(3);

    v[2].push_back(0);
    v[2].push_back(4);
    v[2].push_back(3);

    v[4].push_back(1);
    v[4].push_back(2);

    v[3].push_back(2);
    v[3].push_back(1);

    int visited[5] = {0};
    int prev[5] = {-1}; //[path]
    int dist[5] = {0};// shortest path

    queue<int> q;

    int src = 0;
    cin>>src;
    //cout<<src<<" ";

    /*int to_search = 0, c = 0;
    cin>>to_search; */ // search

    int dest = 0;
    cin>>dest;

    q.push(src);
    visited[src] = 1;
    dist[src] = 0;


    while(! q.empty()){

        int ele = q.front();
        /*if(ele == to_search)
            c = 1;*/ // search
        q.pop();

        for(int i = 0; i < v[ele].size(); i++){

            int temp = v[ele][i];
            if(!visited[temp]){

                visited[temp] = 1;
                cout<<temp<<" ";
                q.push(temp);
                prev[temp] = ele;
                dist[temp] = dist[ele] + 1; // wow. I don't care about anything else.
                // i just know I am your child so my distance would be yours  + the 1 edge bw us.
                // recursion baby


            }

        }

    }
    cout<<endl;
    cout<<"Shortest distance "<<dist[dest]<<endl;

    cout<<"Printing shortest path"<<endl; // in reverse order

    int current = dest;
    cout<<current<<" ";

    while(prev[current] != src){

        cout<<prev[current]<<" ";
        current = prev[current];

    }
    cout<<src;

    /*if(c)
        cout<<"YES";
    else
        cout<<"NO";*/ // search
}
