#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<int> v(N); for(auto& e:v)cin>>e;

    vector<int> cntLeft(N,0); vector<bool> seen(N+1,false);
    cntLeft[0]=1; seen[v[0]]=true;
    for(int i=1; i+1<N; ++i) {
        cntLeft[i] = cntLeft[i-1]+(seen[v[i]]?0:1);
        seen[v[i]]=true;
        // cout << "cntLeft[" << i << "] is set " << cntLeft[i] << endl;
    }
    vector<int> cntRight(N,0); vector<bool> seen2(N+1,false);
    cntRight[N-1]=1; seen2[v[N-1]]=true;
    for(int i=N-2; i>0; --i) {
        cntRight[i] = cntRight[i+1]+(seen2[v[i]]?0:1);
        seen2[v[i]]=true;
        // cout << "cntRight[" << i << "] is set " << cntRight[i] << endl;
    }
    int res=0;
    for(int i=0; i+1<N; ++i) {
        res = max(cntLeft[i]+cntRight[i+1], res);
    }
    cout << res;

    return 0;
}