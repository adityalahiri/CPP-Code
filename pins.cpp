#include<bits/stdc++.h>

using namespace std;

int main(){

    int num_tests = 0;
    cin>>num_tests;


    while(num_tests--){

        long long int n = 0;
        cin>>n;

        long double f = n;
        long double up = ceil(f/2);
        long long int p = n-(long long int)up;
        //cout<<up<<endl;
        unsigned long long int a= pow(10,p);
        string s = to_string(a);
        cout<<1<<" "<<s<<endl;

    }

}