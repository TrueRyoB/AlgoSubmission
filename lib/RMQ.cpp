#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F>
struct LazySegTree {
  int n;
  vector<T> dat, lazy;
  T id, lazy_id;
  F op;

  LazySegTree(int n_, T id_, F op_, T lazy_id_) : id(id_), op(op_), lazy_id(lazy_id_) {
    int x=1;
    while(x<n_) x<<=1;
    n=x;
    dat.assign(2*n-1, id);
    lazy.assign(2*n-1, lazy_id);
  }
  void set(int p, T x) {

  }
  T get(int p) {

  }
  T prod(int l, int r) {

  }
};