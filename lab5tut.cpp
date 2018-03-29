#include<bits/stdc++.h>

using namespace std;

typedef struct Node{

  int data;
  int ls;
  int rs;
  Node* left;
  Node* right;

  Node(int data){

    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->ls = 0;
    this->rs = 0;
  }

} Node;

void insertion(Node* root,int val){

  if(root == NULL)
    return;

  if(val <= root->data){

    (root->ls)++;

    if(root->left == NULL){

      root->left = new Node(val);

    }

    else{

      insertion(root->left,val);

    }

  }

  if(val > root->data){

    (root->rs)++;

    if(root->right == NULL){

      root->right = new Node(val);

      }

    else{

      insertion(root->right,val);

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

void preOrder(Node* root){

  if(root == NULL)
    return;

  cout<<root->ls - root->rs<<" ";
  preOrder(root->left);
  preOrder(root->right);

}

int size(Node* root){

  if(root == NULL)
    return 0;

  return 1+size(root->left) + size(root->right);

}

void modpreOrder(Node* root){

  if(root == NULL)
    return;

  cout<<size(root->left)-size(root->right)<<" ";
  modpreOrder(root->left);
  modpreOrder(root->right);

}

void levelOrder(Node* root){

  if(root == NULL)
    return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();

    cout<<curr->data<<" ";

    if(curr->left)
      q.push(curr->left);

    if(curr->right)
      q.push(curr->right);

  }

}

void reverseLevelOrder(Node* root){

  vector<int> v;

  if(root == NULL)
    return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();

    v.push_back(curr->data);

    if(curr->left)
      q.push(curr->left);

    if(curr->right)
      q.push(curr->right);

  }

  for(int i = v.size()-1; i>=0; i--)
    cout<<v[i]<<" ";

}

void newlineLevelOrders(Node* root){

  if(root == NULL)
    return;

  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();

    if(curr){

      cout<<curr->data<<" ";

      if(curr->left)
        q.push(curr->left);

      if(curr->right)
        q.push(curr->right);


    }

    else{

        cout<<endl;
        if(!q.empty())
          q.push(NULL);

    }

  }

}

void postOrder(Node* root){

  if(root == NULL)
    return;

  preOrder(root->left);
  preOrder(root->right);
  //cout<<root->data<<" ";

}

void leftView(Node* root){

  if(root == NULL)
    return;

  queue<Node*> q;
  cout<<root->data<<" ";
  q.push(root);
  q.push(NULL);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();

    if(curr){

      //cout<<curr->data<<" ";

      if(curr->left)
        q.push(curr->left);

      if(curr->right)
        q.push(curr->right);


    }

    else{
        if(q.front())
        cout<<q.front()->data<<" ";

        if(!q.empty())
          q.push(NULL);

    }

  }

}

void rightView(Node* root){

  if(root == NULL)
    return;

  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();

    if(curr){

      if(q.front() == NULL)
        cout<<curr->data<<" ";

      if(curr->left)
        q.push(curr->left);

      if(curr->right)
        q.push(curr->right);


    }

    else{

        if(!q.empty())
          q.push(NULL);

    }

  }

}


}
int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int num_data = 0;
    cin>>num_data;

    int data_one = 0;
    cin>>data_one;

    int[1000000] array_data = {0};
    int index = 0;


    for(int i = 0; i<num_data-1;i++){



    }

    Node* root = new Node(data_one);

    for(int i = 0; i<num_data-1; i++){

      int curr_data = 0;
      cin>>curr_data;

      insertion(root,curr_data);

    }

    //preOrder(root);
    //cout<<endl;

    //modpreOrder(root);
    //cout<<endl;
    levelOrder(root);
    cout<<endl;

    reverseLevelOrder(root);
    cout<<endl;

    leftView(root);
    cout<<endl;

    rightView(root);
    cout<<endl;
    //newlineLevelOrders(root);
    //inOrder(root);
    //cout<<endl;
    //cout<<size(root)<<endl;
    //cout<<size(root->left)<<endl;
    //cout<<size(root->right)<<endl;

  }

}
