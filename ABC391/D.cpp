#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N, W; cin>>N>>W;
    //列を上昇させてそこだけ管理しようと思ったけど
    //すでにきつい (setとcntの合わせ技でいけるか...?)
    //上昇するときに自分以外もまきこむ場合があるので(上にブロックがあるなど)、その判定もだるい...

    //飛ばします

    //T <= 10^9
    //N <= 2*10^5

    int Q; cin>>Q;
    while(Q--) {
        int t, a; cin>>t>>a;
        //TODO: 
    }

    return 0;
}