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

void get_min_leaf(int data[], int& heap_size){

  int min = INT_MAX;
  int min_index = (heap_size/2) + 1;

  for(int i = (heap_size/2) + 1; i<=heap_size; i++){

    if(data[i] < min){

      min = data[i];
      min_index = i;

    }

  }

  int temp = data[(heap_size/2) + 1];
  data[(heap_size/2)+1] = data[min_index];
  data[min_index] = temp;

}

int main(){

  int num_data = 0;
  cin>>num_data;

  int data[num_data + 1];
  data[0] = -1;

  int val = 0;
  int heap_size = 0;

  for(int i = 1; i<=num_data; i++ ){

    cin>>val;

    insert_min_heap(data, num_data, heap_size, val);
    get_min_leaf(data, heap_size);

    if(heap_size%2)
      printf("%.1f\n",float(data[(heap_size/2) + 1]) );
    else
      printf("%.1f\n",(data[(heap_size/2) + 1] + data[heap_size/2]) / 2.0 );

  }


}
