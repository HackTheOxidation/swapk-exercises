#ifndef EXERCISE1_HPP_
#define EXERCISE1_HPP_


template<typename Acc, typename... Args>
Acc accumulate(Acc acc, Args ...args) {
  return acc + accumulate(args...);
}

double accumulate() {
  return 0;
}

#endif
