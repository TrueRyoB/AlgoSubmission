#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, Q; cin>>N>>Q;
    vector<int> v(N, 1); int cnt=0;
    vector<int> loc(N); for(int i=0; i<N; ++i) loc[i]=i; 
    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            int p, h; cin>>p>>h; --p; --h;
            v[loc[p]]--; if(v[loc[p]] == 1) --cnt;
            loc[p]=h;
            v[h]++; if(v[h]==2) ++cnt;
        }
        else {
            cout <<cnt << endl;
        }
    }

    return 0;
}