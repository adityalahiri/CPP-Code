#include <bits/stdc++.h>

using namespace std;

int main(){

  // aaabb
  // if value of odd occurence is >1 then fails

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    string s;
    cin>>s;

    int len_string = s.length();

    multimap<char,int> data;
    multimap<char,int>::iterator it;

    int ans[len_string] = {0};

    int freq[26] = {0};

    for(int i = 0; i<len_string; i++){

      char ch = s[i];
      freq[ch-97]++;
      data.insert(pair<char,int>(ch,i));

    }

    int num_odd = 0;
    int odd_char = 0;
    int non_zero = 0;

    vector<char> even_char;

    for(int i = 0; i<26; i++){

      if(freq[i]%2){

        num_odd++;
        odd_char = i;

      }

      else if(freq[i] != 0){

        even_char.push_back(char(i+97));

      }

      if(freq[i] != 0)
        non_zero++;

      //put in a set all those that occur even times

    }

    if(non_zero == 1){ // just one element

      for(int i = 1; i<=len_string; i++)
        cout<<i<<" ";

      cout<<endl;
      continue;


    }
    //cout<<num_odd;

    if(num_odd>1){

      cout<<-1<<endl;
      continue;

    }

    else if(num_odd == 1){

      char c = char(odd_char + 97);
      freq[odd_char]--;

      multimap<char,int>::iterator it = data.find(c);
      int ind1 = (*it).second;

      data.erase(it);

      ans[len_string/2] = ind1;

      if(freq[odd_char])
        even_char.push_back(c);


    }

  //  else{ //all even wala case

      // move through all characters in vector even_char, search their indices in map, put those values
      // appropriately aage and peech se in ans array counter aur n-1-counter me daalna hai

      int counter = 0;

      for(int i = 0; i<even_char.size(); i++){

        char ch = even_char[i];
        // iterate over number of times the char occurs +=2 and put indices in answer array
        int times = freq[ch-97];

        for(int j = 0; j<times; j+=2){

          // search for ch in multimap .get indices. put in ans aage peech se.increment counter

          multimap<char,int>::iterator it = data.find(ch);
          int ind1 = (*it).second;

          ans[counter] = ind1;

          data.erase(it);

          it = data.find(ch);
          int ind2 = (*it).second;

          ans[len_string-1-counter] = ind2;

          data.erase(it);

          counter++;

        }

      }




    for(int m = 0; m<len_string;m++)
      cout<<ans[m]+1<<" ";

    cout<<endl;

  }

}
