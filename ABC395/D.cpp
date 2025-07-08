#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, Q; cin>>N>>Q;
    vector<int> loc(N);
    vector<int> back(N);//ren to back
    vector<int> ren(N);//back to ren
    for(int i=0; i<N; ++i) {
        loc[i]=i;
        ren[i]=i;
        back[i]=i;
    }
    while(Q--) {
        int q, a, b; cin>>q>>a; --a;
        if(q<=2) {
            cin>>b; --b;
        }
        if(q==1) {
            loc[a] = ren[b];
        } else if(q==2) {
            swap(ren[a], ren[b]);
            swap(back[ren[a]], back[ren[b]]);
        } else {
            cout << back[loc[a]]+1 << endl;
        }
    }
    return 0;
}