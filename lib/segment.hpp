#ifndef LIB_SEGMENT
#define LIB_SEGMENT

template<typename T, typename F>
class Segment {
private:
  int n;
  vector<T> v;
  F op;
  T ide;

  T query_sub(int a, int b, int k, int l, int r) {
    if (r<=a || b<=l) return ide;
    else if(a<=l && r<=b) return v[k];
    int m = l+(r-l)/2;
    return op(
      query_sub(a, b, k*2, l, m),
      query_sub(a, b, k*2+1, m, r)
    );
  }

public:
  Segment(int len, T identity, F monoid) :op(monoid), ide(identity) {
    n=1;
    while(n<len) n *=2;
    v.assign(2*n, identity);
  }
  Segment(vector<T>& b, T identity, F monoid) :op(monoid), ide(identity) {
    n=1;
    while(n<b.size()) n*=2;
    v.assign(2*n, identity);
    for(int i=0; i<b.size(); ++i) v[i+n]=b[i];
    for(int i=n-1; i>=1; --i) v[i]=op(v[i*2], v[i*2+1]);
  }
  void set(int i, T val) {
    i += n;
    v[i] = val;
    while(i > 1) {
      i = i/2;
      v[i] = op(v[i*2], v[i*2+1]);
    }
  }
  T query(int a, int b) {
    if(a>b) swap(a, b);
    return query_sub(a, b+1, 1, 0, n);
  }

  T operator[](int i) const {
    return v[i+n];
  }

  template<class G>
  T apply(int i, G g) {
    set(i, g(v[i+n]));
    return v[i+n];
  }
};

#endif