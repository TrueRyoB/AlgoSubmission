#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define pii pair<long long, long long>
#define ll long long

int32_t main() {
    int Q; cin>>Q;
    ll fromFront=0, numLeft=0, offset=0;
    vector<pii> v;
    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            int l; cin>>l;
            v.push_back({fromFront, l}); fromFront+=l;
        } else if(q==2) {
            offset -= v[numLeft].second;
            ++numLeft;
        } else {
            int k; cin>>k; --k;
            cout << (v[numLeft+k].first+offset) << endl;
        }
    }

    return 0;
}