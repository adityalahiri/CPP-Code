#include <bits/stdc++.h>

using namespace std;

int main(){

    int n = 0;
    cin>>n;

    deque<int> q1;
    deque<int> q2;


    while(n--){

        int ch = 0;
        cin>>ch;

        if(ch == 1){

            int x = 0;
            cin>>x;

            q1.push_back(x);
            q2.push_front(x);
        }

        else if(ch == 2){

            int x = q1.front();
            q1.pop_front();
            q2.pop_back();
            cout<<x<<endl;

        }
        else{

            q1.swap(q2);
        }

    }

}
