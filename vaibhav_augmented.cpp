#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int height;
	int slope;
	int min;
	int max;
	int size;
	bool bst;
	node *right;
	node *left;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->height = 1;
	n->slope = 0;
	n->left = NULL;
	n->right = NULL;
	return n;

}

node *insert(node *root, int data){
	if(root == NULL) return newNode(data);
	if(data < root->data) root->left=insert(root->left, data);
	else root->right=insert(root->right, data);
	return root;
}

node *inOrderNext(node *root){
	node *t = root->right;
	while(t->left != NULL) t=t->left;
	return t;
}

node *inOrderPrev(node *root){
	node *t = root->left;
	while(t->left != NULL) t=t->right;
	return t;
}

node *search(node *root, int data){
	if(root == NULL || root->data == data) return root;
	if(data < root->data) return search(root->left, data);
	else return search(root->right, data);
}

node *deleteNode(node *root, int data){
	if(root == NULL) return root;
	if(data<root->data) root->left=deleteNode(root->left, data);
	else if(data>root->data) root->right=deleteNode(root->right, data);
	else{
		if(root->right == NULL){
			node *t = root->left;
			delete root;
			return t;
		}

		node *t = inOrderNext(root);
		root->data = t->data;
		root->right = deleteNode(root->right, t->data);
	}
	return root;
}


void setHeight(node *root){
	if(root==NULL) return;

	if(root->right == NULL && root->left==NULL) root->height = 1;
	else if(root->right == NULL && root->left != NULL){
		setHeight(root->left);
		root->height = 1 + root->left->height;
	}
	else if(root->left == NULL && root->right != NULL){
		setHeight(root->right);
		root->height = 1 + root->right->height;
	}
	else{
		setHeight(root->right);
		setHeight(root->left);
		root->height = 1 + max(root->right->height, root->left->height);
	}
}

void setSlope(node *root){
	if(root==NULL) return;
	if(root->right == NULL && root->left==NULL) root->slope = 0;
	else if(root->right == NULL){
		setSlope(root->left);
		root->slope = root->left->height;
	}
	else if(root->left == NULL){
		setSlope(root->right);
		root->slope = - root->right->height;
	}
	else{
		setSlope(root->right);
		setSlope(root->left);
		root->slope = root->left->height - root->right->height;
	}
}

void setMin(node *root){
	if(root == NULL) return;
	if(root->right == NULL && root->left==NULL) root->min = root->data;
	else if(root->right == NULL){
		setMin(root->left);
		root->min = min(root->data, root->left->min);
	}
	else if(root->left == NULL){
		setMin(root->right);
		root->min = min(root->data, root->right->min);
	}
	else{
		setMin(root->left);
		setMin(root->right);
		root->min = min(root->data, min(root->left->min, root->right->min));
	}
}

void setMax(node *root){
	if(root == NULL) return;
	if(root->right == NULL && root->left==NULL) root->max = root->data;
	else if(root->right == NULL){
		setMax(root->left);
		root->max = max(root->data, root->left->max);
	}
	else if(root->left == NULL){
		setMax(root->right);
		root->max = max(root->data, root->right->max);
	}
	else{
		setMax(root->left);
		setMax(root->right);
		root->max = max(root->data, max(root->left->max, root->right->max));
	}
}

void setBst(node *root){
	setMax(root);
	setMin(root);
	if(root == NULL) return;
	if(root->right == NULL && root->left==NULL) root->bst = true;
	else if(root->right == NULL){
		setBst(root->left);
		root->bst = root->left->bst && (root->data > root->left->max);
	}
	else if(root->left == NULL){
		setBst(root->right);
		root->bst = root->right->bst && (root->data < root->right->min);
	}
	else{
		setBst(root->left);
		setBst(root->right);
		root->bst = root->right->bst && root->left->bst && (root->data < root->right->min) && (root->data > root->left->max);
	}
}

void setSize(root){
	if(root == NULL) return;
	if(root->right == NULL && root->left==NULL) root->size = 1;
	else if(root->right == NULL){
		setSize(root->left);
		root->size = 1 + root->left->size;
	}
	else if(root->left == NULL){
		setSize(root->right);
		root->size = 1 + root->right->size;
	}
	else{
		setSize(root->left);
		setSize(root->right);
		root->size = 1 + root->left->size + root->right->size;
	}
}

void inOrder(node *root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<","<<root->bst<<" ";
		inOrder(root->right);
	}
}

int main(){
	node *root = NULL;
	root = insert(root, 50);
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 90);
    insert(root, 80);
    setBst(root);
    inOrder(root);

}
