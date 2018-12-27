#include<bits/stdc++.h>

using namespace std;



void merge(int left[], int right[], int ans[], int size_l, int size_r, int size_ans){

  int l = 0, r = 0, k = 0;

  while(l < size_l && r < size_r){

    if(left[l] < right[r]){

      ans[k] = left[l];
      k++;
      l++;

    }

    else{

      ans[k] = right[r];
      k++;
      r++;

    }

  }

  while(l < size_l){

    ans[k] = left[l];
    k++;
    l++;

  }

  while(r < size_r){

    ans[k] = right[r];
    k++;
    r++;

  }


}

void mergeSort(int data[], int ans[], int l, int r){

  int mid = (l+r)/2;

  if((l+r) < 2)
    return;

  int left[mid] = {0};
  int right[(l+r)-mid] = {0};

  for(int i = 0; i<mid; i++)
    left[i] = data[i];

  for(int j = 0; j<((l+r)-mid); j++)
    right[j] = data[(l+r)-mid+j];

  mergeSort(left,ans,l,mid);
  mergeSort(right,ans,mid,r);
  merge(left,right,ans,l,mid,r);

}

int main(){

  int num_data = 0;
  cin>>num_data;

  int data[num_data] = {0};
  int ans[num_data] = {0};

  for(int i = 0; i<num_data;i++){

      cin>>data[i];
      ans[i] = data[i];

  }
  mergeSort(data, ans,num_data);

  for(int j = 0; j<num_data; j++)
    cout<<ans[j]<<" ";

}
