#include "SharedPtr.hpp"
#include <iostream>
#include <ostream>

int main(void) {
  int* zero = new int(0);
  int* one = new int(1);

  SharedPtr<int> szero(zero);
  std::cout << "*szero " << *szero << std::endl;

  SharedPtr<int> sone(one);
  std::cout << "sone initialized." << std::endl;
  
  SharedPtr<int> sone2 = sone;
  std::cout << "sone2 assigned." << std::endl;
  
  SharedPtr<int> sone3(sone);
  std::cout << "sone3 copy constructor." << std::endl;
  
  return 0;
}
