#include <iostream>
#include "LinkedList.h"
int main() {
  float n1 = 1.0;
  float n2 = 2.0;
  float n3 = 3.0;

  LinkedList<float> linkedList;

  float t1 = 5.f;

  LinkedList<float>::LinkedItemPtr linkedItem1 = new LinkedList<float>::LinkedItem;
  float x = 1.0f;
  linkedItem1->data = &x;

  LinkedList<float>::LinkedItemPtr linkedItem2 = new LinkedList<float>::LinkedItem;
  float y = 2.0f;
  linkedItem2->data = &y;

  LinkedList<float>::LinkedItemPtr linkedItem3 = new LinkedList<float>::LinkedItem;
  float z = 3.0f;
  linkedItem2->data = &z;

  linkedList.add(&t1);
  linkedList.add(linkedItem1);
  linkedList.insertFront(linkedItem2);

  linkedList.insertAfter(linkedItem1,linkedItem3);

  std::cout << linkedList.Count() << "\n"; // should print 4

  linkedList.remove(&t1);
  linkedList.remove(linkedItem1);

  std::cout << linkedList.Count() << "\n"; // should print 2

  LinkedList<float> linkedList2;

  linkedList2.insertAfter(nullptr, linkedItem3);
  linkedList2.insertFront(linkedItem2);
  std::cout << linkedList2.Count() << "\n"; // should print 2

}
