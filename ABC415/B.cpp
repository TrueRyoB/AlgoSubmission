#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s;
    int lastVal = -1;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='#') {
            if(lastVal < 0) {
                lastVal = i;
            } else {
                cout << (lastVal+1) << "," << (i+1) << endl;
                lastVal = -1;
            }
        }
    }

    return 0;
}