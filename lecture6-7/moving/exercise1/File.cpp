#include "File.hpp"
#include <iostream>

int main(void) {
  File f("test.txt");

  File f2(std::move(f));

  File f3 = std::move(f2);
  
  return 0;
}
