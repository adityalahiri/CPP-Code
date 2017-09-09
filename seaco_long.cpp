#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;
    cin>>num_times;

    while(num_times--){

        long long int num_int, num_commands = 0;
        cin>>num_int>>num_commands;

        long long int array_original[num_int];

        for(int i = 0; i<num_int; i++)
            array_original[i] = 0;

        long long int lookup_data[num_commands][num_int] = {0};

        for(int i = 0; i<num_commands; i++){

            for(int j = 0; j<num_int; j++){

                lookup_data[i][j] = 0;

            }
        }

        for(int i = 0; i<num_commands; i++){

            int t,l,r = 0;
            cin>>t>>l>>r;

            if(t == 1){

                for(int j = l-1; j<= r-1; j++){

                    array_original[j]++;
                    lookup_data[i][j]++;

                }

               /* for(int k = 0; k<num_int; k++){

                    lookup_data[i][k] = array_original[k];

                }*/
            }
            else{
                //long long int array_copy[num_int];

                 //for(int j = 0; j<num_int; j++)
                       // array_copy[j] = array_original[j];

                for(int j = l-1; j<=r-1; j++){

                    for(int k = 0; k<num_int; k++){

                        array_original[k] = array_original[k] + lookup_data[j][k];
                        lookup_data[i][k] += lookup_data[j][k];
                        //lookup_data[i][k]++;

                    }

                }

               /* for(int m = 0; m<num_int; m++){//check this

                    lookup_data[i][m] = array_original[m] - array_copy[m];// see what to look up!

                }*/

            }

            /*for(int m = 0; m<num_commands; m++){

                for(int l = 0; l<num_int; l++)
                    cout<<lookup_data[m][l]<<" ";
                cout<<endl;

            }*/
            }

            for( int i = 0; i<num_int; i++)
                cout<<array_original[i] % (1000000000 + 7)<<" ";
            cout<<endl;
        }

    return 0;
}
