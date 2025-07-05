#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int N, M; cin>>N>>M;
    int sum=0;
    while(N--) {
        int x; cin>>x; sum+=x;
    }
    if(M>=sum) cout << "Yes";
    else cout << "No";

    return 0;
}