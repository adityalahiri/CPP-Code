#include<bits/stdc++.h>

using namespace std;

std::vector<int> v;

void heapify_down(int index) {

    int inext = 0;
    while (index < v.size()) {
        inext = index;
        if (2 * index < v.size()) {
            if (v[index]>v[2*(index)]) inext = 2*index;
        }
        if (2*(index) + 1 < v.size()) {
            if (v[inext]>v[2*(index)+1]) inext = 2*(index)+1;
        }
        if (inext == index) break;
        else {
            int temp = v[index];
            v[index] = v[inext];
            v[inext] = temp;
        }
        index = inext;
    }

}

void heapify_one(int index){

  if(index  > (v.size()-2)/2)
    return;


    if(v[index] < v[2*index]){
        if(2*index+1 <= v.size()-1 && v[index] < v[2*index + 1]) return;
    }

  if(2*index+1 <= v.size()-1){
  if(v[index] > v[2*index] && v[index] > v[2*index + 1]){

    int i = 0;
    if(v[2*index] < v[2*index + 1])
      i = 2*index;
    else
      i = 2*index + 1;

    int temp = v[index];
    v[index] = v[i];
    v[i] = temp;

    heapify_one(i);

  }
}

  else if(v[index] > v[2*index]){

    int temp = v[index];
    v[index] = v[2*index];
    v[2*index] = temp;

    heapify_one(2*index);

  }

  else if(v[index] > v[2*index + 1]){

    int temp = v[index];
    v[index] = v[2*index + 1];
    v[2*index + 1] = temp;

    heapify_one(2*index + 1);

  }

}

void heapifly_iter(int index){

    while(index!=1 && v[index] < v[index/2]){
        int temp = v[index/2];
        v[index/2] = v[index];
        v[index] = temp;
        index/=2;
    }
    int inext = 0;
    while (index < v.size()) {
        inext = index;
        if (2 * index < v.size()) {
            if (v[index]>v[2*(index)]) inext = 2*index;
        }
        if (2*(index) + 1 < v.size()) {
            if (v[inext]>v[2*(index)+1]) inext = 2*(index)+1;
        }
        if (inext == index) break;
        else {
            int temp = v[index];
            v[index] = v[inext];
            v[inext] = temp;
        }
        index = inext;
    }

}

void heapify_fly(int index){//WRONG AF


  if(index == 1)
    return;

  if(v[index] > v[index/2]){

    return;

  }

  else{

    int temp = v[index/2];
    v[index/2] = v[index];
    v[index] = temp;

    heapify_fly(index/2);

  }

}

void display_min(){
  if(v.size()>=2)
  cout<<v[1]<<endl;

}


int main(){

  int num_queries = 0;
  cin>>num_queries;

  v.push_back(-1);

  while(num_queries--){

    int choice = 0;
    cin>>choice;

    if(choice == 1){

      int val = 0;
      cin>>val;

      v.push_back(val);
      heapifly_iter(v.size()-1);

    }

    else if(choice == 2){

      int val = 0;
      cin>>val;

      if(v.size() == 2){

        v.pop_back();
        continue;

      }

      int i = 0;
      for(i = 1; i<=v.size()-1;i++){

        if(v[i]==val)
          break;

      }
      int temp = v[i];
      v[i] = v[v.size()-1];
      v[v.size()-1] = temp;
      v.pop_back();
      heapify_down(i);



    }
    else{

      display_min();

    }
     /*
     cout<<"* ";
     for(int j = 1; j<v.size(); j++)
         cout<<v[j]<<" ";
      cout<<endl;*/

  }

}
