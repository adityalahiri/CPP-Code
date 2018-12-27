#include<bits/stdc++.h>

using namespace std;

int main(){

  int n1 = 0, n2 = 0;
  cin>>n1>>n2;

  // union int diff

  int freq1[26] = {0};
  int freq2[26] = {0};

  for(int i = 0; i<n1; i++){

    char ch;
    cin>>ch;

    freq1[ch-97]++;

  }

  for(int i = 0; i<n2; i++){

    char ch;
    cin>>ch;

    freq2[ch-97]++;

  }

  // for union non zero elements of freq1 + freq 2

  for(int i = 0; i<26; i++){

    if(freq1[i] != 0 || freq2[i] != 0)
      cout<<char(i+97);

  }

  cout<<endl;

  for(int i = 0; i<26; i++){

    if(freq1[i] != 0 && freq2[i] != 0)
      cout<<char(i+97);

  }

  cout<<endl;

  for(int i = 0; i<26; i++){

    if(freq1[i] != 0 && freq2[i] == 0)
      cout<<char(i+97);

  }

  cout<<endl;

}
