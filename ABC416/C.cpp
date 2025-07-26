#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long

int32_t main() {
    int N, K; ll X; cin>>N>>K>>X;
    vector<string> v(N); for(auto& e:v) cin>>e;

    vector<ll> exp(K+1); exp[0]= 1LL; 
    for(int i=1; i<=K; ++i) exp[i]=exp[i-1]*N;

    sort(v.begin(), v.end());

    string res = ""; X--;
    for(int i=0; i<K; ++i) {
        ll r = exp[K-i-1];
        ll d =  X / r;
        X -= d*r;
        res += v[d];
    }
    cout << res;

    return 0;
}