#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 0, n =0;
    cin>>n>>k;

   std::vector<char> s;

   int counter = 0;

   while(n--)
        {
            char ch;
            cin>>ch;
            s.push_back(ch);
        }

   //for(int i = 0; i< s.size(); i++){
    int i = 0;
    while(i < s.size()){
    if(s[i+1] < s[i] && counter!=k){
        s.erase(s.begin() + i );
        i = 0;
        counter++;
    }
    else
        i++;
   }

   for(int i = 0 ; i< s.size() - (k - counter); i++)
        cout<<s[i];

    return 0;
}
