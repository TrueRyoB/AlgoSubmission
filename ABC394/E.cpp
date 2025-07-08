#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
#define overload4(a, b, c, d, name, ...) name
#define rep1(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
bool chmin(auto &a, const auto &b) {
    if (a <= b) return 0;
    a = b;
    return 1;
}
bool chmax(auto &a, const auto &b) {
    if (a >= b) return 0;
    a = b;
    return 1;
}
void solve();
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}
void solve() {
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector dist(n, vector<ll>(n, -1));
    queue<pair<ll, ll>> q;
    rep(i, n) {
        dist[i][i] = 0;
        q.push({i, i});
    }
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            if (s[i][j] != '-') {
                dist[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        rep(i, n) {
            if (s[i][y] == '-') continue;
            rep(j, n) {
                if (s[x][j] == '-') continue;
                if (s[i][y] != s[x][j]) continue;
                if (dist[i][j] == -1 || dist[i][j] > dist[y][x] + 2) {
                    dist[i][j] = dist[y][x] + 2;
                    q.push({i, j});
                }
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (dist[i][j] == -1) {
                cout << -1;
            } else {
                cout << dist[i][j];
            }
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}
//https://atcoder.jp/contests/abc394/submissions/67410442