#include <bits/stdc++.h>
using namespace std;

/*int sum_subarray(int l, int r, int *pref_sum, int *array_data){

    return pref_sum[r] - pref_sum[l] + array_data[l];

}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_array = 0;
    cin>>size_array;

    int array_data[size_array];

    for(int i = 0; i<size_array; i++)
        cin>>array_data[i];

    int pref_sum[size_array];
    pref_sum[0] = array_data[0];

    for(int i =1; i<size_array; i++)
        pref_sum[i] = pref_sum[i-1] + array_data[i];

    int rem[size_array];
    int counter = 0;

    for(int i = 0; i<size_array; i++)
        rem[i] = -1;

    for( int i = 0; i<size_array; i++){

        if(rem[0] != -1){

            cout<<1<<" "<<rem[0] + 1;
            counter++;
            break;
        }

        if((rem[pref_sum[i] % size_array] != -1) && (rem[pref_sum[i] % size_array ] != i)){

            cout<<rem[pref_sum[i] % size_array ] + 2<<" "<<i + 1;
            counter++;
            break;

        }


        else{

            rem[pref_sum[i] % size_array] = i;

        }

    }

    if(rem[0] != -1 && counter == 0){

            cout<<1<<" "<<rem[0] + 1;

        }

   /* for( int i = 0; i<size_array; i++){
        cout<<pref_sum[i]<<" ";
    }
*/
    return 0;
}
