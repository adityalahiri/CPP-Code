#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

lli value[2000001] ;
lli prefix[2000001];
lli ans[1000001];

void pre_compute(){

    // odd - even, WHY NOT WORK IN even - odd CAUSE YOUR BASE CASE WAS WRONG!
    // BASE CASES FTW!
    // computing value for each number
    // max i + j sum can be 2000001
    value[0] = 0, prefix [0] = 0;
    value[1] = -1, prefix[1] = 1;

    for(lli i = 2; i <2000001; i++){

        if(i%2)
            value[i] = value[i/10] - i%10;
        else
            value[i] = value[i/10] + i%10;

        prefix[i] = prefix[i-1] + abs(value[i]);
    }

}

void find_answer(){

    ans[0] = 0;
    ans[1] = 2;

    for(lli i = 2; i < 1000001; i++){

        ans[i] = ans[i-1] + 2*(prefix[i+i] - prefix[i]) - abs(value[i+i]);

    }

}

int main(){

    lli T = 0, N = 0;
    pre_compute();
    find_answer();
    cin>>T;

    while(T--){

        cin>>N;
        cout<<ans[N]<<endl;

    }
}
