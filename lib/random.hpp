#ifndef LIB_RANDOM
#define LIB_RANDOM

#ifdef LOCAL
#include "std.hpp"
#endif

inline uint64_t xorshift64() {
  static uint64_t x=88172645463325252ull;
  x^=x<<7;
  x^=x>>9;
  return x;
}

template<uint64_t N>
inline bool chance() {
  constexpr uint64_t TH=(~0ull)/(N+1);
  return xorshift64()<=TH;
}

inline bool chance(uint64_t N) {
  return xorshift64() <= (~0ull)/(N+1);
}

#endif