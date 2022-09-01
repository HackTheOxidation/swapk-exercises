#include "SharedPtr.hpp"
#include <iostream>
#include <ostream>

int main(void) {
  // Exercise 1
  {
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
  }

  // Exercise 2
  {
    SharedPtr<std::string> sp(new std::string("Hello world"));

    if (sp)
      std::cout << "SP Contains: " << *sp << std::endl;
  }

  {
    SharedPtr<std::string> sp(new std::string("Hello"));
    SharedPtr<std::string> sp2(new std::string("world"));

  //   if (sp == sp2)
  //     ;

  //   int x = (sp == sp2) << 1;
  //
  }

  // Exercise 3

  
  
  return 0;
}
