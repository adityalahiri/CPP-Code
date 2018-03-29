#include<bits/stdc++.h>

using namespace std;

typedef struct Node{

  int value;
  Node* left;
  Node* right;
  int height;

  Node(int value){

    this->value = value;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;//initially node is added at leaf

  }

}Node;

int height(Node* root){

    if(root == NULL)
      return -1;
    else
      return root->height;

}

// Right rotate on subtree rooted at y.
struct Node* right_rotate(Node* y){

  Node* x = y->left;
  Node* t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->right), height(y->left)) + 1;
  x->height = max(height(x->right), height(x->left)) + 1;

  return x;

}

 struct Node* left_rotate(Node* x){

   Node* y = x->right;
   Node* t2 = y->left;

   y->left = x;
   x->right = t2;

   x->height = max(height(x->right), height(x->left)) + 1;
   y->height = max(height(y->right), height(y->left)) + 1;

   return y;

 }

 int get_balance(Node* root){

   return height(root->left) - height(root->right);

 }

 Node* insert(Node* root, int value){

  if(root == NULL)
    return new Node(value);

  if(value < root->value)
    root->left = insert(root->left, value);

  else if(value > root-> value)
    root->right = insert(root->right, value);

  else
    return root;

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = get_balance(root);

  // Case 1 Left Left.

  if(balance > 1 && value < root->left->value){

    root = right_rotate(root);
    return root;

  }

  // Case 2 Right right

  if(balance < -1 && value > root->right->value){

    root = left_rotate(root);
    return root;

  }

  // Case 3 left right

  if(balance > 1 && value > root->left->value){

    root->left = left_rotate(root->left);
    root = right_rotate(root);

    return root;


  }

  // Case 4 right left

  if(balance < -1 && value < root->right->value){

    root->right = right_rotate(root->right);
    root = left_rotate(root);

    return root;

  }

  return root;

 }

 Node* find_min(Node* root){

   while(root->left != NULL){

     root = root->left;

   }

   return root;

 }

 Node* deletion(Node* root, int value){

  if(root == NULL)
    return root;

  if(value < root->value)
    root->left = deletion(root->left, value);

  else if(value > root->value)
    root->right = deletion(root->right, value);

  else{

    // No child or one child Case

    if(root->left == NULL || root->right == NULL){

      Node* temp = root->left? root->left: root->right;

      if(temp == NULL){

        temp = root;
        root = NULL;

      }

      else
        *root = *temp;

      free(temp);

    }

    else{

      // 2 children Case

      Node* min_node = find_min(root->right);
      root->value = min_node->value;
      root->right = deletion(root->right, min_node->value);

    }

  }

    if(root == NULL)
      return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    if(balance > 1 && get_balance(root->left) >=0 )
      return right_rotate(root);

    if(balance > 1 && get_balance(root->left) < 0){

      root->left = left_rotate(root->left);
      return right_rotate(root);

    }

    if(balance < -1 && get_balance(root->right) <= 0)
      return left_rotate(root->right);

    if(balance < -1 && get_balance(root->right) > 0){

      root->right = right_rotate(root->right);
      return left_rotate(root);

    }

    return root;


 }

 void pre_order(Node* root){

   if(root == NULL)
    return;

  cout<<root->value<<" ";
  pre_order(root->left);
  pre_order(root->right);

 }

 void in_order(Node* root){

   if(root == NULL)
    return;

   in_order(root->left);
   cout<<root->value<<" ";
   in_order(root->right);

 }

 int main(){

   Node* root = new Node(9);

   root = insert(root, 10);
   root = insert(root, 0);
   root = insert(root, 5);
   root = insert(root, 6);
   root = insert(root, 11);
   root = insert(root, -1);
   root = insert(root, 1);
   root = insert(root, 2);

   in_order(root);
   cout<<endl;

   root = deletion(root, 10);

   in_order(root);

 }
