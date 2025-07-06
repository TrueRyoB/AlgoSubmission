#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N;cin>>N;

    auto solve = [&](int a, int b, int c) {
        int l = 0LL, r = 600000001LL;
        while (r - l > 1) {
            int mid = l+(r-l)/2;
            if (a * mid * mid + b * mid + c <= 0)
                l = mid;
            else
                r = mid;
        }
        if (a * l * l + b * l + c == 0)
            return l;
        return -1LL;
    };
    
    for(int d=1; d*d*d<=N; ++d) {
        if(N%d != 0LL) continue;
        int k = solve(3LL, 3LL*d, d*d-N/d);
        if(k > 0LL) {
            cout << k+d << " " << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
//1 000 000 000 000 000 000