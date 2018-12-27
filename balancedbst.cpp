#include<bits/stdc++.h>

using namespace std;

// Using augmentation

typedef struct Node{

  int data;
  int nodesLeft;
  int nodesRight;
  Node* right;
  Node* left;

  Node(int data){

    this->data = data;
    this->right = NULL;
    this->left = NULL;
    this->nodesLeft = 0;
    this->nodesRight = 0;

  }
}Node;

  void insertion(Node* root, int value){

    if(value <= root->data){

      root->nodesLeft++;

      if(root->left)
        insertion(root->left, value);

      else{

        root->left = new Node(value);

      }

    }

    else{

      root->nodesRight++;

      if(root->right){

        insertion(root->right, value);

      }

      else{

        root->right = new Node(value);

      }

    }

  }

void inOrder(Node* root){

    if(root == NULL)
      return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
  }

int main(){

  int num_data = 0;
  cin>>num_data;

  int val = 0;
  cin>>val;

  Node* root = new Node(val);

  for(int i = 1; i<=num_data-1; i++){

    cin>>val;
    insertion(root,val);

  }

  inOrder(root);
  cout<<endl;

}
