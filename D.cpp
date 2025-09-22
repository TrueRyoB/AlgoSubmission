#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int di[] = {-1, -1, 1, 1};
constexpr int dj[] = {-1, 1, -1, 1};

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (const auto& e:v) os << e << " "; return os; }

int32_t main() {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);

  auto select = [&](int i, int j, vector<vector<int>>& g, int H, int W) {
    if(g[i][j]<0) return false;
    if(g[i][j]==0) return true;
    for(int k=0; k<4; ++k) {
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||ni>=H||nj<0||nj>=W) continue;
      if(g[i][j]==g[ni][nj]) g[ni][nj]=-1;
    }
    return true;
  };

  int T; cin>>T;
  while(T--) {
    int res=0;
    int H, W; cin>>H>>W;
    vector<vector<int>> g(H, vector<int>(W));
    for(int i=0; i<H; ++i) {
      string s; cin>>s;
      for(int j=0; j<W; ++j) g[i][j] = s[i]=='.'?0:-1;
    }
    int cnter=0;
    for(int i=1; i<H; ++i) {
      for(int j=1; j+1<W; ++j) {
        if(g[i][j]==0 || g[i-1][j]==0) continue;
        bool openleft=select(i-1, j-1, g, H, W)||select(i, j-1, g, H, W);
        bool openright=select(i-1, j+1, g, H, W)||select(i, j+1, g, H, W);

        if(openleft || openright) ++cnter;
        if(!openleft)g[i][j+1]=cnter;
        g[i][j]=cnter;
      }
    }
    
    cout << res << endl;
  }


  return 0;
}