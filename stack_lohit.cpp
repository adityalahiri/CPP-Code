#include <bits/stdc++.h>
using namespace std;
// To do - Parenthesis Stack Question
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> stk;

    int num_brackets, counter = 0;
    cin>>num_brackets;

    while(num_brackets--){
        char ch;
        cin>>ch;
        if(ch == '('){

            stk.push(ch);

        }
        else{

            if(stk.empty()){

                counter ++;

            }
            else
                stk.pop();

        }
    }
    if(!stk.empty())
        counter = 1;

    if(counter)
        cout<<"Bad";
    else
        cout<<"Good";

    /*stk.push(10);
    stk.push(20);
    stk.push(30);
    cout<<stk.top()<<"\n";
    stk.pop();
    cout<<stk.top()<<"\n";

    if(stk.empty())
        cout<<"Stack is empty";
    else
        cout<<"Stack has "<<stk.size()<<" elements";*/

    return 0;
}
