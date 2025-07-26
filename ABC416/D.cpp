#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

bool comp(int a, int b) {
    return a>b;
}

int32_t main() {
    int T; cin>>T;


    while(T--) {
        int N, M; cin>>N>>M;
        vector<int> a(N); for(auto& e:a) cin>>e;
        vector<int> b(N); for(auto& e:b) cin>>e;

        sort(a.begin(), a.end(), comp);
        sort(b.begin(), b.end());

        int sum = 0, less = 0, jt = 0;

        for(int i=0; i<N; ++i) {
            sum += a[i];
            for(int j=jt; j<N; ++j) {
                sum += b[j]; jt = j+1;
                if(a[i]+b[j] >= M) {
                    less++; break;
                }
            }
        }
        int res = (sum%M)+M*((sum/M)-less);
        cout << res << endl;

    }
    return 0;
}