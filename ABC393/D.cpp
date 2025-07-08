#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int N; cin>>N;
    string s; cin>>s;

    vector<int> cnt(N); 
    cnt[0]=(s[0]=='1')?1:0;
    for(int i=1; i<N; ++i) {
        cnt[i] = cnt[i-1]+((s[i]=='1')?1:0);
    }
    vector<vector<int>> dp(N, vector<int>(2));

    dp[0][0]=0, dp[N-1][1]=0;
    for(int i=1; i<N; ++i) {
        dp[i][0]=((s[i]=='0')?cnt[i-1]:0)+dp[i-1][0];
    }
    for(int i=N-2; i>=0; --i) {
        dp[i][1]=((s[i]=='0')?(cnt[N-1]-cnt[i]):0)+dp[i+1][1];
    }
    int res = LLONG_MAX;
    for(int i=0; i<N; ++i) {
        res = min(res, dp[i][0]+dp[i][1]);
    }
    cout << res;

    return 0;
}//g++ -Wall -Wextra -g -std=c++20 ABC393/D.cpp -o D

// 線形時間で求めるには、式変換をする定期

// あかん、むずい
// 左右どちらからも求める手法はO(2N)で出来るようで、真ん中までしか判定できないので糞...

// Uターンの要領で、二通り試させる？
// ワ―シャルフロイド、お前なのか...?
// 前提が変わるのできつい
// 計算をしょうりゃくするんなら、あらかじめ演算すればいい
// 移動コストが左からきているか右からきているかの二通りしかありえないのなら
// (N, (2, 0))で演算できる？？
// iまでに寄せる計算量
// それを線探索して、足し合わせが一番低いのが勝ち
// 故に線形時間で解ける！