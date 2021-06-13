// ask Derrick about throwing exceptions
// and when would setting up a stack-based iteration of data versus recursion calling overhead be
// ideal?

#include <iostream>
#include <vector>
#include "BinarySearch.hpp"

int main() {
  std::vector<int> searchArr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> searchArr1{6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
  std::cout << BinaryIntSearch(searchArr, 6); // returns 6
  std::cout << BinaryIntSearch(searchArr1, 3); // returns -1
}
