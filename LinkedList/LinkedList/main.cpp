#include <iostream>
#include "LinkedList.h"
int main() {
  float n1 = 1.0;
  float n2 = 2.0;
  float n3 = 3.0;

  LinkedList<float> linkedList;

  float t1 = 1.f;

  LinkedList<float>::LinkedItemPtr linkedItem1 = new LinkedList<float>::LinkedItem;
  float x = 1.0f;
  linkedItem1->data = &x;

  linkedList.add(&t1);
  linkedList.add(linkedItem1);

  std::cout << linkedList.Count() << "\n"; // should print 2

  linkedList.remove(&t1);
  linkedList.remove(linkedItem1);

  std::cout << linkedList.Count() << "\n"; // should print 0
}
