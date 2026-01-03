#ifndef LIB_UTIL
#define LIB_UTIL

#ifdef LOCAL
#include "std.hpp"
#endif

//TODO: implement a method for coordinate compression
template<class T>
struct Grid {
  vector<vector<T>> g;
  static constexpr int d[5]={1, 0, -1, 0, 1};

  Grid(T id) {
    int H, W; cin>>H>>W;
    g=vector(H, vector<T>(W, id));
    fill();
  }
  int H() const { return g.size(); }
  int W() const { return g.empty() ? 0 : g[0].size(); }
  void fill() {
    for(auto& row:g) for(auto& e:row) cin>>e;
  }
  const vector<T>& operator[](int i) const {
    return g[i];
  }
  vector<T>& operator[](int i) {
    return g[i];
  }
  void print(const string& label="") const {
    if(label.size()>0) cout << label << ": " << endl;
    for(const auto& row: g) cout << row << endl;
  }
  void print(int i, const string& label="") const {
    if(label.size()>0) cout << label <<"[" << i << "]: " << endl;
    cout << g[i] << endl;
  }
  vector<pair<int, int>> neighbor(int i, int j) const {
    vector<pair<int, int>> res;
    for(int k=0; k<4; ++k) {
      int ni=i+d[k], nj=j+d[k+1];
      if(0<=ni && ni<H() && 0<=nj && nj<W()) res.emplace(ni, nj);
    }
    return res;
  }

  template<class F>
  void forEach(F f) const {
    for(int i=0; i<H(); ++i) for(int j=0; j<W(); ++j) f(i, j, g[i][j]);
  }
};

template<class T>
struct PrefixSum {
  vector<T> res;
  PrefixSum(const vector<T>& v) {
    static_assert(is_integral_v<T>);
    int N=v.size();
    res = vector<T>(N+1);
    for(int i=0; i<N; ++i) res[i+1]=v[i]+res[i];
    return res;
  }
  T operator[](int i) const {
    return res[i];
  }
  //[l, r)
  T operator()(int l, int r) const {
    return s[r]-s[l];
  }
};

#endif