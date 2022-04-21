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

node* Binary_tree::findPreviousNode(int searchValue, node* result, node* prevResult) {
  if(result) {
    if(result->value == searchValue) {
      cout << "findPreviousNode - prevResult is: " << prevResult->value << endl;
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

void Binary_tree::findNode(int & searchValue, node* & result, node* & prevResult) {
  prevResult = findPreviousNode(searchValue, result, prevResult);
  if(prevResult) {
    cout << "findNode - prevResult is: " << prevResult->value << ", finding result..." << endl;
    if(prevResult->lchild->value == searchValue) {
      cout << "findNode - Result is lchild of prevResult" << endl;
      result = prevResult->lchild;
    }
    else if(prevResult->rchild->value == searchValue) {
      cout << "findNode - Result is rchild of prevResult" << endl;
      result = prevResult->rchild;
    }
    else {
      cout << "findNode - couldn't find result from prevResult, returning root..." << endl;
      result = root;
    }
  }
  else {
    cout << "findNode - What the fuck" << endl;
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
  cout << "remove - Target locked: " << result->value << endl;
  bool lchild = islchild(result, prevResult);
  if(!result->lchild && !result->rchild) { //leaf
    if(lchild) {
      prevResult->lchild = nullptr;
      delete result;
    }
  }
  else if(result->lchild && result->rchild) { //two children
    cout << "remove - Node has two children." << endl;
    node* replacementParent = result->rchild;
    node* replacement = replacementParent->lchild;
    cout << "remove - Finding leftmost of right substree..." << endl;
    if(replacement) {
      while(replacement->lchild) { //find leftmost of right subtree
	replacementParent = replacement;
	replacement = replacementParent->lchild;
      }
      cout << "remove - replacementParent is: " << replacementParent->value << endl;
      cout << "remove - replacement is: " << replacement->value << endl;
    }
    cout << "Last left of right found: " << replacement->value << ", swapping value to: " << result->value << endl;
    if(replacement->rchild) {
      if(replacementParent == result) {
	replacementParent->rchild = replacement->rchild;
      }
      else {
	cout << "remove - replacement has rchild, moving rchild upward..." << endl;
	replacementParent->lchild = replacement->rchild;
      }
    }
    else {
      if(replacementParent == result) {
	replacementParent->rchild = nullptr;
      }
      else {
	replacementParent->lchild = nullptr;
      }
    }
    int replacementValue = replacement->value;
    delete replacement;
    result->value = replacementValue;
    cout << "remove - Success" << endl;
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
  if(prefix.length() > 100) {
    return;
  }
  if(root) {
    cout << prefix;

    cout << (isLeft ? "├──" : "└──" );

    cout << root->value << endl;
    displayTree(true, root->lchild, prefix + (isLeft ? "|   " : "    " ));
    displayTree(false, root->rchild, prefix + (isLeft ? "|   " : "    " ));
  }
}
