#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin>>n;
    int t = 0;

    vector <int> array_data;

    for(int i = 0; i<2*n; i++){
        cin>>t;
        array_data.push_back(t);

    }

    sort(array_data.begin(), array_data.end());

    int min = 100000;
    int current = 0;
    int index = 0,sum=0;

    while(array_data.size()!=2){
        min = 100000;
        index = 0,sum=0;
    for(int i = 0; i< array_data.size()-1 ; i+=1){

        current =   array_data[i+1] - array_data[i];
        if(current < min){
            index = i;
            min = current;
        }

   }
   sum = sum + abs(array_data[index] - array_data[index + 1]);
   array_data.erase(array_data.begin() + index, array_data.begin() + index + 2);
}

    cout<<sum;

    return 0;
}
