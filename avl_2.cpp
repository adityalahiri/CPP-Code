#include<bits/stdc++.h>

using namespace std;

int num_left_rotations = 0;
int num_right_rotations = 0;

typedef struct Node{

  int data;
  Node* left;
  Node* right;
  int height;
  int count;

  Node(int data){

    this->data = data;
    left = NULL;
    right = NULL;
    height = 0;
    count = 1;

  }

}Node;

int get_height(Node* root){

  if(root == NULL)
    return -1;
  else
    return root->height;

}

int get_balance(Node* root){

  return get_height(root->left) - get_height(root->right);

}

int set_height(Node* root){

  return 1 + max(get_height(root->right), get_height(root->left));

}

Node* left_rotate(Node* x){

  num_left_rotations+=1;

  Node* y = x->right;
  Node* b = y->left;

  y->left = x;
  x->right = b;

  x->height = set_height(x);
  y->height = set_height(y);

  return y;

}

Node* right_rotate(Node* y){

  num_right_rotations+=1;

  Node* x = y->left;
  Node* b = x->right;

  x->right = y;
  y->left = b;

  y->height = set_height(y);
  x->height = set_height(x);

  return x;

}

Node* insert(Node* root, int data){

  if(root == NULL)
    return new Node(data);

  if(data < root->data)
    root->left = insert(root->left, data);

  else if(data > root->data)
    root->right = insert(root->right, data);

  else{

    root->count += 1;
    return root;

  }

  root->height = 1 + max(get_height(root->left), get_height(root->right));

  int balance = get_balance(root);

  if(balance > 1){

    if(data > root->left->data)
      root->left = left_rotate(root->left);

    return right_rotate(root);

  }


  if(balance < -1){

    if(data < root->right->data)
      root->right = right_rotate(root->right);

    return left_rotate(root);

  }

  return root;

}

Node* get_min_leaf(Node* root){

  Node* temp = root;

  while(temp->left != NULL)
    temp = temp->left;

  return temp;

}

Node* deletion(Node* root, int data){

  if(data < root->data)
    root->left = deletion(root->left,data);

  else if(data > root->data)
    root->right = deletion(root->right,data);

  else{

  if(root == NULL)
    return root;

  if(root->count  > 1){

    root->count--;
    return root;

  }

  if(root->left){

    if(root->right){

      Node* min_node = get_min_leaf(root->right);
      root->data = min_node->data;

      deletion(min_node, min_node->data);

    }

    else{

      Node* temp = root->left;
      delete root;

      return temp;

    }

    }

    else if(root->right){

      Node* temp = root->right;
      delete root;

      return temp;

    }

    else{

      delete root;
      return NULL;

    }

  }

  if(root == NULL)
    return root;

  int height = set_height(root);

  int balance = get_balance(root);

  if(balance > 1){

    if(get_balance(root->left) < 0)
      root->left = left_rotate(root->left);

    return right_rotate(root);

  }

  if(balance < -1){

    if(get_balance(root->right) > 0)
      root->right = right_rotate(root->right);

    return left_rotate(root);

  }

  return root;

  }

  void pre_order(Node* root){

    if(root == NULL)
      return;

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);

  }

  int main(){

    Node* root = new Node(9);

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    pre_order(root);
    cout<<endl;

    cout<<num_right_rotations<<" "<<num_left_rotations<<endl;

    root = deletion(root,10);
    pre_order(root);
    cout<<endl;

    cout<<num_right_rotations<<" "<<num_left_rotations<<endl;


  }
