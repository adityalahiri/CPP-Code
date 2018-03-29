#include<bits/stdc++.h>

using namespace std;

typedef struct Node{

  int data;
  Node* left;
  Node* right;

  Node(int data){

    this->data = data;
    this->left = NULL;
    this->right = NULL;

  }

}Node;

void insertion(Node* root, int value){

  if(value <= root->data){

    if(root->left == NULL){

      root->left = new Node(value);
      //return;
    }

    else
      insertion(root->left,value);

  }

  else{

    if(root->right == NULL){

      root->right = new Node(value);
      //return;
    }

    else
      insertion(root->right,value);

  }

}

void inOrder(Node* root){

  if(root == NULL)
    return;

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

Node* search(Node* root, int value){

  if(root == NULL)
    return NULL;

  if(root->data == value)
    return root;

  else if(value < root->data)
    search(root->left, value);

  else
    search(root->right, value);


}

Node* parent(Node* root, Node* child){

  if(child == root)
    return NULL;

  if(root->left == child || root->right == child)
    return root;

  if(child->data < root-> data){

    parent(root->left, child);

  }

  else{

    parent(root->right, child);

  }

}

Node* minRight(Node* root){

  if(root->left == NULL)
    return root;
  else
    minRight(root->left);

}

bool checkLeaf(Node* root){

  if(root->right == NULL && root->left == NULL)
    return true;

  return false;

}

void deletion(Node* root, int value){

// First, search and finding the node location of the given value to delete.

Node* loc = search(root, value);

 // 3 Cases

 // Case 1 Node of the value to be deleted is a leaf node

if(checkLeaf(loc)){

  Node* p = parent(root,loc);

  if(p->right == loc)
    p->right = NULL;
  else
    p->left = NULL;

  loc = NULL;

  //delete loc;


  return;

}

// Case 2 Node of the value to be deleted has exactly 1 child.

if(loc->right != NULL and loc->left == NULL){

  Node* p = parent(root,loc);

  if(p->right == loc)
    p->right = loc->right;
  else
    p->left = loc->right;

  loc = NULL;


}

if(loc->left != NULL and loc->right == NULL){

  Node* p = parent(root,loc);

  if(p->right == loc)
    p->right = loc->left;
  else
    p->left = loc->left;

  loc = NULL;


}

// Case 3 Node of the value to be deleted has both children.

if(loc->left && loc->right){

  Node* toSwap = minRight(loc->right);
  loc->data = toSwap->data;

  Node* p = parent(root,toSwap);

  if(p->left == toSwap)
    p->left = toSwap->right;
  else
    p->right = toSwap->right;

}

}

Node* lca(Node* root, int val1, int val2){

  //Node* loc1 = search(root, val1);
  //Node* loc2 = search(root, val2);

  if(val1 < root->data && val2 < root->data)
    lca(root->left,val1,val2);
  else if(val1 > root->data && val2 > root->data)
    lca(root->right,val1,val2);
  else // equal to case and both values on different subtrees case
    return root;

}


int main(){

  int num_data = 0;
  cin>>num_data;

  int val = 0;
  cin>>val;

  Node* root = new Node(val);

  for(int i = 1; i<num_data; i++){

    cin>>val;
    insertion(root,val);

  }

  cout<<"Inorder traversal of given BST is ";
  inOrder(root);
  cout<<endl;

  cout<<"Enter element to search"<<endl;
  cin>>val;

  Node* result = search(root,val);

  if(result)
    cout<<"Element found"<<endl;
  else
    cout<<"Element not found"<<endl;

  Node* p = parent(root,result);
  if(p)
    cout<<p->data<<endl;

  deletion(root,1);
  inOrder(root);
  cout<<endl;
  /*Node* l = lca(root,4,1);
  cout<<l->data<<endl;
  l = lca(root,7,9);
  cout<<l->data<<endl;
  l = lca(root,5,3);
  cout<<l->data<<endl;*/
}
