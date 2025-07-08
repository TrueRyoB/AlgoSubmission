#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// #define int long long

int32_t main() {
    int N, M; cin>>N>>M;
    vector<set<int>> s(N); int cnt = 0;
    for(int i=0; i<M; ++i) {
        int u, v; cin>>u>>v; --u; --v; if(u>v) swap(u, v);
        if(u==v || s[u].find(v) != s[u].end()) {
            cnt++; continue;
        }
        s[u].insert(v);
    }
    cout << cnt << endl;

    return 0;
}