#include <bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int ans = 0;
    string str;
    cin>>str;


    if(str.length()<4){

      cout<<"normal"<<endl;
      continue;

    }

    for(int i = 0;i <= (str.length()-4);i++){

    string temp = str.substr(i,4);

    int arr[26] = {0};

    for(int k = 0; k<temp.length();k++)
      arr[temp[k] - 97]++;

    if(arr[2] == 1 && arr[7] == 1 && arr[4] == 1 && arr[5] == 1)
      ans++;

    }

    if(ans == 0)
      cout<<"normal"<<endl;
    else
      cout<<"lovely "<<ans<<endl;

  }

}
