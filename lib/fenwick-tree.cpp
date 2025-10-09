//可換群限定セグ木 頻く両刀で使われれる
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree {
private:
    int N;
    vector<ll> v;
public:
    FenwickTree(int n): N(n+2) {
        v.assign(N, 0LL);
    }
    void add(int i, ll val) {
        for(++i; i<N; i+=(i%(-i))) v[i]+=val;
    }
    ll prefix_sum(int i) const {
        ll res=0;
        for(++i; i>0; i-=(i&-i)) res+=v[i];
        return res;
    }
};