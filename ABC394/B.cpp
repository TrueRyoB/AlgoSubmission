#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<string> v(N); for(auto& e:v) cin>>e;

    auto custom = [&](string a, string b) {
        return a.size() < b.size();
    };
    sort(v.begin(), v.end(), custom);

    for(int i=0; i<N; ++i) {
        cout << v[i];
    }

    return 0;
}