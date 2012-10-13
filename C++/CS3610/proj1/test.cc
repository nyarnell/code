#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char** argv) {
  //Do testing here
	int values[argc-2];
	for (int i = 0; i < argc-1; i++){
		values[i] = atoi(argv[i+1]);
	}
	BinaryTree btree = BinaryTree(argc-2, values);
	btree.preorder();
	cout << endl;
	btree.inorder();
	cout << endl;
	btree.postorder();
	cout << endl;
	btree.insert(8);
	btree.preorder();
	cout << endl;
	btree.inorder();
	cout << endl;
	btree.postorder();
	cout << endl;
	cout << btree.recursive_number_of_leaves() << endl;
	btree.insert(11);
	cout << btree.recursive_number_of_leaves() << endl;
	btree.insert(0);
	cout << btree.recursive_number_of_leaves() << endl;
	cout << "Testing constructor" << endl;
	BinaryTree buttree = BinaryTree();
	buttree.insert(5);
	buttree.insert(9);
	buttree.insert(3);
	buttree.insert(4);
	buttree.insert(2);
	buttree.preorder();
	cout << endl;
	buttree.inorder();
	cout << endl;
	cout << buttree.recursive_number_of_leaves() << endl;
	buttree.postorder();
	cout << endl;
  buttree.remove();
  buttree.preorder();
  cout << endl;
  cout << buttree.recursive_number_of_leaves() << endl;
  buttree = btree;
  buttree.preorder();
  cout << endl;
  buttree.inorder();
	cout << endl;
	buttree.postorder();
	cout << endl;
  cout << buttree.recursive_number_of_leaves() << endl;
  cout << buttree.iterative_number_of_leaves() << endl;
  return 0;
}
