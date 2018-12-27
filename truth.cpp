#include <bits/stdc++.h>
using namespace std;

void truth(int n ){
/*if(n == 1){
        cout<<"1"<<endl<<"0"<<endl;
    }*/
    if(n>0){
        cout<<"1";
        truth(n-1);
        cout<<"0";
        truth(n-1);
    }
    else{
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int num_times = 0;
    cin>>num_times;

    truth(num_times);

    return 0;
}
