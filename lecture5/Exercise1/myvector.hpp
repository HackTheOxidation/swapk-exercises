
#include <cstddef>
#include <exception>
template<typename T>
class MyVector {
  public:
  explicit MyVector(int capacity = 10) {
    data_ = new T[capacity];

  }

  MyVector(const MyVector& other) {

  }

  MyVector& operator=(const MyVector& other) {

  }

  ~MyVector() {
  }

  int size() const {
  }

  T& back() {
      
  }

  void push_back(const T& t) {
  }

  void pop_back() {
  }

  void insert(const T& t, size_t n) {
  }

  T* begin() const {
    return data_;
  }

  T* end() const {
    return data_ + size();
  }

  T& operator [](size_t i) {
    if (i >= size())
      throw std::exception();

    return data_[i];
  }

  private:
  T* data_;
};
