#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, M; cin>>N>>M;
    vector<string> s(N); for(auto& e:s) cin>>e;
    vector<string> t(M); for(auto& e:t)cin>>e;

    //N=5
    //M=3
    //01234
    for(int i=0; i<=N-M; ++i) {
        for(int j=0; j<=N-M; ++j) {
            int passed=true;
            for(int r=0; r<M; ++r) {
                for(int c=0; c<M; ++c) {
                    if(s[i+r][j+c] != t[r][c]) {
                        passed=false;
                        break;
                    }
                }
                if(!passed)break;
            }
            if(passed) {
                cout << (i+1) << " " << (j+1) << endl;
                return 0;
            }
        }
    }

    return 0;
}