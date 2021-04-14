#include <iostream>
#include "LinkedList.h"
int main() {

  float n1 = 1.0;
  float n2 = 2.0;
  float n3 = 3.0;

  LinkedList<float> linkedList;

  linkedList.pushBack(n1);
  linkedList.pushBack(n2);
  linkedList.pushBack(n3);

  linkedList.pop();

  std::cout << "Hello World!\n";
}
