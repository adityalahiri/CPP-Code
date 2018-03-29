#include<bits/stdc++.h>

using namespace std;

void min_heapify(int data[], int array_size, int& heap_size, int index){

  int smallest = index;
  int left = 2*index;
  int right = 2*index  + 1;

  if(left <= heap_size && data[left] < data[smallest])
    smallest = left;

  if(right <= heap_size && data[right] < data[smallest])
    smallest = right;

  if(smallest != index){

    int temp = data[index];
    data[index] = data[smallest];
    data[smallest] = temp;

    min_heapify(data, array_size,heap_size,smallest);

  }

}

void build_min_heap(int data[], int array_size, int& heap_size){

  for(int i = (heap_size/2); i>=1; i--){

    min_heapify(data, array_size, heap_size, i);

  }

}

int remove_min(int data[], int& array_size, int& heap_size){

  int min = data[1];

  int temp = data[1];
  data[1] = data[heap_size];
  data[heap_size] = temp;

  heap_size--;

  min_heapify(data, array_size, heap_size, 1);

  return min;

}

void float_up(int data[], int array_size, int& heap_size, int index){

  int parent = index/2;

  if(index > 1 && data[parent] > data[index]){

    int temp = data[parent];
    data[parent] = data[index];
    data[index] = temp;

    float_up(data, array_size, heap_size,parent);

  }

}

void insert_min_heap(int data[], int array_size, int& heap_size, int value){

  heap_size++;
  data[heap_size] = value;

  float_up(data, array_size, heap_size,heap_size);

}

void display(int data[],int size){

  for(int i = 1; i<=size; i++)
    cout<<data[i]<<" ";

  cout<<endl;
}

void manual_test(){

  int data[] = {-1,1,6,7,9,4,2,13,3};
  int array_size = 8;
  int heap_size = 8;
  //min_heapify(data,5,5,2);
  build_min_heap(data,array_size,heap_size);
  display(data,array_size);
  cout<<endl;

  /*while(heap_size >= 1)
    cout<<remove_min(data,array_size,heap_size)<<endl;*/

  remove_min(data,array_size,heap_size);

  insert_min_heap(data,array_size,heap_size,1);

  cout<<remove_min(data,array_size,heap_size)<<endl;

  remove_min(data,array_size,heap_size);

  remove_min(data,array_size,heap_size);

  insert_min_heap(data,array_size,heap_size,2);

  cout<<remove_min(data,array_size,heap_size)<<endl;
  cout<<remove_min(data,array_size,heap_size)<<endl;
  //display(data,array_size);

}

int main(){

  int num_cookies = 0;
  int min_sweetness = 0;

  cin>>num_cookies>>min_sweetness;

  int data[num_cookies + 1];
  data[0] = -1;

  for(int i = 1; i <= num_cookies; i++)
    cin>>data[i];

  int array_size = num_cookies;
  int heap_size = num_cookies;

  int ans = 0;

  build_min_heap(data, array_size, heap_size);

  while(data[1] < min_sweetness){

  ans++;

  if(heap_size < 2){

    ans = -1;
    break;

  }

  int min1 = remove_min(data, array_size, heap_size);
  int min2 = remove_min(data, array_size, heap_size);


  int new_sweet = min1 + 2*min2;

  insert_min_heap(data, array_size,heap_size, new_sweet);

}

  cout<<ans<<endl;

}
