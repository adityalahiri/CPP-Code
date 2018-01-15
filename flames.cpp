#include <bits/stdc++.h>

using namespace std;

int main(){

  string name1, name2;
  cin>>name1;
  cin>>name2;

  transform(name1.begin(), name1.end(), name1.begin(), :: tolower);
  transform(name2.begin(), name2.end(), name2.begin(), :: tolower);

  int freq1[26] ={0};
  int freq2[26] = {0};

  for(int i = 0; i<name1.length(); i++)
    freq1[name1[i] - 97]++;

  for(int i = 0; i<name2.length(); i++)
    freq2[name2[i] - 97]++;


  for(int i = 0; i<26; i++){

    if(freq1[i] != 0 && freq2[i] != 0){

      freq1[i]--;
      freq2[i]--;

    }

  }

  int iter = 0;

  for(int i = 0; i<26; i++)
    iter = iter + freq1[i] + freq2[i];

  //cout<<iter;

  // flames part

  int flames[6] = {0};
  int begin_loc = 0;
  int current_loc = 0;

  for(int i = 0; i<5; i++){

    current_loc = begin_loc;

    int count = 0;
    //int flag  = 0;

    while(count < iter - 1){



      if(flames[current_loc] == 1){
        current_loc = (current_loc + 1) % 6;

      }
      else{
        /*if(flag)
          count++;
        else
          flag = 1;*/
        current_loc = (current_loc + 1) % 6;

        while(flames[(current_loc) % 6] == 1){
          current_loc = (current_loc + 1) % 6;
      }
      count++;
        //if(flames[current_loc] == 1)
        //  continue; // why this gives inifinite loop


      }

  }
  //cout<<current_loc<<" ";
  flames[current_loc] = 1;

  begin_loc = (current_loc + 1)%6;
  //cout<<"b"<<begin_loc<<" ";
  }

  int i = 0;

  for(i = 0; i<6; i++){
    if(flames[i] == 0)
      break;

  }
  //cout<<endl;

  cout<<name1.length()<<" "<<name2.length()<<" "<<iter<<" ";
  if(i == 0)
   cout<<"f";
  if(i == 1)
    cout<<"l";
  if(i == 2)
    cout<<"a";
  if(i == 3)
    cout<<"m";
  if(i == 4)
    cout<<"e";
  if(i == 5)
    cout<<"s";

  cout<<endl;


}
