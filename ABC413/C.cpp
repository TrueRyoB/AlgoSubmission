#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int32_t main() {
    int Q; cin>>Q;
    deque<pii> dq;

    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            int c, x; cin>>c>>x;
            dq.push_back({c, x});
        } else {
            int k; cin>>k; int sum=0;
            while(k>0) {
                auto [nc, nx] = dq.front(); dq.pop_front();
                if(nc < k) {
                    sum += nc*nx;
                } else {
                    sum += k*nx;
                    if(nc-k != 0) dq.push_front({nc-k, nx});
                }
                k -= nc;
            }
            cout << sum << endl;
        }
    }
    

    return 0;
}