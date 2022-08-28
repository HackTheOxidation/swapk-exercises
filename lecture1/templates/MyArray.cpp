#include "MyArray.hpp"
#include <cstddef>

template<typename T>
MyArray<T>::MyArray() {
  _size = 0;
  _array = {};
}


template<typename T>
MyArray<T>::MyArray(MyArray const& other) {
  _size = other.size();
  _array = other._array;
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(MyArray const& other) {
  _size = other.size();
  _array = other._array();
}

template<typename T>
void MyArray<T>::fill(const T & obj) {
  T new_array[size() + 1];
  for (int i = 0; i < _size; i++) {
    new_array[i] = _array[i];
  }
  new_array[size()] = obj;

  _array = new_array;
}

template<typename T>
T* MyArray<T>::begin() const {
  if (_size > 0) {
    return &_array[0];
  } else {
    return nullptr;
  }
}

template<typename T>
T* MyArray<T>::end() const {
  if (_size > 0) {
    return &_array[_size - 1];
  } else {
    return nullptr;
  }
}

template<typename T>
std::size_t MyArray<T>::size() const {
  return _size;
}

template<typename T>
T& MyArray<T>::operator[](int i) const {
  if (i >= 0 && i < _size)
    return _array[i];

  return nullptr;
}
