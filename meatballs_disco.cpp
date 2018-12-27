#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_meatballs = 0, counter = 0;
    cin>>num_meatballs;

    long long array_data[num_meatballs] = {0};
    for(int i = 0; i<num_meatballs; i++){
        cin>>array_data[i];
    }
    if(num_meatballs > 20){
        cout<<"YES";
    }

    else if(num_meatballs == 1){
        if(array_data[0] == 0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }

    else{
        for(int i = 0; i<(1<<num_meatballs); i++){

            std::vector <int> subset;
            int xor_output = 1  ;

            for(int j = 0; j<num_meatballs; j++){
                if((i&(1<<j))){
                   subset.push_back(array_data[j]);
                }
            }

            if(subset.size()){
            for (std::vector<int>::iterator it = subset.begin() ; it != subset.end() - 1; ++it){
                if(it == subset.begin())
                    xor_output = (*it) ^ *(it + 1);
                else
                    xor_output = xor_output ^ *(it + 1);
                //cout<<"oho "<<*(it+1) ^ *it<<endl;
            }
            if(xor_output == 0){
                counter ++;
            }
    }
    }

    if(counter){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }

    return 0;
}
