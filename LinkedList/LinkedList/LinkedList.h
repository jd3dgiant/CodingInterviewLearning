#pragma once

// linked type one to the nextItem

// TODO
// add in more tests in main.cpp

template <typename T>
class LinkedList {
 public:
  LinkedList() : head(nullptr), size(0){};
  ~LinkedList() {
    clearList();
  }

  typedef struct LinkedItem {
    LinkedItem* nextItem = nullptr;
    T data;
  } * LinkedItemPtr;

  // add new LinkedItem by data type T
  bool add(T newData) {
    LinkedItemPtr newItemPtr = new LinkedItem;

    newItemPtr->data = newData;
    newItemPtr->nextItem = nullptr;

    if (!head) {
      head = newItemPtr;
      size++;
      return true;
    }

    LinkedItemPtr currentTrackedItem = head;
    // keep traversing the list until the last linked item's nextItem variable pointer is nullptr.
    while (currentTrackedItem->nextItem != nullptr) {
      currentTrackedItem = currentTrackedItem->nextItem;
    }

    currentTrackedItem->nextItem = newItemPtr;
    size++;
    return true;
  }
  // add new LinkedItem by created ptr struct
  bool add(LinkedItemPtr newItem) {
    if (!newItem) {
      return false;
    }

    if (!head) {
      head = newItem;
      size++;
      return true;
    }

    LinkedItemPtr currentTrackedItem = head;
    // keep traversing the list until the last linked item's nextItem variable pointer is nullptr.
    while (currentTrackedItem->nextItem != nullptr) {
      currentTrackedItem = currentTrackedItem->nextItem;
    }

    currentTrackedItem->nextItem = newItem;
    size++;
    return true;
  }

  // remove first instance of matching data type T
  bool remove(T removeData) {
    if (!head) {
      return false;
    }

    LinkedItemPtr prevTrackedItem = head;
    if (head->data == removeData) {
      head = head->nextItem;
      // delete old head ptr of list and then point it to the
      delete (prevTrackedItem);
      size--;
      return true;
    }

    // keeping tabs on two linked list ptrs, the last known none nullptr prevTrackedItem and the
    // nextItem item in the list currentTrackedItem searching through till a data match is found and
    // updating the linked list or returning false if a data match was never found
    LinkedItemPtr currentTrackedItem = prevTrackedItem->nextItem;
    while (currentTrackedItem) {
      if (currentTrackedItem->data == removeData) {
        prevTrackedItem->nextItem = currentTrackedItem->nextItem;
        delete (currentTrackedItem);
        size--;
        return true;
      } else {
        prevTrackedItem = currentTrackedItem;
        currentTrackedItem = currentTrackedItem->nextItem;
      }
    }
    return false;
  }

  // remove matching struct ptr of LinkedItem
  bool remove(LinkedItemPtr removeItem) {
    if (!head || !removeItem) {
      return false;
    }

    if (head == removeItem) {
      head = head->nextItem;
      // delete old head ptr of list and then point it to the
      delete (removeItem);
      size--;
      return true;
    }

    LinkedItemPtr prevTrackedItem = head;
    LinkedItemPtr currentTrackedItem = prevTrackedItem->nextItem;
    while (currentTrackedItem) {
      if (currentTrackedItem == removeItem) {
        prevTrackedItem->nextItem = currentTrackedItem->nextItem;
        delete (removeItem);
        size--;
        return true;
      } else {
        prevTrackedItem = currentTrackedItem;
        currentTrackedItem = currentTrackedItem->nextItem;
      }
    }
  }

  bool insertFront(LinkedItemPtr newFrontItem) {
    if (!newFrontItem) {
      return false;
    }

    if (!head) {
      head = newFrontItem;
      size++;
      return true;
    }

    newFrontItem->nextItem = head;
    head = newFrontItem;
    size++;
    return true;
  }

  bool insertAfter(LinkedItemPtr prevItem, LinkedItemPtr newInsertItem) {
    if (!prevItem || !newInsertItem) {
      return false;
    }

    if (!head) { // assuming list is empty if head is never assigned so ignoring prevElement
      head = newInsertItem;
      size++;
      return true;
    }

    newInsertItem->nextItem = prevItem->nextItem;
    prevItem->nextItem = newInsertItem;
    size++;
    return true;
  }

  void clearList() {
    // checking if list is already empty
    if (head == nullptr) {
      return;
    }

    LinkedItemPtr currentTrackedItem = head;
    LinkedItemPtr nextTrackedItem = head;
    while (currentTrackedItem) {
      nextTrackedItem = currentTrackedItem->nextItem;
      delete(currentTrackedItem);
      currentTrackedItem = nextTrackedItem;
    }
    head = nullptr;
    size = 0;
  }

  int getSize() const {
    return size;
  }

 private:
  LinkedItemPtr head;
  int size;
};
