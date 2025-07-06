#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s;
    int N = s.size(), cnt=0;
    for(int i=0; i<N; ++i) {
        if(s[i] != (((i+cnt)%2==0)?'i':'o')) cnt++;
    }
    if((N+cnt)%2!=0)cnt++;
    cout <<cnt <<endl;

    return 0;
}