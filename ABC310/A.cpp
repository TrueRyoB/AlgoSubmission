#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// DP の状態：
//   penalty = Σ(A[i] - λ·B[i])
//   sumA    = ΣA[i]  (実際の満足度合計)
//   sumB    = ΣB[i]  (実際の満腹度合計)
struct Node {
    double penalty;
    ll sumA, sumB;
};

int N, M;
vector<ll> A, B;

// λ を固定したとき、
// パス上で隣接禁止に選べる集合の最適 DP を O(N) で実行し、
// 最終的な (penalty, sumA, sumB) を返す
Node solve_with_lambda(double lambda) {
    // dp0 = ベスト (i-1 までで末尾不選択)
    // dp1 = ベスト (i   で選択)
    Node dp0{0.0, 0, 0}, dp1{-1e18, 0, 0};
    for (int i = 0; i < N; i++) {
        // 遷移用に前の状態を退避
        Node old0 = dp0, old1 = dp1;

        // 1) i を選ばない → 新しい dp0
        //    末尾不選択なので、old0.old1 のどちらでも良い
        Node new0 = old0.penalty > old1.penalty ? old0 : old1;

        // 2) i を選ぶ → 新しい dp1
        //    隣接禁止なので、old0 からのみ遷移
        double pi = (double)A[i] - lambda * (double)B[i];
        Node cand1;
        cand1.penalty = old0.penalty + pi;
        cand1.sumA    = old0.sumA + A[i];
        cand1.sumB    = old0.sumB + B[i];

        // 更新
        dp0 = new0;
        dp1 = cand1;
    }

    // 最終的に末尾選択／不選択のうちペナルティが大きい方
    return dp0.penalty > dp1.penalty ? dp0 : dp1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // λ の二分探索の範囲：0 ～ max(A[i]/B[i])
    double lo = 0.0, hi = 0.0;
    for (int i = 0; i < N; i++) {
        hi = max(hi, (double)A[i] / (double)B[i]);
    }

    ll bestAns = 0;
    // 60 回程度探索すれば十分な精度
    for (int it = 0; it < 60; it++) {
        double mid = (lo + hi) / 2.0;
        Node res = solve_with_lambda(mid);

        if (res.sumB > M) {
            // 食べ過ぎ ⇒ ペナルティを重くする（λ を上げる）
            lo = mid;
        } else {
            // 食べ足りない or ちょうど ⇒ ペナルティを軽くする（λ を下げる）
            hi = mid;
            bestAns = max(bestAns, res.sumA);
        }
    }

    // hi または lo どちらでも構わないが、
    // 最後に使ったベスト sumA を出力
    cout << bestAns << "\n";
    return 0;
}

/*
高橋くんはお寿司屋さんに行きました。現在の空腹度はMです。お寿司がN個順番に流れてきます。
各お寿司に対して満足度上昇値（A）と満腹貢献度（B）が割り当てられています。
また、レールが高速な為、連続したお皿を取ることはできません。
達成可能な満足度の最大値を出力してください。

1 <= N, M <= 5*10^5
1 <= Ai, Bi <= 10^4

*/