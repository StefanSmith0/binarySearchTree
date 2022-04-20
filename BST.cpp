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

node* Binary_tree::findPreviousNode(int & searchValue, node* & result, node* & prevResult) {
  if(result) {
    if(result->value == searchValue) {
      return prevResult;
    }
    else if(result->value > searchValue) {
      return findPreviousNode(searchValue, result->lchild, result);
    }
    else {
      return findPreviousNode(searchValue, result->rchild, result);
    }
  }
  else {
    return nullptr;
  }
}

void Binary_tree::findNode(int& searchValue, node*& result, node*& prevResult) {
  prevResult = findPreviousNode(searchValue, result, prevResult);
  if(prevResult) {
    if(prevResult->lchild->value == searchValue) {
      result = prevResult->lchild;
    }
    else {
      result = prevResult->rchild;
    }
  }
}

bool Binary_tree::islchild(node* child, node* parent) {
  if(parent->lchild->value == child->value) {
    return true;
  }
  return false;
}

void Binary_tree::remove(int deleteValue) {
  node* result = root;
  node* prevResult = root;
  findNode(deleteValue, result, prevResult);
  bool lchild = islchild(result, prevResult);
  if(!result->lchild && !result->rchild) { //leaf
    if(lchild) {
      prevResult->lchild = nullptr;
      delete result;
    }
  }
  else if(result->lchild && result->rchild) { //two children
    node* replacement = result->rchild;
    node* replacementL = replacement->lchild;
    while(replacementL != nullptr) {
      replacement = replacementL;
      replacementL = replacement->lchild;
    }
    int replacementValue = replacement->value;
    cout << "sawg" << replacementValue << endl;
    remove(replacementValue);
    result->value = replacement->value;
  }
  else if(result->lchild || result->rchild) { //one child
    node* child;
    if(result->lchild) {
      child = result->lchild;
    }
    else {
      child = result->rchild;
    }
    if(lchild) {
      prevResult->lchild = child;
    }
    else {
      prevResult->rchild = child;
    }
    delete result;
  }
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
