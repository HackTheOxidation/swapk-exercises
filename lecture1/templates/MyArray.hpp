#include <cstddef>

#ifndef MYARRAY_HPP_
#define MYARRAY_HPP_

template<typename T>
class MyArray {
public:
  MyArray();
  ~MyArray() {};
  MyArray(MyArray const&);
  MyArray& operator=(MyArray const&);
  void fill(const T&);
  T* begin() const;
  T* end() const;
  T& operator[](int i) const;
  std::size_t size() const;

private:
  std::size_t _size;
  T _array[];
};

#endif
