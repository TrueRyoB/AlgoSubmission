#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    deque<int> dq;
    for(int i=0; i<100; ++i) dq.push_front(0);
    int Q; cin>>Q;
    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            int x; cin>>x;
            dq.push_front(x);
        } else {
            int y = dq.front(); dq.pop_front();
            cout << y << endl;
        }
    }

    return 0;
}