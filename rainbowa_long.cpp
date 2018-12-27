#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_times = 0;

    cin>>num_times;

    while(num_times--){
        int size = 0;
        cin>>size;

        int temp = 0;
        int counter = 0;
        int invalid = 0;

        vector <int> vec_1;
        vector <int> vec_2;

        while(size--){
            cin>>temp;
            if(temp<7 && counter == 0)
                vec_1.push_back(temp);
            if(temp<7 && counter!=0)
                vec_2.push_back(temp);
            if(temp == 7)
                counter ++;
            if(temp>7)
                invalid++;
        }
        //std::reverse(vec_2.begin(), vec_2.end()); // reversing the second vector
        sort(vec_2.begin(), vec_2.end());

        if((vec_1.size()  != vec_2.size()) || invalid){
            cout<<"no \n";
            continue;
        }
        else{ //implies sizes are at least same
            if(vec_1 == vec_2)
                cout<<"yes \n";
            else
                cout<<"no \n";
        }

    }

    return 0;
}
