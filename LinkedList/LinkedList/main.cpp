#include <iostream>
#include "LinkedList.h"

void floatLinkedListTest() {
  LinkedList<float> linkedListFloat;

  float t1 = 5.0f;

  LinkedList<float>::LinkedItemPtr linkedItem1 = new LinkedList<float>::LinkedItem;
  linkedItem1->data = 1.0f;

  LinkedList<float>::LinkedItemPtr linkedItem2 = new LinkedList<float>::LinkedItem;
  linkedItem2->data = 2.0f;

  LinkedList<float>::LinkedItemPtr linkedItem3 = new LinkedList<float>::LinkedItem;
  linkedItem2->data = 3.0;

  linkedListFloat.add(t1);
  linkedListFloat.add(linkedItem1);
  linkedListFloat.insertFront(linkedItem2);

  linkedListFloat.insertAfter(linkedItem1, linkedItem3);

  std::cout << linkedListFloat.getSize() << "\n"; // should print 4

  linkedListFloat.remove(t1);
  linkedListFloat.remove(linkedItem1);

  std::cout << linkedListFloat.getSize() << "\n"; // should print 2

  linkedListFloat.clearList();
  linkedListFloat.add(t1);
}

void structPointerLinkedListTest() {
  typedef struct pointerDataTest {
    int x = 0;
    int y = 1;
    int z = 2;
  } *pointerDataTestPtr;

  LinkedList<pointerDataTest> linkedListDataTest;


  pointerDataTest t1 = { 1,2,3 }; // setting member values for x,y,z

  LinkedList<pointerDataTest>::LinkedItemPtr linkedItem1 = new LinkedList<pointerDataTest>::LinkedItem;
  linkedItem1->data = pointerDataTest{4,5,6};

  LinkedList<pointerDataTest>::LinkedItemPtr linkedItem2 = new LinkedList<pointerDataTest>::LinkedItem;
  linkedItem1->data = pointerDataTest{ 7,8,9 };

  linkedListDataTest.add(t1);
  linkedListDataTest.add(linkedItem1);
  linkedListDataTest.insertFront(linkedItem2);

  std::cout << "Struct Pointer Linked List Test Count: " << linkedListDataTest.getSize() << "\n"; // should print 3  
}


int main() {

  floatLinkedListTest();

  structPointerLinkedListTest();
}