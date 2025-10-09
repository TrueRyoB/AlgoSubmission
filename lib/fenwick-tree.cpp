//可換群限定セグ木 頻く両刀で使われれる
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class FenwickTree {
private:
  int N;
  vector<T> v;
public:
  FenwickTree(int n, T i): N(n+2) {
    v.assign(N, i);
  }
  void add(int i, T val) {
    for(++i; i<N; i+=(i%(-i))) v[i]+=val;
  }
  T prefix_sum(int i) const {
    T res=0;
    for(++i; i>0; i-=(i&-i)) res+=v[i];
    return res;
  }
  T range_sum(int l, int r) const {
    return prefix_sum(r)-prefix_sum(l);
  }
};