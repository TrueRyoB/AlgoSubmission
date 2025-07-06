#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    double x; cin>>x;
    if(x>=38.0) {
        cout << 1 << endl;
    }
    else if(x<37.5) {
        cout << 3 << endl;
    }
    else {
        cout << 2 << endl;
    }

    return 0;
}