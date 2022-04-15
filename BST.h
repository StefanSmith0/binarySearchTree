#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>

using namespace std;

struct node {
  int value;
  node* lchild;
  node* rchild;
};

class Binary_tree {
 public:
  Binary_tree();
  ~Binary_tree();
  void insert(int);
  void remove(int);
  void display();
  void inorder(node*&);
 private:
  node* root;
  void insertNode(node*&, node*&);
  void displayTree(bool, node*, const string&);
  void findNode(int&, node*&, node*&);
};


#endif
