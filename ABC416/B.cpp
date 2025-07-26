#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string t; cin>>t;
    bool reset=true;
    for(auto& e:t) {
        if(e=='.' && reset) {
            e = 'o'; reset=false;
        }
        if(e=='#') reset=true;
    }
    cout << t;
    return 0;
}