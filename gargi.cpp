#include<iostream>

using namespace std;

void printt(int a[3])
{
    for(int i=0;i<3;i++)
    {
        cout<<a[i];

    }
    cout<<endl;
}

void ttable(int n)
{
     static int a[3];

    if(n>0)
    {
        a[n-1]=0;
        ttable(a[n-1]);
        a[n-1]=1;
        ttable(a[n-1]);
    }
    else printt(a);
}

int main()
{
        int n;

        cout<<"Please enter the number of inputs."<<endl;
        cin>>n;

        ttable(n);

    return 0;

}





