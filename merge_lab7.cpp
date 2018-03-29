#include<bits/stdc++.h>

using namespace std;

//arr1 is larger accumulating array. arr1 is final_array
int merge(int final_array[], int arr2[],int size1, int size2){

    int first = 0;
    int second = 0;
    int parent = 0;

    int final_array_copy[size1];

    for(int i =0; i<size1; i++)
      final_array_copy[i] = final_array[i];

    while(first<size1 && second<size2){

      if(final_array_copy[first] < arr2[second]){

        final_array[parent] = final_array_copy[first];
        first++;
        parent++;

      }
      else{

        final_array[parent] = arr2[second];
        second++;
        parent++;

      }

    }

    while(first < size1){

      final_array[parent] = final_array_copy[first];
      first++;
      parent++;

    }

    while(second < size2){

      final_array[parent] = arr2[second];
      second++;
      parent++;

    }

    return parent;

}

int main(){

  int num_array = 0;
  int each_size = 0;

  cin>>num_array>>each_size;

  int each_data1[each_size];
  int each_data2[each_size];

  int final_array[num_array*each_size];

  int fin_size = each_size;

  for(int i = 0; i<each_size; i++)
    cin>>each_data1[i];

  for(int i = 0; i<each_size; i++)
    cin>>final_array[i];

  merge(final_array,each_data1,fin_size,each_size);
  fin_size+=each_size;

  for(int i = 0; i<num_array-2; i++){

    for(int i = 0; i<each_size; i++)
      cin>>each_data1[i];

    merge(final_array,each_data1,fin_size,each_size);
    fin_size+=each_size;

  }

  for(int i = 0; i<fin_size; i++)
    cout<<final_array[i]<<" ";

}
