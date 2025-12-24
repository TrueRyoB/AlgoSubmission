#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7ll;

//for modulo non-modulo
static int c[31][31]={{0}};
void pascal() {
  if(c[0][0]==1) return; c[0][0]=1;
  for(int i=1; i<=30; ++i) {
    c[i][0]=c[i][i]=1;
    for(int j=1; j<=i/2; ++j) c[i][j]=c[i][i-j]=c[i-1][j-1]+c[i-1][j]%MOD;
  }
}

//for modulo prime
ll qpow(ll a, ll r) {
  ll res=1ll;
  while(r>0) {
    if(r&1) (res*=a)%=MOD;
    (a*=a)%=MOD;
    r>>=1;
  }
  return res;
}

int32_t main() {
  int N; cin>>N;
  vector<ll> facto(N+1); facto[0]=1; 
  for(int i=1; i<=N; ++i) facto[i]=facto[i-1]*i%MOD;
  vector<ll> inv(N+1); inv[N]=qpow(facto[N], MOD-2);
  for(int i=N-1; i>=0; --i) inv[i]=inv[i+1]*(i+1)%MOD;

  auto nCk = [&](ll n, ll k) {
    return (facto[n]*inv[n-k]%MOD)*inv[k]%MOD;
  };

  return 0;
}