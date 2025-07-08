#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<int> v(N); for(auto& e:v) cin>>e;

    bool safe = true;
    for(int i=1; i<N; ++i) {
        if(v[i-1]>=v[i]) {
            safe=false;break;
        }
    }
    if(safe)cout << "Yes";
    else cout << "No";

    return 0;
}