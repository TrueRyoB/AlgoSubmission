#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, M; cin>>N>>M;
    vector<bool> v(N+1, false);
    for(int i=0; i<M; ++i) {
        int x; cin>>x;
        v[x]=true;
    }
    cout << (N-M) << endl;
    for(int i=1; i<=N; ++i) {
        if(!v[i]) cout << (i) << " ";
    }
    return 0;
}