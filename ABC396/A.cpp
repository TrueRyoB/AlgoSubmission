#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<int> v(N); for(auto& e:v) cin>>e;
    bool seen = false;
    for(int i=1; i+1<N; ++i) {
        if(v[i]==v[i-1] && v[i]==v[i+1]) {
            seen=true; break;
        }
    }
    if(seen) cout << "Yes";
    else cout << "No";

    return 0;
}