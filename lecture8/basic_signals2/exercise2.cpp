#include <boost/signals2.hpp>
#include <iostream>
#include <string>

struct median {
  double operator()(double ) {
  }
};

int main(void) {
  boost::signals2::signal<double (double, double, double)> sig;
  return 0;
}
