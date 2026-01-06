#ifndef LIB_IOSTREAM
#define LIB_IOSTREAM

#ifdef LOCAL
#include "std.hpp"
#endif

namespace std {
//cout
template <typename T, size_t N> ostream& operator<<(ostream& os, const array<T, N>& v) { os << '['; for(size_t i=0; i<N; ++i) { if(i) os<<", "; os<<v[i]; } os << "]"; return os; }
template <typename T> ostream& operator<<(ostream& os, const pair<T, T>& p) { os << '{' << p.first << ", " << p.second <<  "}"; return os; }
template <class T, class F, class G> ostream& operator<<(ostream& os, const tuple<T, F, G>& t) { os << '{' << get<0>(t) << ", " << get<1>(t) << ", "  << get<2>(t) << "}"; return os; }
constexpr const char* dotline = "-------------------------------------";
//cin
}
#endif