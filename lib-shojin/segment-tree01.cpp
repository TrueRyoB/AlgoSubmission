// Date: September 3rd, 2025
// Description: good at applying a monoid operation within a range by O(logN)

template<typename T, typename F>
class SegmentTree {
private:
  int n;
  vector<T> v;
  F op;
  T ide;
  T query_sub(int a, int b, int k, int l, int r) {
    if (r<=a || b<=l) return ide;
    else if(a<=l && b<=r) return v[k];
    return op(
      query_sub(a, b, k*2+1, l, l+(r-l)/2),
      query_sub(a, b, k*2+2, l+(r-l)/2, r)
    );
  }

public:
  SegmentTree(int len, F monoid, T identity) :op(monoid), ide(identity) {
    n=1;
    while(n<len) n *=2;
    v.assign(2*n-1, identity);
  }
  void set(int i, T val) {
    i += n-1;
    v[i] = val;
    while(i > 0) {
      i = (i-1)/2;
      v[i] = op(v[i*2+1], v[i*2+2]);
    }
  }
  T query(int a, int b) {
    if(a>b) swap(a, b);
    return query_sub(a, b, 0, 0, n);
  }
};