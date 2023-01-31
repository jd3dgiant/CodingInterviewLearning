#ifndef STACKS_H
#define STACKS_H
#include <array>

#include "../LinkedList/LinkedList/LinkedList.h"

// stack data structure needs to be Last In First out when adding and removing items
// so last item added to the data structure needs to also be removed first

template<typename T>
class Stack {
public:
  Stack() = default;
  Stack(T item) {
    // handle constructing as first item of stack
    push(item);
  }
  // main stack functions
  void push(T item);
  T pop();
  T top();
  bool empty();
  void clear();
private:
  // data storage. Could be a simple vector data internally, but want to be able to handle insertion in preallocated memory, so underlying data is not reallocating constantly
  //size_t curIndex = 0;
  //size_t curSize = 0;
  //constexpr size_t maxArraySize = 8;

  //std::array<T, maxArraySize>* currentCache = nullptr;

  LinkedList<T> data;
};

#endif
