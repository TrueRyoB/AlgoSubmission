#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    unordered_map<int, int> map;
    
    int res = 9999999999999LL;
    bool found = false;
    for(int i=0; i<N; ++i) {
        int x; cin>>x;
        if(map.find(x) != map.end()) {
            found=true;
            res = min(res, i-map[x]+1);
        }
        map[x]=i;
    }
    if(found) {
        cout << res;
    } else {
        cout << -1;
    }

    return 0;
}