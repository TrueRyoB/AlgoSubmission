#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<string> v(N); for(auto& e:v) cin>>e;

    int cnt=0;
    set<string> s;
    for(int i=0; i+1<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            string conc = v[i]+v[j];
            string conc2 = v[j]+v[i];
            if(s.find(conc) == s.end()) {
                s.insert(conc); cnt++;
            }
            if(s.find(conc2) == s.end()) {
                s.insert(conc2); cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}