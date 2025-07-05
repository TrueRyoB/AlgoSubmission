#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N; cin>>N;
    vector<int> v(N); for(auto& e:v)cin>>e;

    int cntp=0, cntn=0;
    for(auto& e : v) {
        if(e == abs(v[0]))cntp++;
        else if(e == -1*abs(v[0]))cntn++;
    }
    if(cntp+cntn==N && min(cntp, cntn)==N/2) {
        cout << "Yes" << endl;
        return;
    }


    bool safe = true;
    auto custom = [&](int a, int b) {
        return abs(a) < abs(b);
    };
    sort(v.begin(), v.end(), custom);
    for(int i=1; i<N-1; ++i) {
        if(v[i]*v[i] != v[i-1]*v[i+1]) {
            safe = false; break;
        }
    }
    if(safe) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int32_t main() {
    int T; cin>>T;
    while(T--)solve();
    return 0;
}