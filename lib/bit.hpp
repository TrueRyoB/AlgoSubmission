#ifndef LIB_BIT
#define LIB_BIT

#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

template<class T>
int popcount(T t) {
  static_assert(is_integral_v<T>);
  assert(t>=0);
  int res=0;
  while(t) {
    if(t&1) ++res;
    t>>=1;
  }
  return res;
}

//most significant bit
template<class T>
int msb(T t) {
  static_assert(is_integral_v<T>);
  assert(t>=0);
  int res=-1;
  for(int i=0; (1ll<<i)<=t; ++i) if((t>>i)&1) res=i;
  return res;
}

//least significant bit
template<class T>
int lsb(T t) {
  static_assert(is_integral_v<T>);
  assert(t>=0);
  for(int i=0; (1ll<<i)<=t; ++i) if((t>>i)&1) return i;
  return -1;
}

//32 -> 10000
template<class T>
string to_binary(T t) {
  static_assert(is_integral_v<T>);
  assert(t>=0);
  string res="";
  for(int i=0; (1ll<<i)<=t; ++i) res.push_back((t>>i)&1 ? '1':'0');
  reverse(res.begin(), res.end());
  return res;
}

#endif