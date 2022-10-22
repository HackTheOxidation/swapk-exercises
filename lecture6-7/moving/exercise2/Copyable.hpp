#include <iostream>

class Copyable {
public:
  Copyable(int inner)
    : inner_(inner) {
    std::cout << "Called the default constructor on " << inner_ << "\n";
  }
  
  Copyable(const Copyable& other)
    : inner_(other.inner_) {
    std::cout << "Called the copy constructor on " << inner_ << "\n";
  }

  Copyable& operator=(const Copyable& other) {
    if (this != &other)
      this->inner_ = other.inner_;

    std::cout << "Called the copy assignment operator on " << inner_ << "\n";
    
    return *this;
  }

  Copyable(Copyable&& rhs) noexcept
    : inner_(std::move(rhs.inner_)) {
    std::cout << "Called the move constructor on " << inner_ << "\n";
  }

  Copyable& operator=(Copyable&& rhs) noexcept {
    if (this != &rhs)
      this->inner_ = std::move(rhs.inner_);

    std::cout << "Called the move assignment operator on " << inner_ << "\n";
    
    return *this;
  }

private:
  int inner_;  
};
