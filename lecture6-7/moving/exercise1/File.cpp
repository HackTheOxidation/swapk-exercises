#include "File.hpp"
#include <string>
#include <iostream>

int main(void) {
  std::string fileName = "test.txt";
  File f(fileName);

  File f2(std::move(f));

  File f3 = std::move(f2);
  
  return 0;
}
