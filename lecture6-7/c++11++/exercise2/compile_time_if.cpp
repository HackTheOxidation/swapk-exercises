#include <string>
#include <iostream>

template<typename T, typename... Args>
void ya_printf(const char *s, T value, Args... args) {
  while (*s) {
    if (*s == '%') {
      if (*(s + 1) == '%') {
	++s;
      } else {
	std::cout << value;
	if constexpr(sizeof...(args) > 0)
	  ya_printf(s + 1, args...);

	return;
      }
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}


int main(void) {
  ya_printf("Henlo %S", "Wurld\n");
  return 0;
}
