    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int num_friends = 0, num_dependencies = 0;
        cin>>num_friends>>num_dependencies;

        int dep_or_not[num_friends][num_friends];

        for( int i = 0; i < num_friends; i++){
            for(int j = 0;j<num_friends; j++)
                dep_or_not[i][j] = 0;
        }

        while(num_dependencies--){

            int a,b = 0;
            cin>>a>>b;

            dep_or_not[a-1][b-1]++;
            //dep_or_not[b-1][a-1]++;

        }

        int counter = 0;
        int sum = 0;
        int min =num_friends;

        for(int i = 0; i<num_friends; i++){
            sum = 0;
            for(int j = 0; j<num_friends; j++){

                if(dep_or_not[i][j])
                    sum++;

            }
            if(sum<min){
                min = sum;
            }
        }
        if(min)
            cout<<min+1;
        else
            cout<<1;
        return 0;
    }
