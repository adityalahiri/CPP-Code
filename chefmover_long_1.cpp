#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_times = 0;
    cin>>num_times;

    while(num_times--){
        long long sum = 0;
        long long num_elements = 0;
        long long mover = 0;
        long long mean = 0;
        long long steps = 0;
        long long temp = 0;
        long long counter = 0;

        cin>>num_elements>>mover;

        long long array_data[num_elements] = {0};

        for(int i = 0; i<num_elements; i++){
            cin>>array_data[i];
            sum += array_data[i];
        }

        if(sum%num_elements){
            counter ++;
        }

        mean = sum/num_elements;

        for(int i = 0; i<num_elements-mover; i++){
            steps = steps + abs(mean - array_data[i]);
            temp = array_data[i];
            array_data[i] = mean;
            array_data[i+mover] = array_data[i+mover] + temp - mean;
        }

        for(int i =0; i<num_elements; i++){
            if(array_data[i] != mean){
                counter ++;
            }
        }
        if(counter){
            cout<<-1<<endl;
        }
        else{
            cout<<steps<<endl;
        }
    }

    return 0;
}
