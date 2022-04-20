#include <iostream>
#include "BST.h"
#include "time.h"

using namespace std;

int main() {
  Binary_tree* bst = new Binary_tree();
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    bst->insert((rand() % 999) + 1);
  }
  bst->display();
  int input;
  cout << "Choose a number to remove: ";
  cin >> input;
  bst->remove(input);

  bst->display();
  return 0;
}
