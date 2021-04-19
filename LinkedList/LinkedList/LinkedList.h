#pragma once

// linked type one to the nextItem

// TODO
// add in inserting functionality
// add in more tests in main.cpp

template <typename T>
class LinkedList {
 public:
  LinkedList() : head(nullptr){};

  typedef struct LinkedItem {
    LinkedItem* nextItem = nullptr;
    T* data = nullptr;
  } * LinkedItemPtr;

  // add new LinkedItem by data type T
  bool add(T* newData) {
    if (!newData) {
      return false;
    }

    LinkedItemPtr newItemPtr = new LinkedItem;

    newItemPtr->data = newData;
    newItemPtr->nextItem = nullptr;

    if (!head) {
      head = newItemPtr;
      return true;
    }

    LinkedItemPtr currentTrackedItem = head;
    // keep traversing the list until the last linked item's nextItem variable pointer is nullptr.
    while (currentTrackedItem->nextItem != nullptr) {
      currentTrackedItem = currentTrackedItem->nextItem;
    }

    currentTrackedItem->nextItem = newItemPtr;
    return true;
  }
  // add new LinkedItem by created ptr struct
  bool add(LinkedItemPtr newItem) {
    if (!newItem) {
      return false;
    }

    if (!head) {
      head = newItem;
      return true;
    }

    LinkedItemPtr currentTrackedItem = head;
    // keep traversing the list until the last linked item's nextItem variable pointer is nullptr.
    while (currentTrackedItem->nextItem != nullptr) {
      currentTrackedItem = currentTrackedItem->nextItem;
    }

    currentTrackedItem->nextItem = newItem;
    return true;
  }

  // remove first instance of matching data type T
  bool remove(T* removeData) {
    if (!head || !removeData) {
      return false;
    }

    LinkedItemPtr prevTrackedItem = head;
    if (head->data == removeData) {
      head = head->nextItem;
      // delete old head ptr of list and then point it to the
      delete (prevTrackedItem);
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
      return true;
    }

    LinkedItemPtr prevTrackedItem = head;
    LinkedItemPtr currentTrackedItem = prevTrackedItem->nextItem;
    while (currentTrackedItem) {
      if (currentTrackedItem == removeItem) {
        prevTrackedItem->nextItem = currentTrackedItem->nextItem;
        delete (removeItem);
        return true;
      }
      else {
        prevTrackedItem = currentTrackedItem;
        currentTrackedItem = currentTrackedItem->nextItem;
      }
    }
  }

  
  // TODO maybe this could be tracked as things are added and removed, so a full traversal is not needed
  int Count() {
    if (!head) {
      return 0;
    }

    LinkedItemPtr currentTrackedItem = head;
    int count = 1;
    while (currentTrackedItem->nextItem != nullptr) {
      count++;
      currentTrackedItem = currentTrackedItem->nextItem;
    }
    return count;
  }

 private:
  LinkedItemPtr head;
};
