#include<bits/stdc++.h>

using namespace std;

int rec(int n, vector<int> v){

    if(n<v.size())
        return v[n];
    
    return (rec(v[n-1]) + rec(v[n-2])); 

}

int main(){

    int num_tests = 0;
    cin>>num_tests;

    vector<int> v;

    v.push_back(1);
    v.push_back(2);

    long long int m = 1000000;

    for(long long int i = 2; i<m; i++){

        v.push_back((v[i-1]+v[i-2])%1000000007);

    }

    while(num_tests--){

        long long int n=0;
        cin>>n;

        cout<<rec(n,v)<<endl;

    }

}