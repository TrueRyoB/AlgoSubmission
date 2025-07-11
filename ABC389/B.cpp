#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    int x=1, i=1LL;
    while(N != x) {
        i++;
        x *= i;
    }
    cout << i << endl;

    return 0;
}