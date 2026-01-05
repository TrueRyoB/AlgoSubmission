#ifndef LIB_PRIMITIVE
#define LIB_PRIMITIVE

#ifdef LOCAL
#include "std.hpp"
#endif

template<ll MOD>
struct Modint {
  static constexpr Modint zero() { return Modint(0); }
  static constexpr Modint one() { return Modint(1); }
  ll v;
  Modint(long long x=0): v(x%MOD) {
    if (v<0) v+=MOD;
  }
  const ll& val() const {
    return v;
  }
  inline void print(ostream& os) const {
    os<<v;
  }
  friend istream& operator>>(istream& is, Modint& a) {
    is>>a.v; return is;
  }
  friend ostream& operator<<(ostream& os, const Modint& a) {
    return a.print(os), os;
  }
  Modint& operator++() {
    if(++v == MOD) v=0;
    return *this;
  }
  Modint operator++(int) {
    Modint prev=*this;
    ++(*this);
    return prev;
  }
  Modint& operator+=(const Modint& o) {
    v+=o.v;
    if(v>=MOD) v-=MOD;
    return *this;
  }
  Modint& operator-=(const Modint& o) {
    v-=o.v;
    if(v<0) v+=MOD;
    return *this;
  }
  Modint& operator*=(const Modint& o) {
    v = v*o.v%MOD;
    return *this;
  }
  Modint operator+(const Modint& a) const {
    Modint res=(*this);
    res+=a;
    return res;
  }
  Modint operator-(const Modint& a) const {
    Modint res=(*this);
    res-=a;
    return res;
  }
  Modint operator*(const Modint& a) const {
    Modint res=(*this);
    res*=a;
    return res;
  }
  Modint operator/(const Modint& a) const {
    Modint res=(*this);
    res/=a;
    return res;
  }
  Modint pow(ll n) const {
    Modint r(1), a(*this);
    while(n) {
      if(n&1) r*=a;
      a*=a;
      n>>=1;
    }
    return r;
  }
  Modint inv() const {
    return pow(MOD-2);
  }
  Modint& operator/=(const Modint& o) {
    return *this *= o.inv();
  }
};

#endif