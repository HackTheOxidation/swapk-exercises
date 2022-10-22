#include "Copyable.hpp"
#include <vector>

int main(void) {
  std::vector<Copyable> vec = { Copyable{1}, Copyable{2}, Copyable{3}, Copyable{4}, Copyable{5} };

  Copyable c6(6);
  vec.emplace_back(std::move(c6));

  Copyable c7(7);
  vec.emplace_back(std::move(c7));
  
  return 0;
}
