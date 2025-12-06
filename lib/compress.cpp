#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> compress(vector<ll> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}