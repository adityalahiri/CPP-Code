#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, M = 0;
    cin>>N>>M;

    int data[N][M];

    for(int i = 0; i<N; i++){
        int k = 0;
        cin>>k;
        for(int j = 0;j < k; j++){
            int temp = 0;
            cin>>temp;
            data[i][temp-1] = 1; // front signified by 1. So, 2D array that has 1 at positions where number is at front with 0 indexing. ie. number 2 is represented by 1 in array, 1 by 0 and so on.
        }
    }

    float constraint = floor(log2(double(M)))+ 1.0;
    //cout<<constraint;

    if(float(N) > constraint)
        cout<<"YES"<<"yolo";

    else{

        int counter = 0, flag = 0;

        for(int i = 0; i<(1<<N); i++){// each i represents one configuration of cards
            counter = 0;
            int occurance[M]= {0}; // if a digit occurs, that is, can be seen in the ith config, I increment it.

            for(int j=0;j<N;j++){ // each J represents a card
                if(i & (1<<j)){//both are 1 means that it is in that subset which means that it is facing up. So, subsets here means cards that are facing up
                    for(int k = 0; k<N;k++){
                        for(int l = 0; l<M;l++){
                            if(data[k][l]) // kyonki seedha hai to 1 hoga
                                occurance[l]++; // Y IS OCCURENCE ALWAYS GETTING INC!
                        }
                    }
                }
                    else{
                         for(int k = 0; k<N;k++){
                        for(int l = 0; l<M;l++){
                            if(!data[k][l]) // kyonki is baar seedha nai hai to 0 hoga
                                occurance[l]++;
                        }
                    }
                    }
                }
                for(int c =0; c<M; c++){
                        if(occurance[c])
                                counter++;
                    }
                    if(counter == M){
                        flag = 1;
                        cout<<i;
                    }

            }
            if(flag)
                cout<<"YES"<<counter ;
            else
                cout<<"NO";
        }

    return 0;
}
