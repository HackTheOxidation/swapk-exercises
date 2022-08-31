#include <cstddef>

#ifndef MYARRAY_HPP_
#define MYARRAY_HPP_

template<typename T>
class MyArray {
public:
  MyArray() {
    array_ = {};
    size_ = 0;
  };
  ~MyArray() {};
  MyArray(MyArray const& ref)
    : array_(ref.array_), size_(ref.size_) {};
  MyArray<T>& operator=(MyArray<T> const& ref) {
    this->array_ = ref.array_;
    this->size_ = ref.size_;

    return *this;
  };
  void fill(const T& obj) {
    T new_array[size() + 1];

    for (int i = 0; i < size_; i++) {
      new_array[i] = array_[i];
    }
    new_array[size_] = obj;

    array_ = new_array;
  };
  T* begin() const {
    if (size_ > 0)
      return &array_[0];

    return nullptr;
  };
  T* end() const {
    if (size_ > 0)
      return &array_[size_ - 1];

    return nullptr;
  };
  T& operator[](int i) const {
    if (i < size_)
      return array_[i];

    return nullptr;
  };
  std::size_t size() const {
    return size_;
  };

private:
  std::size_t size_;
  T* array_;
};

template<typename T>
T* myfind(T* first, T* last, const T& v) {
  T* cursor = first;
  while (cursor != last) {
    if (v == cursor)
      break;
    else
      cursor++;
  }

  return cursor;
}

#endif

