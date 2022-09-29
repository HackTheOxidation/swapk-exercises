#include <algorithm>
#include <cstddef>
#include <type_traits>

class Test {};

template<typename T>
class MyVector {
public:
  MyVector(int capacity = 10)
    : capacity_(capacity), count_(0), data_(new T[capacity]) {}

  bool full() const {
    return count_ == capacity_;
  }

  void push_back(const T& oneMore) {
    if (full()) {
      capacity_ *= 2;
      T* newData = new T[capacity_];

      std::copy(data_, data_+count_, newData);
      std::swap(data_, newData);
      delete [] newData;
    }

    data_[count_] = oneMore;
    ++count_;
  }

private:
  size_t capacity_;
  size_t count_;
  T* data_;
};

void f() {
  MyVector<Test> my(20);

  Test t;

  my.push_back(t);
}

int main() {
  f();
}
