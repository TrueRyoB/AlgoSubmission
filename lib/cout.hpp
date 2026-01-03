#ifndef LIB_COUT
#define LIB_COUT

#include "std.hpp"

namespace std {
template <typename T, size_t N> ostream& operator<<(ostream& os, const array<T, N>& v) { os << '['; for(size_t i=0; i<N; ++i) { if(i) os<<", "; os<<v[i]; } os << "]"; return os; }
template <typename T> ostream& operator<<(ostream& os, const pair<T, T>& p) { os << '{' << p.first << ", " << p.second <<  "}"; return os; }
}
#endif