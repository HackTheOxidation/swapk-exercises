#ifndef SHAREDPTR_HPP_
#define SHAREDPTR_HPP_

#include "Helper.hpp"
#include <cstddef>

// Exercise 4
namespace sharedptr {

using namespace helper;

// Exercise 1
template<typename T>
class SharedPtr {
  private:
  T* ptr_;
  size_t count_ = 1;
  Helper<T>* h_;

  public:
  // Exercise 2.1
  explicit SharedPtr(T* t = 0) : ptr_(t) {}

  // Exercise 3
  template<typename D>
  SharedPtr(T* t, D d) : ptr_(t), h_(new Helper<T, D>(d)) {}

  SharedPtr(const SharedPtr<T>& ref)
    : SharedPtr<T>(ref.ptr_) {
    count_ = ref.count_ + 1;
  }

  SharedPtr& operator=(const SharedPtr<T>& ref) {
    if (this != &ref) {
      this->ptr_ = ref.ptr_;
      this->count_ = ref.count_ + 1;
    }

    return *this;
  } 

  ~SharedPtr() {
    count_--;

    if (count_ == 0 && ptr_)
      (*h_)(ptr_);
  }

  T& operator*() const throw() {
    return *ptr_;
  }

  T* operator->() const throw() {
    return ptr_;
  }

  size_t count() const {
    return count_;
  }

  // Exercise 2.2.2
  explicit operator bool() {
    return ptr_ != nullptr;
  }

};

// Exercise 2.2.3
template<typename T>
SharedPtr<T> operator==(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
  return lhs.ptr_ == rhs.ptr_;
}

}

#endif
