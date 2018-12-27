#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int fingers = 0;
    cin>>fingers;

    std::vector<int> length_fingers;
    std::vector<int> length_sheath;

    for(int i = 0; i<fingers; i++){

      int l = 0;
      cin>>l;

      length_fingers.push_back(l);

    }

    for(int i = 0; i<fingers; i++){

      int l = 0;
      cin>>l;

      length_sheath.push_back(l);

    }

    int front = 0, back = 0;

    for(int i = 0; i<fingers; i++){

      if(length_fingers[i] > length_sheath[i]){

        front = 1;
        break;

      }

    }


    for(int i = 0; i<fingers; i++){

      if(length_fingers[i] > length_sheath[fingers - 1 - i]){

        back = 1;
        break;

      }

    }

    if(front && back)
      cout<<"none"<<endl;
    else if(!front && !back)
      cout<<"both"<<endl;
    else if(!front)
      cout<<"front"<<endl;
    else
      cout<<"back"<<endl;

  }

}
