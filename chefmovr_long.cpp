#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;
    cin>>num_times;

    while(num_times--){
        long long num_elements = 0;
        long long mover = 0;
        long long sum = 0;
        long long steps = 0;
        long long mean = 0;
        long long mean_local = 0;
        long long counter = 0;

        cin>>num_elements>>mover;

        long long array_numbers[num_elements] = {0};

        for(int i = 0; i<num_elements; i++){
            cin>>array_numbers[i];
            sum += array_numbers[i];
        }
        //cout<<sum<<endl;
        mean = sum/num_elements;
        //cout<<mean<<endl;
        long long array_numbers_ideal[num_elements] = {0};
        std::fill_n(array_numbers_ideal, num_elements, mean);
        //cout<<array_numbers_ideal[2]<<endl;

        for(int i = 0; i<num_elements - mover; i++){
            mean_local = floor((array_numbers[i] + array_numbers[i+mover]) / 2);
            cout<<mean_local<<endl;
            if(mean_local == mean){
                steps = steps + max(array_numbers[i], array_numbers[i+mover])  - mean;
                //cout<<steps<<endl;
                array_numbers[i] = mean_local;
                array_numbers[i + mover] = mean_local;
            }
        }

        for(int i = 0;i<num_elements;i++){
            if(array_numbers[i] != array_numbers_ideal[i]){
                counter ++;
            }
        }

        if(counter == 0){
            cout<<steps<<endl;
        }
        else{
            cout<<-1<<mean<<endl;
        }


    }

    return 0;
}
