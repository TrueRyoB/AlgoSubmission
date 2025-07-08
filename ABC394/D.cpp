#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    string s; cin>>s; int N=s.size();

    stack<char> st; bool safe = true;
    for(int i=0; i<N; ++i) {
        if(s[i]=='['||s[i]=='('||s[i]=='<') {
            st.push(s[i]);
        } else {
            if(st.size()==0) {
                safe = false; break;
            }
            char t = st.top();

            if(
                (s[i]==']'&&t=='[') ||
                (s[i]==')'&&t=='(') ||
                (s[i]=='>'&&t=='<')
            ) {
                st.pop();
            } else {
                safe = false; break;
            }
        }
    }
    if(safe && (st.size()==0)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}