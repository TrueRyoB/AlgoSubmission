#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//https://atcoder.jp/contests/abc293/editorial/5955
//説明: Iを基準にaの倍増を掛けている

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll mod) {
    int N=a.size();
    vector res(N, vector<ll>(N));
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) for(int k=0; k<N; ++k) (res[i][j]+=a[i][k]*b[k][j])%=mod;
    return res;
}
vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll r, ll mod) {
    int N=a.size();
    vector res(N, vector<ll>(N));
    for(int i=0; i<N; ++i) res[i][i]=1;
    do {
        if(r&1) res=mat_mul(res, a, mod);
        a = mat_mul(a, a, mod);
    } while(r>>=1);
    return res;
}