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
  bool search(int);
  void display();
 private:
  node* root;
  void insertNode(node*&, node*&);
  void displayTree(bool, node*, const string&);
  node* findPreviousNode(int, node*, node*);
  void findNode(int&, node*&, node*&);
  bool islchild(node*, node*);
  void inorder(node*&);
  void destroy(node*&);
};


#endif
