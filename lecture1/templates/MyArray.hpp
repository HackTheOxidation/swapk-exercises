#include <cstddef>
#include <iostream>
#include <typeinfo>

#ifndef MYARRAY_HPP_
#define MYARRAY_HPP_

template<typename T, std::size_t capacity = 5>
class MyArray {
public:
  MyArray() {};

  ~MyArray() {};

  MyArray(MyArray const& ref)
    : array_(ref.array_), size_(ref.size_) {};

  MyArray<T, capacity>& operator=(MyArray<T, capacity> const& ref) {
    this->array_ = ref.array_;
    this->size_ = ref.size_;

    return *this;
  };

  void fill(const T& obj) {
    for (std::size_t i = 0; i < capacity; i++) {
      array_[i] = obj;
    }
    size_ = capacity;
  };

  T* begin() {
    if (size_ > 0)
      return &array_[0];

    return nullptr;
  };

  T* end() {
    if (size_ > 0)
      return &array_[size_ - 1];

    return nullptr;
  };

  T& operator[](int i) {
      return array_[i];
  };

  std::size_t size() const {
    return size_;
  };

private:
  std::size_t size_ = 0;
  T array_[capacity];
};


// Exercise 1.2
template<typename T>
T* myfind(T* first, T* last, const T& v) {
  for (auto iter = first; iter <= last; iter++) {
    if (*iter == v)
      return iter;
  }

  return last;
}

// Exercise 1.3
template<typename T, typename V>
T* myfind2(T* first, T* last, const V& v) {
  const T val = static_cast<T>(v);
  for (auto iter = first; iter <= last; iter++) {
    if (*iter == val) {
      return iter;
    }
  }

  return last;
}

#endif

