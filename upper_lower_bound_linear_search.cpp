#include <bits/stdc++.h>

using namespace std;

int main(){

  int arr[] = {1,2,2,3,3,3,3,4,6,6,8,10,11};

  int x = 0;
  cin>>x;

  int upper_bound = 0, lower_bound = 13-1;

  // upper bound doesnt exist
  if(x>arr[12]){

    cout<<"Upper bound does not exist";
    return 0;

  }

  if(x < arr[0]){

    cout<<"Lower bound does not exist";
    return 0;

  }

  // for upper bound

  for(int i = 13 -1 ; i>=1; i--){

    if(arr[i] == x){

      upper_bound = i;
      break;

    }


    if(arr[i] > x && arr[i-1] < x){

      upper_bound = i;
      break;

    }

  }

  // for lower_bound

  for(int i = 0; i<13 - 1; i++){

    if(arr[i] == x){

      lower_bound = i;
      break;

    }


    if(arr[i] < x && arr[i+1] > x){

      lower_bound = i;
      break;

    }


}

  cout<<"upper_bound "<<arr[upper_bound]<<" "<<upper_bound<<"\n"<<"lower_bound "<<arr[lower_bound]<<" "<<lower_bound;

}
