#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define BUFF ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const int INF = 1e18+5;

signed main()
{
    BUFF;
    int n,num; cin >> n;

    vi k(n);
    vector<map<int,int>> used(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            cin >> num;
            used[i][num]++;
        }
    }

    double res = 0.0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double aux = 0;
            for(auto [u, times] : used[i]) {
                if(used[j].find(u) != used[j].end()) {
                    aux += ((double)1.0*used[j][u]/k[j])*((double)1.0*times/k[i]);
                }
            }

            res= max(res, aux);
        }
    }

    cout << fixed << setprecision(15) << res << endl;

    return 0; 
}
//https://atcoder.jp/contests/abc392/submissions/67473440