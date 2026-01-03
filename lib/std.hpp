#ifndef LIB_STD
#define LIB_STD

#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <functional>
#include <cstdint>
#include <string>
#include <cassert>

using namespace std;
using ll = long long;

constexpr ll LINF = 1001001001001001001ll;
constexpr int d[] = {0, -1, 0, 1, 0};
template <typename T> inline void chmin(T& a, const T& b) {if (a > b) a = b; }
template <typename T> inline void chmax(T& a, const T& b) {if (a < b) a = b; }

#define endl '\n'
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for(const auto& e:v)os<<e<<'\t'; return os; }

#endif