#pragma once

// linked type one to the next

template <typename T>
class LinkedList {
 public:
  LinkedList() : head(nullptr){};

 protected:
  typedef struct LinkedItem {
    struct LinkedItem* next;
    T data;
  } * linkedItemPtr;

 public:
  linkedItemPtr head;

  bool pushBack(T newItem) {
    if (!newItem) {
      return false;
    }

    linkedItemPtr itemPtr = new LinkedItem;

    itemPtr->data = newItem;
    itemPtr->next = nullptr;

    if (!head) {
      head = itemPtr;
      return true;
    }

    linkedItemPtr currentLinkedItem = head;
    // keep travering the next item pointer final item's next is nullptr , then the end of list has
    // been found
    while (currentLinkedItem->next != nullptr) {
      currentLinkedItem = currentLinkedItem->next;
    }

    currentLinkedItem->next = itemPtr;
    return true;
  }

  T* pop();
};
// removing front stack
template <typename T>
inline T* LinkedList<T>::pop() {
  if (!head) {
    return nullptr; // better error handling as linked list is empty
  }

  linkedItemPtr currentLinkedItem = head;

  T data = currentLinkedItem->data;
  head = currentLinkedItem->next;
  delete(currentLinkedItem);
  return &data;
}

//template <typename T>
//inline LinkedList<T>::linkedItemPtr LinkedList<T>::popEnd() {
//  if (!head) {
//    return nullptr;
//  }
//
//  linkedItemPtr currentLinkedItem = head;
//  linkedItemPtr lastLinkedItem = head;
//  while (currentLinkedItem->next != nullptr) {
//    currentLinkedItem = currentLinkedItem->next;
//  }
//
//  return linkedItemPtr();
//}
