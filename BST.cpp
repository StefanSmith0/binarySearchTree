#include "BST.h"

using namespace std;

Binary_tree::Binary_tree() {
  root = NULL;
  cout << "Tree initialized" << endl;
}

void Binary_tree::insert(int newInt) {
  node* newNode = new node();
  newNode->value = newInt;
  newNode->lchild = nullptr;
  newNode->rchild = nullptr;
  insertNode(root, newNode);
}

void Binary_tree::findNode(int & searchValue, node* & current, node* & prev) {
  if(current) {
    if(current->value == searchValue) {
      
      return;
    }
    else if(current->value > searchValue) {
      findNode(searchValue, current->lchild, current);
    }
    else {
      findNode(searchValue, current->rchild, current);
    }
  }
}

void Binary_tree::remove(int deleteValue) {
  node* result = root;
  node* prevResult = root;
  findNode(deleteValue, result, prevResult);
  cout << result->value << endl;
  cout << prevResult->value << endl;
}

void Binary_tree::insertNode(node* & root, node* & newNode) {
  if(!root) {
    root = newNode;
  }
  else if(root->value > newNode->value) {
    insertNode(root->lchild, newNode);
  }
  else {
    insertNode(root->rchild, newNode);
  }
}

void Binary_tree::display() {
  string prefix = "";
  displayTree(false, root, prefix);
  cout << endl;
}

void Binary_tree::inorder(node* & root) {
  if(root) {
    inorder(root->lchild);
    cout << root->value << ", ";
    inorder(root->rchild);
  }
}

//Prints the tree as a horizontal tree - printBT by Adrian Schneider (modified)
void Binary_tree::displayTree(bool isLeft, node* root, const string &prefix) {
  if(root) {
    cout << prefix;

    cout << (isLeft ? "├──" : "└──" );

    cout << root->value << endl;
    displayTree(true, root->lchild, prefix + (isLeft ? "|   " : "    " ));
    displayTree(false, root->rchild, prefix + (isLeft ? "|   " : "    " ));
  }
}
