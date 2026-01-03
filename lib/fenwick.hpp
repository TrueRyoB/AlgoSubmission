#ifndef LIB_FENWICK
#define LIB_FENWICK

template<typename T>
class Fenwick {
private:
  int N;
  vector<T> v;
public:
  Fenwick(int n, T i): N(n+2) {
    v.assign(N, i);
  }
  void add(int i, T val) {
    for(++i; i<N; i+=(i&-i)) v[i]+=val;
  }
  T prefix_sum(int i) const {
    T res=0;
    for(++i; i>0; i-=(i&-i)) res+=v[i];
    return res;
  }
  T range_sum(int l, int r) const {
    return prefix_sum(r)-prefix_sum(l-1);
  }
  T operator[](int i) const {
    return v[i];
  }
};

#endif