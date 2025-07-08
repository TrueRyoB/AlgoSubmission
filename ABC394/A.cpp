#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s;
    int cnt = 0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='2')++cnt;
    }
    for(int i=0; i<cnt;++i) {
        cout << '2';
    }
    return 0;
}