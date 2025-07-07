#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long
#define ll long long

typedef struct{
    int v;
    ll w;
}edge;

// WA
int32_t main() {
    int N, M; cin>>N>>M;
    vector<vector<edge>> edges(N);
    for(int i=0; i<M; ++i) {
        int u, v, w; cin>>u>>v>>w; --u; --v;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    ll res = (1<<62);

    auto dfs = [&](auto dfs, int visited, ll val, int c) {
        if(c == N-1) {
            res = min(val, res);
            return;
        }
        for(auto& e : edges[c]) {
            if((visited & (1<<e.v)) == 0) dfs(dfs, (visited | (1<<e.v)), (e.w ^ val), e.v);
        }
    };

    dfs(dfs, 0, 0LL, 0);
    cout << res;


    return 0;
}