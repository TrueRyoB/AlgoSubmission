#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define int long long

int32_t main() {
    int N=6; vector<int> v(N);
    for(int i=1; i<N; ++i) {
        cin>>v[i];
    }
    int cnt = 0; bool safe = true;
    for(int i=1; i<N-1; ++i) {
        if(v[i] == i+1 && v[i+1] == i) {
            ++cnt; ++i;
        }
        else if(v[i] != i) safe = false;
    }
    if(safe && cnt == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}//g++ -Wall -Wextra -g -std=c++20 ABC390/C.cpp -o C