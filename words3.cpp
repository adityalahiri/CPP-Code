#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    int upper = 0, lower = 0;
    cin>>word;
    for(int i = 0; i<word.length(); i++)
    {
        if(isupper(word[i]))
            upper++;
        else
            lower++;
    }
    if(upper>lower){
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    }
    else{
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    cout<<word;
    return 0;
}
