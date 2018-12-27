#include<bits/stdc++.h>

using namespace std;

// Using augmentation

typedef struct Node{

  int data;
  int nodesLeft;
  int nodesRight;
  Node* height;

  Node(int data){

    this->data = data;
    this->right = NULL;
    this->left = NULL;
    this->height = 0;

  }
}Node;


Node* insertion(Node* root, int value){

  if(root == NULL){

    return new Node(value);

  }

  if(value < root->data){

    root->left = insertion(root->left,value);

    if(root->height < root->left->height + 1) // nayi ht hoti to ye hoti root->left->height + 1
      root->height = 1 + root->height;

  }

  else{

    root->right = insertion(root->right,value);

    if(root->height < root->right->height + 1) // nayi ht hoti to ye hoti root->left->height + 1
      root->height = 1 + root->height;


  }

}

void inOrder(Node* root){

    if(root == NULL)
      return;

    inOrder(root->left);
    cout<<root->data<<" "<<root->height;
    inOrder(root->right);
  }
