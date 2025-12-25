#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7ll;

struct DSU {
  unordered_map<ll, ll> root;
  ll find(ll x) {
    if(!root.count(x)) return x;
    if(root[x]!=x) root[x]=find(root[x]);
    return root[x];
  }
  void use(ll x) {
    root[x]=find(x+1);
  }
};

struct BDSU {
  unordered_map<ll, ll> root;
  ll find(ll x) {
    x%=MOD;
    if(!root.count(x)) return x;
    if(root[x]!=x) root[x]=find(root[x]);
    return root[x];
  }
  void use(ll x) {
    root[x%MOD]=find((x+1)%MOD);
  }
};