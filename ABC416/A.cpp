#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, L, R; cin>>N>>L>>R;
    string s; cin>>s;
    for(int i=L-1; i<R; ++i) {
        if(s[i]!='o') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}