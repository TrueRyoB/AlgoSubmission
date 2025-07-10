#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define int long long

//諦めます。。。

int32_t main() {
    int H, W; cin>>H>>W;
    vector<string> v(H); for(auto& e:v) cin>>e;

    bool insideBlack = false; bool passedblock=false;
    int leftmin, leftmax, rightmin, rightmax;
    for(int i=0; i<W; ++i) {
        if(!insideBlack && v[0][i]=='?' && !passedblock){
            leftmin=i; continue;
        }
        if(v[0][i]=='.' && v[0][i-1]=='?') {
            leftmin=W-1;
        }
        if(!insideBlack && v[0][i]=='#') {
            if(passedblock) {
                cout << "No"; return 0;
            }
            leftmin=min(leftmin, i);
            leftmax=i; insideBlack=true; continue;
        }
        if(insideBlack && v[0][i]=='?') {
            rightmax=i; continue;
        }
        if(insideBlack && v[0][i]=='#' && v[0][i-1]=='?') {
            rightmax=i;rightmin=i; continue;
        }
        if(insideBlack && v[0][i]=='.') {
            rightmin=i; insideBlack=false; passedblock=true; continue;
        }
    }
    
    for(int r=1; r<H; ++r) {
        bool safe=false;
        
        for(int c=0; c<W; ++c) {
            if(v[r][c]=='#' && (c<leftmin || rightmax<c)) {
                safe=false; break;
            }
            if(v[r][c]=='.' && (leftmax <= c&& c<=rightmin)) {
                safe=false;break;
            }
            
            if(v[r][c]=='.'&& (leftmin <=c)) {
                leftmin=c;
            }
            else if(v[r][c]=='#' && (leftmin <=c && c <= leftmax)) {
                leftmax=c;
            }
            else if(v[r][c]=='.'&& (c <= rightmax)) {
                rightmax=c;
            }
            else if(v[r][c]=='#' && (rightmin <=c)) {
                rightmin=c;
            }
        }
        if(!safe) {
            cout << "No"; return 0;
        }
    }
    cout << "Yes";

    return 0;
}