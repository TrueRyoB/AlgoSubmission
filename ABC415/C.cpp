#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int T; cin>>T;

    while(T--) {
        int N; cin>>N;
        string s; cin>>s;
        int len = (1<<N);
        vector<bool> dp(len, false); dp[0]=true;
        for(int i=0; i<len-1; ++i) {
            if(s[i]=='0') {
                int base = i+1;
                for(int bit=base-1; bit>=0; --bit) {
                    if((base & (1 << bit)) == 0)continue;
                    int val = base - (1<<bit);
                    if(dp[val]) {
                        dp[base]=true;
                        break;
                    }
                }
            }
        }
        if(dp[len-1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
//絶対通るべきなのに、通らなくて萎えそう
//risk at 1
//safe at 2
//safe at 1+2


//今日の反省

//想定解じゃなさそうなのに、コードを変えなかった
//デバッグにかなりの時間を費やしていた
//問題読解にかなりの時間をかけていた
//C問題もD問題も解けない...
//まだ灰色...