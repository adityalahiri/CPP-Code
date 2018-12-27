    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n,k = 0;
        cin>>n>>k;
        int counter = 0;
        int len = 0;

        std::string s;
        cin>>s;
        std::string s1(n,'\0');

        for(int i = 0;i< n-1; i++){

            if(i<n-2 && s[i+1] == s[i] && counter!=k){
                int temp = i;
                while(s[temp+1] == s[temp]){
                    temp++;
                }
                int change = temp - i + 1;
               cout<<temp;
                if(s[temp+1] < s[temp]){

                    while(change--){
                        if(counter!=k){
                        counter++;
                        //cout<<counter<<"yo"<<k<<"yo"<<i;
                        i++;
                    }
                    else if(counter == k){
                        s1[len++] = s[i];
                        break;
                    }
                    else{}
                    }

                }
                else
                    while(change--){

                    s1[len++] = s[i++];
                }
            }

            else if(s[i+1]< s[i]  && counter!=(k)){
                counter ++;
            }
            else{
                s1[len] = s[i];
                //cout<<s[i]<<" ";
                len++;
            }
            }

        s1[len++] = s[n-1];
        //cout<<len;
        int diff = k - counter;
        //cout<<diff;

        for(int j = 0; j<len-diff; j++)
            cout<<s1[j];


        return 0;
    }
