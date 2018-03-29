#include<bits/stdc++.h>

using namespace std;

int flag = 0;

typedef struct Node{

  int data;
  Node* left;
  Node* right;
  int height;

  Node(int data){

    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;

  }

}Node;

Node* insertion(Node* root, int value){

    if(root == NULL)
      return new Node(value);

    if(value <= root->data){

      root->left = insertion(root->left,value);

      if(root->height < root->left->height + 1)
        root->height = root->height + 1;

    }

    else{

      root->right = insertion(root->right,value);

      if(root->height < root->right->height + 1)
        root->height = root->height + 1;

    }

    return root;

}

void balanced(Node* root){

  if(root == NULL)
    return;

  balanced(root->left);

  if(root->left && root->right == NULL){

    if(root->left->height + 1 > 1 || root->left->height + 1 < -1)
      flag = 1;

  }

  else if(root->right && root->left == NULL){

    if((-1 - root->right->height) < -1 || (-1 - root->right->height) > 1 )
      flag = 1;

  }

  else if(root-> right && root->left){

    if((root->left->height - root->right->height) < -1 || (root->left->height - root->right->height) > 1)
      flag = 1;

  }

  balanced(root->right);

}

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    flag = 0;

    int num_data = 0;
    cin>>num_data;

    int val = 0;
    cin>>val;

    Node* root = new Node(val);

    for(int i = 1;i<num_data;i++){

      cin>>val;
      insertion(root,val);

    }

    balanced(root);

    if(flag)
      cout<<0<<endl;
    else
      cout<<1<<endl;

  }

}
