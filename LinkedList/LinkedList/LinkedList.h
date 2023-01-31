#pragma once

// Single Link List

// TODO
// add in more tests in main.cpp

template <typename T>
class LinkedList {
 public:
  LinkedList() : head(nullptr), tail(nullptr), size(0){};
  LinkedList(T item) : head(nullptr), tail(nullptr), size(0){
    head = new LinkedItem{ item, nullptr };
    tail = head;
  };

  ~LinkedList() {
    clearList();
  }

  typedef struct LinkedItem {
    T data;
    LinkedItem* nextItem = nullptr;
  } * LinkedItemPtr;

  // add new LinkedItem by data type T
  bool add(T newData) {
    LinkedItemPtr newItemPtr = new LinkedItem{ newData, nullptr };

    if (!head) {
      head = newItemPtr;
      tail = head;
      ++size;
      return true;
    }

    tail->nextItem = newItemPtr;
    tail = newItemPtr;
    LinkedItemPtr currentTrackedItem = head;
    ++size;
    return true;
  }

  // remove first instance of matching data type T
  bool remove(T removeData) {
    if (!head) {
      return false;
    }

    LinkedItemPtr prevTrackedItem = head;
    if (head->data == removeData) {
      if (tail == head) {
        tail = nullptr;
      }
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

  bool insertFront(T newData) {
    LinkedItemPtr newItemPtr = new LinkedItem{ newData, nullptr };

    if (!head) {
      head = newItemPtr;
      tail = head;
      ++size;
      return true;
    }

    newFrontItem->nextItem = head;
    head = newFrontItem;
    ++size;
    return true;
  }

  bool insertAfter(T prevItem, T newData) {
    if (!prevItem || !newInsertItem) {
      return false;
    }

    if (!head) { // assuming list is empty if head is never assigned so ignoring prevElement
      head = newInsertItem;
      ++size;
      return true;
    }

    newInsertItem->nextItem = prevItem->nextItem;
    prevItem->nextItem = newInsertItem;
    ++size;
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

  const T* front() {
    return head;
  }  
  
  const T* back() {
    return tail;
  }

  size_t getSize() const {
    return size;
  }

  bool empty() const {
   return !head;
  }

 private:
  LinkedItemPtr head;
  LinkedItemPtr tail;
  size_t size;
};
