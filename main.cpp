#include <iostream>
#include "BST.h"
#include "time.h"
#include <cstring>

using namespace std;

int main() {
  Binary_tree* bst = new Binary_tree();
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    bst->insert((rand() % 999) + 1);
  }
  char input[10];
  bool running = true;
  bst->display();
  while(running) {
    cout << endl;
    cout << "Command: ";
    cin.getline(input, 10);
    if(!strcmp(input, "rm")) {
      int intInput = 0;
      cout << "Choose a number to remove: ";
      cin >> intInput;
      bst->remove(intInput);
      cin.ignore();
      cin.clear();
    }
    else if(!strcmp(input, "d")) {
      bst->display();
    }
    else if(!strcmp(input, "q")) {
      running = false;
    }
    cout << endl;
  }
  return 0;
}
