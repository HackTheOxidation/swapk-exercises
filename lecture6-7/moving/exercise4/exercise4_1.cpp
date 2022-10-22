#include "detail.hpp"
#include <string>

int g() {
  return 1;
}

std::string&& f() {
  return "Henlo";
}

int main(void) {
  int a, x;
  
  // lvalues
  PRINT_VALUE_CAT(a);
  PRINT_VALUE_CAT("Henlo");

  // xvalues
  PRINT_VALUE_CAT(std::move(x));
  PRINT_VALUE_CAT(f());

  // prvalues
  PRINT_VALUE_CAT(g());
  PRINT_VALUE_CAT(42);

  return 0;
}

