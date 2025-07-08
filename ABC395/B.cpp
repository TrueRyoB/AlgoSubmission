#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;
    string s = "";

    for(int r=0; r<N; ++r) {
        s+='#'; char lastpick='#'; 
        int ag = min(N-r-1, r); /*cout << "ag is at " << ag << endl;*/
        for(int c=1; c<N; ++c) {
            bool flip = (c<=ag || c>=N-ag);
            if(flip) {
                lastpick=(lastpick=='#')?'.':'#';
                s+=lastpick;
            } else {
                s+=lastpick;
            }
        }
        s+='\n';
    }

    cout << s;

    return 0;
}