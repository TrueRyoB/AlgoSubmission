#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    vector<string> map(N); for(auto& e:map) cin>>e;

    //Monancharを使うっぽい
    //ただ全グラフ?には端などという概念がないうえに、繋がっているかも怪しいので
    //且つ回文の最短長さを求めるとのことなので
    //探索済というフラグのみ立てたら十分🦆
    //ただ、偶数回であるときの判定ができない...;-;

    return 0;
}
//あと2分で休憩時間が終わりなのですが
//どうしてもわからなそうなので、断念します...
//;-;
//https://atcoder.jp/contests/abc394/editorial/12279
//お疲れさまでした。