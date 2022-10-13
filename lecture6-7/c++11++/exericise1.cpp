#include <iostream>
#include "exercise1.hpp"

int main(void) {
  long long int result = accumulate<int, int, int>(1, 2, 3);
  std::cout << "Result: " << result << std::endl;

  return 0;
}
