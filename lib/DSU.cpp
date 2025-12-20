#include <bits/stdc++.h>
using namespace std;

struct DSU {
  unordered_map<int, int> root;
  int find(int x) {
    if(!root.count(x)) return x;
    if(root[x]!=x) root[x]=find(root[x]);
    return root[x];
  }
  void use(int x) {
    root[x]=find(x+1);
  }
};