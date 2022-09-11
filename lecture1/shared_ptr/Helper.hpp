#ifndef HELPER_HPP_
#define HELPER_HPP_

// Exercise 3
namespace helper {

  template<typename T>
  struct Deleter {
    void operator()(T* t) {
      delete t;
    } 
  };

  template<typename T, class D = Deleter<T>>
  class Helper {
  private:
    D d_;

  public:
    Helper(D d) : d_(d) {}
    virtual ~Helper() {}

    void operator()(T* t) {
      d_(t);
    }
  };

}

#endif
