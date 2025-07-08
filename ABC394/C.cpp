#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s; int n = s.size();
    string res = "";
    int laststop = 0, i=0;
    while(i<n) {
        //modify and skip one more i if WA
        if(i+1<n && s[i]=='W' && s[i+1]=='A') {
            res += "AC"; int laststop=i;
            while(i>0 && s[i-1]=='W') {
                res[i]='C';
                res[--i]='A';
            }
            i = laststop+2;
            continue;
        }
        res += s[i]; ++i;
    }
    cout << res;

    return 0;
}