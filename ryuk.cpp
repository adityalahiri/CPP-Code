#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int test_cases = 0;
    cin>>test_cases;

    while(test_cases--){

        long long int num_apples, max_time;
        long long int left, right;

        cin>>num_apples>>max_time;

        long long int *apple_timings;
        apple_timings = new long long int[num_apples]; // creating array for storing each timing of num_apples apples.

        for(int i =0; i<num_apples; i++){
            cin>>apple_timings[i]; // storing elements in the apple_timings
        }

        left = 0; // initialising both left and right pointers to first element
        right = 0;

        long long int sum = 0; // stores sum of timings of apples in the current sub array
        long long int current_apples = 0; // stores number of apples for each iteration. Is compared with max_apples
        long long int max_apples = 0; // stores the output, that is, maximum apples that can be eaten in given time

        sum = apple_timings[left];
        while(left<num_apples && max_apples<num_apples ){ // have to put in a condition for best case,ie, where left never increases
            if(sum + apple_timings[(right+1)%num_apples] <= max_time){
                sum += apple_timings[(right+1)%num_apples]; //increases the sum
                right = (right + 1)%num_apples; //modular increment of right pointer
                if(right >= left){ //?
                    current_apples = right - left + 1;
                }
                else{
                    current_apples = num_apples - left + 1 + right  ;
                }
                if(current_apples > max_apples){
                    max_apples = current_apples;
                }
            }
            else{
                sum -= apple_timings[left++]; // removes the left most element from sum and increases it's pointer.
            }
        }
        cout<<max_apples<<"\n";
    }

    return 0;
}
