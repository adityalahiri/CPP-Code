#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    string A;
    string B;

    cin>>word;
    cin>>A;
    cin>>B;

    int len = A.length();

    std::string temp(len, '0');

    int pos = 0;

    pos = word.find(A);
    word.replace(pos, std::string(A).length(), temp);

    pos = word.find(B);
    word.replace(pos, std::string(B).length(), A);

    pos = word.find(temp);
    word.replace(pos, std::string(temp).length(), B);

    cout<<word;


    return 0;
}
