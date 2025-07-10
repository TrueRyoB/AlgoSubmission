#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

string getVal(string s) {
    if(s=="N") return "S";
    if(s=="E") return "W";
    if(s=="S") return "N";
    if(s=="W") return "E";

    if(s=="NE") return "SW";
    if(s=="NW") return "SE";
    if(s=="SE") return "NW";
    if(s=="SW") return "NE";
    return "chokudai";
}

int32_t main() {
    string s; cin>>s;
    cout << getVal(s) << endl;

    return 0;
}