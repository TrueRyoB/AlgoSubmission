#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s; int n = s.size(), cnt = 0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='B') {
            for(int j=1; j<=i; ++j) {
                if(s[i-j]=='A' && s[i+j]=='C') ++cnt;
            }
        }
    }
    cout << cnt;

    return 0;
}