#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    auto manacher = [&](string s) {
        int i=0, j=0, N=s.size();
        vector<int> r(N);
        while(i < N) {
            while(i-j>=0 && i+j<s.size() && s[i-j]==s[i+j]) ++j;
            r[i] = j;
            int k=1;
            while(i-k>=0 && k+r[i-k]<j) r[i+k]=r[i-k];
            i += k;
            j -= k;
        }
    };

    string s; cin>>s;
    for(const auto& e:manacher(s)) cout << e << " ";

    return 0;
}