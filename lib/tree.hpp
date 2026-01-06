#ifndef LIB_TREE
#define LIB_TREE

#ifdef LOCAL
#include "std.hpp"
#endif

vector<int> toposort(const vector<vector<int>>& g, vector<int> indeg) {
  int N=g.size();
  assert(N == indeg.size());
  queue<int> q; for(int i=0; i<N; ++i) if(indeg[i]==0) q.push(i);
  vector<int> res; res.reserve(N);
  while(!q.empty()) {
    const auto u = q.front(); q.pop();
    res.push_back(u);
    for(const auto& v:g[u]) if(--indeg[v] == 0) q.push(v);
  }
  assert(res.size() == N);
  return res;
}

template<class T>
void warshal_floyd(vector<vector<T>>& g) {
  int N=g.size();
  assert(N<=300);
  for(int k=0; k<N; ++k) for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
    chmin(g[i][j], g[i][k]+g[k][j]);
  }
}


struct Tree {
  int N;
  vector<vector<int>> g;
  Tree(const vector<vector<int>>& v) {
    g=v;
  }
  Tree(int n): N(n) {
    g.resize(N);
    fill();
  }
  void fill() {
    for(int i=0; i+1<N; ++i) {
      int u, v; cin>>u>>v; --u; --v;
      g[u].push_back(v); g[v].push_back(u);
    }
  }
  const vector<int>& operator[](int i) const {
    return g[i];
  }
  int size() const {
    return N;
  }
  int indeg(int u) const {
    assert(false);
    return -1;
  }
  bool is_leaf(int u) const {
    assert(false);
    return false;
  }
  int dist(int u, int v) const {
    assert(false);
    return -1;
  }
  int diameter() const {
    assert(false);
    return -1;
  }
  int lca(int u, int v) const {
    assert(false);
    return -1;
  }
  int kth_ancestor(int v, int k) {
    assert(false);
    return -1;
  }
  int dist_lca(int u, int v) {
    assert(false);
    return -1;
  }
  //heavy-light decomposition
  int path_query(int u, int v) {

  }
};

struct WeightedTree {

};

#endif