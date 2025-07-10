#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N=3;
    vector<int> v(N); for(auto& e:v) cin>>e;

    bool passed=false;
    for(int i=0; i<N; ++i) {
        int sum = v[0]*v[1]*v[2]/v[i];
        if(v[i]==sum) {
            passed=true;break;
        }
    }
    if(passed) cout << "Yes";
    else cout << "No";

    return 0;
}