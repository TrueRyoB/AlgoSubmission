#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

typedef struct {
    int a, diff, indexAt;
}ab;

int32_t main() {
    int N, M; cin>>N>>M;
    vector<ab> v(M); 
    unordered_map<int, int> hash;
    for(int i=0; i<v.size(); ++i) {
        int a, b; cin>>a>>b;
        int diff = a-b;
        v[i] = {a, diff, i};
        if(hash.find(diff)==hash.end()) {
            hash[diff]=i;
        }
    }
    auto custom = [&](auto x, auto y) {
        return x.diff < y.diff;
    };
    int usedBy = -1;
    sort(v.begin(), v.end(), custom);
    int cnt = 0;
    for(int i=0; i<M; ++i) {
        if(v[i].indexAt < usedBy || N < v[i].a) continue;//同値は消させない作戦(がさつ)
        int diff = v[i].diff;
        int add = floor((N-v[i].a)/diff);
        if(N-(add+1)*diff >=0) add++;
        N -= add*diff;
        cnt += add;
        usedBy = hash[diff];
    }
    cout << cnt;

    return 0;
}
//無理や...
//エラー数が増えているのだが..?