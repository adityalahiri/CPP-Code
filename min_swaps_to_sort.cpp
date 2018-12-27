#include<bits/stdc++.h>

using namespace std;

int res = 0;
int cycle_length = 0;

int binarySearchAsc(vector<int> arr, int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] < x)
            return binarySearchAsc(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearchAsc(arr, mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

void min_swaps(std::vector<int> &v, std::vector<int> &v1, int visited[], int j){

  if(visited[j])
    return;

  else{

    visited[j] = 1;
    cycle_length+=1;

    int to_go = binarySearchAsc(v1,0,v1.size()-1,v[j]);
    cout<<"to "<<to_go;
    min_swaps(v, v1,visited,to_go);

  }

}

int main(){

  std::vector<int> v;

  int n = 0;
  cin>>n;

  for(int i = 0; i<n; i++){

    int t = 0;
    cin>>t;

    v.push_back(t);

  }

  std::vector<int> v1;
  v1 = v;

  sort(v1.begin(), v1.end(), greater<int>());


  int visited[n] = {0};

  for(int i = 0; i<n; i++){


    min_swaps(v,v1,visited,i);
  //  cout<<cycle_length<<" "<<endl;
    if(cycle_length)
    res = res + cycle_length-1;

    cycle_length = 0;

  }

  cout<<res<<endl;

  }
