#ifndef LIB_NTT
#define LIB_NTT

#ifdef LOCAL
#include "std.hpp"
#endif

ll sqrtll(ll t) {
  ll l=0, r=t;
  while(l+1<r) {
    ll m=l+(r-l)/2;
    if(m<=t/m) l=m;
    else r=m;
  }
  return l;
}
ll lower_p2(int t) {
  ll r=1ll;
  while((r<<1)<t) r<<=1;
  return r;
}
ll upper_p2(int t) {
  ll r=1ll;
  while(r<t) r<<=1;
  return r;
}
ll upper_log2(int t) {
  int r=1;
  while((1ll<<r)<t) ++r;
  return r;
}

struct ModCtx {
  ll MOD, G;
  vector<int> rev;
  vector<ll> roots, iroots;
  ModCtx(ll mod, ll g, int len=1000000): MOD(mod), G(g) {
    assert(validateMod(upper_log2(len)) && validateG());
  }

  bool validateG() {
    ll t=MOD-1;
    vector<ll> ft;
    for(ll i=2; i*i<=t; ++i) if(t%i==0) {
      ft.push_back(i); while(t%i==0) t/=i;
    }
    if(t>1) ft.push_back(t);

    for(const auto& q:ft) if(modpow(G, (MOD-1)/q)==1) return false;
    return true;
  }

  bool validateMod(int minlog) {
    ll t=MOD-1; 
    int cnt=0;
    while((t&1)==0) t>>=1, ++cnt;
    return cnt>=minlog;
  }

  ll modpow(ll a, ll e) {
    ll r={1};
    while(e) {
      if(e&1) r=r*a%MOD;
      a=a*a%MOD;
      e>>=1;
    }
    return r;
  }

  ll modinv(ll a) {
    return modpow(a, MOD-2);
  }

  void prepare_ntt(int n) {
    if(rev.size()==n) return;
    rev.assign(n, 0);
    int k=__builtin_ctz(n);
    for(int i=0; i<n; ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));

    roots.resize(n); iroots.resize(n);
    ll root=modpow(G, (MOD-1)/n), iroot=modinv(root);
    roots[0]=iroots[0]=1;
    for(int i=1; i<n; ++i) {
      roots[i]=roots[i-1]*root%MOD;
      iroots[i]=iroots[i-1]*iroot%MOD;
    }
  }

  void ntt(vector<ll>& A, bool invert) {
    int n=A.size();
    prepare_ntt(n);
    
    for(int i=0; i<n; ++i) if(i<rev[i]) swap(A[i], A[rev[i]]);

    for(int len=2; len<=n; len<<=1) for(int i=0, step=n/len; i<n; i+=len) for(int j=0; j<len/2; ++j) {
      ll u=A[i+j], v=A[i+j+len/2]*(invert ? iroots[step*j]:roots[step*j])%MOD;
      A[i+j]=(u+v)%MOD;
      A[i+j+len/2]=(u-v+MOD)%MOD;
    }

    if(invert) {
      ll invn=modinv(n); for(auto& e:A) e=e*invn%MOD;
    }
  }

  vector<ll> convolution(vector<ll> A, vector<ll> B) {
    int N=upper_p2(A.size()+B.size()-1);
    A.resize(N); B.resize(N);
    cout << "ccc" << endl;
    ntt(A, false);
    ntt(B, false);
    for(int i=0; i<N; ++i) A[i]=A[i]*B[i]%MOD;

    ntt(A, true);
    return A;
  }

  vector<ll> taylor_shift(const vector<ll>& C, ll a) {
    int n=C.size();
    
    vector<ll> facto(n), ifacto(n); 
    facto[0]={1}; for(int i=1; i<n; ++i) facto[i]=facto[i-1]*i%MOD;
    ifacto[n-1]=modinv(facto[n-1]); for(int i=n-1; i>0; --i) ifacto[i-1]=ifacto[i]*i%MOD;

    vector<ll> A(n), B(n);
    for(int i=0; i<n; ++i) {
      A[i]=C[i]*facto[i]%MOD;
      B[i]=modpow(a, i)*ifacto[i]%MOD;
    }
    reverse(A.begin(), A.end());
    vector<ll> cov = convolution(A, B);

    vector<ll> res(n); for(int i=0; i<n; ++i) res[i]=cov[n-1-i]*ifacto[i]%MOD;
    return res;
  }

  vector<ll> poly_inv(const vector<ll>& f, int k) {
    vector<ll> g(1, modinv(f[0])); 
    int n=g.size();
    while(n<k) {
      n<<=1;

      vector<ll> f_cut(min(n, (int)f.size()));
      for(int i=0; i<f_cut.size(); ++i) f_cut[i]=f[i];

      vector<ll> g_ext=g; g_ext.resize(n);

      vector<ll> t=convolution(f_cut, g_ext); t.resize(n);
      for(int i=0; i<n; ++i) t[i]=(MOD-t[i])%MOD;
      t[0]=(t[0]+2)%MOD;

      g=convolution(g_ext, t); g.resize(n);
    }
    g.resize(k);
    return g;
  }

  vector<ll> poly_mod(vector<ll> A, vector<ll> B) {
    int n=A.size(), m=B.size();
    if(n<m) return A;

    reverse(A.begin(), A.end()); reverse(B.begin(), B.end());

    int k=n-m+1;
    A.resize(k); B.resize(k);

    vector<ll> Q=convolution(A, poly_inv(B, k));
    Q.resize(k); 
    reverse(Q.begin(), Q.end());

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<ll> R(n), QB=convolution(Q, B);
    for(int i=0; i<n; ++i) R[i]=(i>=QB.size()) ? A[i] : (A[i]-QB[i]+MOD)%MOD;
    R.resize(m-1);
    return R;
  }

  vector<ll> multipoint_eval(const vector<ll>& C, const vector<ll>& XS) {
    int n=XS.size();
    vector<ll> res(n);

    int m=upper_p2(n);
    vector<vector<ll>> v; v.assign(2*m, {1});
    for(int i=0; i<n; ++i) v[i+m]={(MOD-XS[i]%MOD), 1};
    for(int i=m-1; i>0; --i) v[i]=convolution(v[i*2], v[i*2+1]);

    

    auto query = [&](int a, int b, int k, int l, int r, const auto& query) {
      if(r<=a || b<=l) return vector<ll>{1};
      if(a<=l && r<=b) return v[k];
      int m=l+(r-l)/2;
      return convolution(query(a,b,k*2,l,m, query), query(a,b,k*2+1,m,r, query));
    };

    auto fetch = [&](int a, int b) {
      return query(a, b, 1, 0, m, query);
    };

    auto dfs = [&](int l, int r, const vector<ll>& f, const auto& dfs)->void {
      if(f.empty()) {
        for(int i=l; i<r; ++i) res[i]=0; 
        return;
      }
      if(r-l==1) {
        res[l]=f[0];
        return;
      }

      int m=(l+r)/2;
      vector<ll> fmod=poly_mod(f, fetch(l, r));
      
      dfs(l, m, poly_mod(fmod, fetch(l, m)), dfs);
      dfs(m, r, poly_mod(fmod, fetch(m, r)), dfs);
    };

    dfs(0, n, C, dfs);
    return res;
  }
};

#endif