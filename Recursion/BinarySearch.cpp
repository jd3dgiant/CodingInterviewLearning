#include "BinarySearch.hpp"

// cpp only function
int RecursiveIntSearch(
    const std::vector<int> sortedArray,
    const int valueToFind,
    const int startIndex,
    const int endIndex) {
  int searchMax = endIndex - startIndex;

  if (searchMax == 0 && sortedArray[startIndex] != valueToFind) {
    return -1; // value not found
  } else if (sortedArray[startIndex] > sortedArray[endIndex]) {
    return -1; // array was not sorted
  } else {
    int middleIndex = (searchMax / 2) + startIndex;
    int indexedValue = sortedArray[middleIndex];

    if (indexedValue == valueToFind) {
      return middleIndex;
    } else if (indexedValue > valueToFind) { // search left of middleindex
      return RecursiveIntSearch(sortedArray, valueToFind, startIndex, middleIndex - 1);
    } else { // search right of middle index
      return RecursiveIntSearch(sortedArray, valueToFind, middleIndex + 1, endIndex);
    }
  }
}

int BinaryIntSearch(const std::vector<int> sortedArray, const int valueToFind) {
  int arraySize = sortedArray.size();
  if (arraySize == 0) {
    return -1; // return error instead
  }
  return RecursiveIntSearch(sortedArray, valueToFind, 0, arraySize - 1);
}
