#ifndef SHAREDPTR_HPP_
#define SHAREDPTR_HPP_

#include <cstddef>

template<typename T>
class SharedPtr {
  private:
  T* ptr_;
  size_t count_;

  public:
  SharedPtr(T* t = 0) : ptr_(t), count_(1) {}
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
      delete ptr_;
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
};

#endif
