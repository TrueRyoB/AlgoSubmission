#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, M; cin>>N>>M;
    vector<int> B(N); for(auto&e:B) cin>>e;
    vector<int> W(M); for(auto&e:W) cin>>e;
    sort(B.begin(), B.end());
    sort(W.begin(), W.end());

    int sum=0, bcnt=0, wcnt=0;
    for(; bcnt<N; ++bcnt) {
        if(B[N-bcnt-1]<0) break;
        sum+=B[N-bcnt-1];
    }
    for(; wcnt<min(bcnt,M); ++wcnt) {
        if(W[M-wcnt-1]<0) break;
        sum+=W[M-wcnt-1];
    }
    while(wcnt<M && bcnt<N && (B[N-bcnt-1]+W[M-wcnt-1])>=0) {
        sum+=B[N-bcnt-1]+W[M-wcnt-1];
        ++wcnt; ++bcnt;
    }
    cout << sum<<endl;

    return 0;
}