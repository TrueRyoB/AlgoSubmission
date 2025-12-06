#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> compress(vector<ll> v) {
  vector<ll> res = v;
  sort(v.begin(), v.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}