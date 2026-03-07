#ifndef LIB_DISCRETE
#define LIB_DISCRETE

#ifndef LIB_STD
#include "std.hpp"
#endif

int mex(const vector<int>& v) {
  int N=v.size();
  vector<char> seen(N, 0);
  for(const int& e:v) if(0<=e && e<N) seen[e]=1;
  for(int i=0; i<N; ++i) if(!seen[i]) return i;
  return N;
}


#endif