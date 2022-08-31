#include "MyArray.hpp"
#include <iostream>

int main(void) {
  MyArray<int> arr;
  std::cout << "Size after initializing the array: " << arr.size() << std::endl;

  arr.fill(1);
  std::cout << "After inserting 1 - arr[0]: " << arr[0] << std::endl;
  std::cout << "Size after inserting 1: " << arr.size() << std::endl << std::endl;

  return 0;
}
