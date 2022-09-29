#include <cstddef>

class Test {}; 

template<typename T, int N>
class MyArray {
  public:
  T& operator[](size_t i) {
    return data_[i];
  }

  private:
  T data_[N];
};


void f() {
  MyArray<Test, 10> my;

  Test t;

  my[5] = t;
}

int main() {
  f();
}
