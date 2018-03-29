#include<bits/stdc++.h>

using namespace std;

typedef struct Node{

  int data;
  int min;
  int max;
  int height;
  int size;
  int slope;

  bool bst;

  Node* left;
  Node* right;

  Node(int val){

    data = val;
    min = val;
    max = val;
    height = 1;
    size = 1;
    slope = 0;

    bst = true;


    left = NULL;
    right = NULL;

  }

}Node;


Node *insertion(Node* root, int val){

  if(root == NULL)
    return new Node(val);

  if(val < root->data)
    root->left = insertion(root->left, val);

  else
    root->right = insertion(root->right, val);

  return root;

}

Node *search(Node *root, int data){
	if(root == NULL || root->data == data) return root;
	if(data < root->data) return search(root->left, data);
	else return search(root->right, data);
}
