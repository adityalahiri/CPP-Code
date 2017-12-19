# include <iostream>
# include <bits/stdc++.h>

using namespace std;

typedef long long lli;

int main(){

    lli num_tests = 0, length_array = 0, len_arr = 0;
    int temp = 0;
    cin>>num_tests;

    while(num_tests--){

        cin>>length_array;
        len_arr = length_array;
        std::vector<int> v;
        std::queue<int> pop_v;
        //std::vector<int> dist_v;
        int ans[length_array] = {0};

        while(len_arr--){

            cin>>temp;
            v.push_back(temp);

        }

        lli k = (length_array/2) + 1;



        if(length_array == 1){
            cout<<0<<endl;
            cout<<v[0]<<endl;
            continue;
        }

        if(length_array == 3){

            //todo // finding ham distance manually after swaps
            ans[0] = v[1];
            ans[1] = v[2];
            ans[2] = v[0];
            int c = 0;
            for(int i = 0; i < 3; i++){
                if(ans[i] != v[i])
                    c++;
            }
            cout<<c<<endl;
            for(int i = 0; i<3; i++)
                cout<<ans[i]<<" ";
            cout<<endl;
            continue;

        }

        for(lli i =0; i<length_array; i++){

            pop_v.push(v[(k+i)%length_array]);

        }

       lli c = 0;

       while(pop_v.size()){

            if(v[c] != pop_v.front()){

                ans[c] = pop_v.front();
                pop_v.pop();
                c++;
            }

            else{

                int temp = pop_v.front();
                pop_v.push(temp);
                pop_v.pop();

            }

       }


        cout<<length_array<<endl;

        for(lli i = 0; i < length_array; i++)
            cout<<ans[i]<<" ";
        cout<<endl;

       /* std::reverse(v.begin(), v.end());

        if(length_array%2){

            temp = v[length_array/2];
            v[length_array/2] = v[length_array-1];
            v[length_array-1] = temp;

        }

        cout<<length_array<<endl;

        for(lli i = 0; i < length_array; i++)
            cout<<v[i]<<" ";

        cout<<endl;
*/

    }

}
