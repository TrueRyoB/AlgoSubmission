#include <bits/stdc++.h>
using namespace std;

struct pv {
  vector<int> lc, rc;
};
pv getMonotonicLR(vector<int> a) {
  int N = a.size();
  vector<int> lc(N, -1), rc(N, -1);

  stack<int> st;
  for(int i=0; i<N; ++i) {
    while(!st.empty()) {
      int x = st.top();
      if(a[x]>a[i]) break;
      lc[i]=x;
      st.pop();
    }
    if(!st.empty()) rc[st.top()]=i;
    st.push(i);
  }
  return {lc, rc};
}