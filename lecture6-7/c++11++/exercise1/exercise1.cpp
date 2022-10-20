#include <iostream>
#include "exercise1.hpp"

int main(void) {
  auto result = accumulate(1, 2, 3);
  std::cout << "Result: " << result << std::endl;

  return 0;
}
