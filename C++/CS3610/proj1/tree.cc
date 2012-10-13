#include "tree.h"
#include <vector>

//declarations for helper functions

void _preorder(node* root);

void _inorder(node* root);

void _postorder(node* root);

int _recursive_number_of_leaves(node* root);

//helper functions

void _preorder(node* root){
  if (root == NULL){}
  else{
    cout << root->value << " ";
    if (root->left) _preorder(root->left);
    if (root->right) _preorder(root->right);
  }
}

void _inorder(node* root){
  if (root == NULL){}
  else{
	  if (root->left) _inorder(root->left);
	  cout << root->value << " ";
	  if (root->right) _inorder(root->right);
  }
}

void _postorder(node* root){
  if (root == NULL){}
  else{
    if (root->left) _postorder(root->left);
    if (root->right) _postorder(root->right);
    cout << root->value << " ";
  }
}

int _recursive_number_of_leaves(node* root){
	if ( root != NULL ){
		if ( root->left == NULL && root->right == NULL ) return 1;
		else return _recursive_number_of_leaves(root->left) + _recursive_number_of_leaves(root->right);
	}
	else return 0;
}

BinaryTree::BinaryTree(){
	root = root->left = root->right = NULL;
	//root->value = 0;
}

BinaryTree::BinaryTree(int n, int* values){
	root = NULL;
  //root->value = 0;
	for (int i = 0; i <= n; i++){
		node* ptr = new node;
  	node* parent;
  	ptr->value = values[i];
    ptr->left = ptr->right = parent = NULL;
  	if(empty()) root = ptr;
  	else {
   	  node* cur;
   	  cur = root;
   	  while(cur){
   	    parent = cur; //keeps track of the parent
   	    if(ptr->value > cur->value) cur = cur->right;
   	    else cur = cur->left;
   	  } //we've hit null, time to insert node
			if(ptr->value < parent->value) parent->left = ptr;
  	  else parent->right = ptr;
  	}
	}
}

BinaryTree::BinaryTree(const BinaryTree &other){
  std::vector<node const*> tree;
  node const* cur = other.root;
  while (cur) {
    insert(cur->value);
    if (cur->right) tree.push_back(cur->right);
    if (cur->left) cur = cur->left;
    else if (tree.empty()) break;
    else {
      cur = tree.back();
      tree.pop_back();
     }
  }
}

BinaryTree::~BinaryTree(){
  std::vector<node*> tree;
  node* cur = root;
  while (cur) {
    node* left = cur->left;
    if (cur->right) tree.push_back(cur->right);
    delete cur;
    if (left) cur = left;
    else if (tree.empty()) break;
    else {
      cur = tree.back();
      tree.pop_back();
    }
  }
}

void BinaryTree::insert(int value){
	node* ptr = new node;
  node* parent;
  ptr->value = value;
  ptr->left = ptr->right = parent = NULL;  
  if(empty()) root = ptr;
  else {
    node* cur;
    cur = root;
   	while(cur){
      parent = cur;
      if(ptr->value > cur->value) cur = cur->right;
      else cur = cur->left;
    }
		if(ptr->value < parent->value) parent->left = ptr;
 	  else parent->right = ptr;
  }
}

void BinaryTree::remove(){
  if (root == NULL){} // do nothing
  else {
    cout << "Root's value is: " << root->value << ". ";
    cout << "Removing root." << endl;
    if (root->left == NULL && root->right == NULL){ // no children
      //cout << "root->left and root->right == NULL" << endl;
      root = NULL;
    }
    else if (root->left == NULL && root->right != NULL){
      root = root->right;
    }
    else if (root->left != NULL && root->right == NULL){
      root = root->left;
    }
    else { // right and left are trees
      //cout << "root->left and root->right != NULL" << endl;
      node* curr;
      node* parent;
      curr = parent = root;
      curr = curr->left;
      //cout << "parent->value == " << parent->value << endl;
      //cout << "curr->value == " << curr->value << endl;
      //cout << "curr->right == " << curr->right << endl;
      //cout << "curr->left == " << curr->left << endl;
      if (curr->right != NULL){
        parent = parent->left;
        curr = curr->right;
        //cout << "parent->value == " << parent->value << endl;
        //cout << "curr->value == " << curr->value << endl;
      }
      while (curr->right != NULL){ //curr is the node to become the new root
        curr = curr->right;
        parent = parent->right;
      }
      if (parent->value == root->value){
        //cout << "parent value == root value" << endl;
        root->value = curr->value;
        root->left = curr->left;
        delete curr;
        //root-> left = NULL;
      }
      else{
        root->value = curr->value;
        parent->right = curr->left;
        delete curr;
      }
    }
  }
}

void BinaryTree::preorder(){
	_preorder(root);
}

void BinaryTree::inorder(){
	_inorder(root);
}

void BinaryTree::postorder(){
	_postorder(root);
}

int BinaryTree::recursive_number_of_leaves(){
	return _recursive_number_of_leaves(root);
}

int BinaryTree::iterative_number_of_leaves(){
  std::vector<node const*> remaining;
  node const* cur = root;
  int count = 0;
  while (cur){
    if (cur->right == NULL && cur->left == NULL) count++;
    if (cur->right) remaining.push_back(cur->right);
    if (cur->left) cur = cur->left;
    else if (remaining.empty()) return count;
    else {
      cur = remaining.back();
      remaining.pop_back();
    }
  }
}