#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> compress(vector<ll> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}

int main() {

  int N; cin>>N;
  vector<ll> v(N); for(auto& e:v) cin>>e;
  vector<int> p;
  {
    vector<ll> c=compress(v);
    for(int i=0; i<N; ++i) p.push_back(lower_bound(c.begin(), c.end(), v[i])-c.begin());
  }
  return 0;
}