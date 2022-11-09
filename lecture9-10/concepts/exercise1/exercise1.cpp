#include <iterator>
#include <ostream>
#include <type_traits>
#include <concepts>
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>
#include <list>

// Exercise 1.1
template<typename T>
concept Sortable = requires(T t) {
  typename T::value_type;
  typename T::size_type;
  typename T::allocator_type;
  typename T::iterator;
  typename T::const_iterator;
  t.size();
  t.begin();
  t.end();
  t.cbegin();
  t.cend();
};

template<Sortable Container>
void sort(Container &container) {
  std::sort(container.begin(), container.end());
}

// Exercise 1.2
template<typename T>
concept Iterable = requires(T t) {
  typename T::iterator;
  typename T::const_iterator;
  t.begin();
  t.end();
};

template<typename T>
concept Streamable = requires(std::ostream &os, T t, T::value_type v) {
  { os << v } -> std::convertible_to<std::ostream &>;
};

template<typename T>
concept IterableStreamable = Iterable<T> && Streamable<T>;

template<IterableStreamable Container>
void print(Container container) {
  for (auto c : container) {
      std::cout << c << " ";
  }
  std::cout << "\n";
}

int main(void) {
  // Exercise 1.1
  {
    std::vector<int> v{5, 2, 15, 3, 7};
    sort(v);

    for (auto elem : v)
      std::cout << elem << " ";
    std::cout << "\n";
  }

  // Exercise 1.2
  {
    std::vector<int> v{5, 2, 15, 3, 7};
    print(v);
  }

  return 0;
}
