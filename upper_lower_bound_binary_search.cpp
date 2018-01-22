
#include <bits/stdc++.h>

using namespace std;

int main(){
//             0 1 2 3 4 5 6 7 8 9 10 11 12
  int arr[] = {1,2,2,3,3,3,3,4,6,6,8,10,10,11};
  int nn=sizeof(arr)/sizeof(int);
  int x = 0;
  cin>>x;

  int upper_bound = 12;

  if(x > arr[12]){

    //cout<<"Upper Bound does not exist";
    //return 0;

  }

  if(x == arr[12]){

  //  cout<<12<<" "<<arr[12];
    //return 0;

  }
  // upper bound using binary search
  int l = 0, u = 12, mid = 0;

  while(l <= u ){

    mid = (l + u)/2;

    if(arr[mid] == x && arr[mid+1] != x){ // Will mid+1 always exist

      upper_bound = mid;
      break;

    }

    else if(arr[mid] == x && arr[mid+1] == x){

      l = mid + 1;

    }

    else if(arr[mid] < x && arr[mid+1] > x){

      upper_bound = mid+1;
      break;

    }

    else if(arr[mid] < x){

      l = mid + 1;

    }
    else if(arr[mid] > x){

      u = mid - 1;

    }

  }
  //cout<<upper_bound<<" "<<arr[upper_bound]<<endl;
  //array<int>::iterator upper;
  int upper = std::upper_bound (arr,arr + nn, x) - arr;
  //cout<<upper<<"\n";

  int lower = std::lower_bound (arr,arr + nn, x) - arr;
  cout<<lower<<"\n";
}
