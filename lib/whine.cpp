#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void whine(int N=1e5) {
  static int seed=42;
  static mt19937_64 rng(seed<0?chrono::steady_clock::now().time_since_epoch().count():seed);
  uniform_int_distribution<ll> dist(0, N);
  if(dist(rng)<=0) cout << "解説AC" << endl;
}