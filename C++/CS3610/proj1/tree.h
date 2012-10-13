#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;

/* node structure for the Binary Tree class. */
struct node {
  struct node *left;    /* pointer to left sub-tree  */
  struct node *right;   /* pointer to right sub-tree */
  int          value;   /* value of the current node */
};

class BinaryTree {
  public:
    /* default constructor (empty tree) */
    BinaryTree();
    
    /* constructor with array of values */
    BinaryTree(int n, int* values);

    /* copy constructor */
    BinaryTree(const BinaryTree &other);

    /* destructor */
    ~BinaryTree();
    
    /* function to insert a new value into the tree */
    void insert(int value);

    /* function to print the value of the root node, remove the root node 
         and update the tree */ 
    void remove();

    /* preorder traversal function */
    void preorder();

    /* postorder traversal function */
    void postorder();

    /* inorder traversal function */
    void inorder();

    /* recursive number of leaves function */
    int recursive_number_of_leaves();

    /* iterative number of leaves function */
    int iterative_number_of_leaves();


    inline bool empty() { return root == NULL; }
  private:
    /* root of the binary tree */
    struct node *root;
};

#endif
