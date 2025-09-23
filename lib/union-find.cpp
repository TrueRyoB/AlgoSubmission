#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
vector<int> par, rank, siz;
int nlink;

public:
  UnionFind(int n): par(n, -1), rank(n, 0), siz(n, -1), nlink(n) {}

  int root(int x) {
    if(par[x]==-1) return x;
    return par[x]= root(par[x]);
  }
  bool same(int x, int y) {
    return root(x)==root(y);
  }
  bool unite(int x, int y) {
    int rx=root(x), ry=root(y);
    if(rx==ry) return false;
    nlink--;

    if(rank[rx]<rank[ry]) swap(rx, ry);
    par[ry] = rx;
    if(rank[rx]==rank[ry]) ++rank[rx];
    siz[rx] += siz[ry];
    return true;
  }
  int size(int x) {
    return siz[root(x)];
  }
  int size() {
    return nlink;
  }
};