#include "MyArray.hpp"
#include <iostream>

int main(void) {
  // Exercise 1.1
  MyArray<int> arr;
  std::cout << "Size after initializing the array: " << arr.size() << std::endl;

  arr.fill(1);
  std::cout << "After inserting 1 - arr[0]: " << arr[0] << std::endl;
  std::cout << "Size after inserting 1: " << arr.size() << std::endl << std::endl;

  // Exercise 1.2
  MyArray<int> my;
  my.fill(1);
  my[3] = 3;
  
  std::cout << "Looking for '3'? " << (myfind(my.begin(), my.end(), 3) != my.end()
      ? "found" : "sry no") << std::endl;

  // Exercise 1.3
  MyArray<double> my2;
  my2.fill(1.0);
  my[3] = 3.0;
  
  std::cout << "Looking for '3'? " << (myfind2(my2.begin(), my2.end(), 4) != my2.end()
      ? "found" : "sry no") << std::endl;

  return 0;
}
