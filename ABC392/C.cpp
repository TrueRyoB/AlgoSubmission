#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define int long long

int32_t main() {
    int N; cin>>N;

    vector<int> p(N+1);
    for(int i=1; i<=N; ++i) cin>>p[i];
    vector<int> q(N+1); 
    for(int i=1; i<=N; ++i) cin>>q[i];
    vector<int> ztop(N+1);
    for(int i=1; i<=N; ++i) ztop[q[i]] = i;

    for(int i=1; i<=N; ++i) {
        cout << q[p[ztop[i]]] << " ";
    }

    return 0;
}//g++ -Wall -Wextra -g -std=c++20 ABC392/C.cpp -o C