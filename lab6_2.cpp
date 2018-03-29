#include<bits/stdc++.h>

using namespace std;

typedef struct Node{

  long long int data;
  Node* left;
  Node* right;

  Node(long long int val){

    data = val;
    left = NULL;
    right = NULL;

  }

}Node;

queue<Node*> q;

void insertion(long long int val1, long long int val2){

  Node* curr = q.front();
  q.pop();

  if(val1 != -1){

    curr-> left = new Node(val1);
    q.push(curr->left);

  }

  else if(val1 == -1){

    curr->left = NULL;

  }

  if(val2 != -1){

    curr->right = new Node(val2);
    q.push(curr->right);

  }

  else if(val2 == -1){

    curr->right = NULL;

  }

}


void inOrder(Node* root){

  if(root == NULL)
    return;

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);

}

bool isBst(Node* root, long long int min, long long int max){

  if(root == NULL)
    return true;

  if(root->data < min || root->data > max){

    return false;

  }

  return isBst(root->left,min,root->data) && isBst(root->right,root->data,max);

}

int main(){

  long long int num_data = 0;
  cin>>num_data;

  long long int val = 0;
  cin>>val;

  if(val == -1){

    cout<<"no";
    return 0;

  }

  num_data--;

  Node* root = new Node(val);

  q.push(root);

  while(!q.empty() && num_data){

    long long int val1 = -1, val2 = -1;

    cin>>val1;
    num_data--;

    if(num_data){

      cin>>val2;
      num_data--;

    }

    insertion(val1, val2);

  }

  if(isBst(root, LONG_MIN, LONG_MAX))
    cout<<"yes";
  else
    cout<<"no";

  //inOrder(root);

}
