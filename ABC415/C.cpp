#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int T; cin>>T;

    while(T--) {
        int N; cin>>N;
        string s; cin>>s; s = "0"+s;
        int len = (1<<N);
        vector<bool> dp(len, false); dp[0]=true;
        for(int i=0; i<len; ++i) {
            if(s[i]=='0' && dp[i]) {
                for(int bit=0; bit<N; ++bit) {
                    if((i & (1<<bit)) != 0) continue;
                    int next = (1<<bit) + i;
                    if(s[next]=='0') dp[next]=true;
                }
            }
        }
        if(dp[len-1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
//今回糞バグらせたりしてレートも(上がってはいるけど)ほんまに終わってる結果になった
//でも、今週は他のことに時間費やしてたからパフォ悪くても罪悪感とかなくて
//むしろ健全に復習できているので、かえって効率のいい精進方法なのかもしれない(こなみ)