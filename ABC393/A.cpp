#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s1, s2; cin>>s1>>s2;
    bool ok1 = s1 == "fine";
    bool ok2 = s2 == "fine";
    if(ok1 && ok2) {
        cout << 4;
    } else
    if(!ok1 && !ok2) {
        cout << 1;
    } else 
    if(ok1) {
        cout << 3;
    } else {
        cout << 2;
    }

    return 0;
}