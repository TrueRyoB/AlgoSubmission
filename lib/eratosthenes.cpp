#include <bits/stdc++.h>
using namespace std;

class Sieve {
private:
int n;
vector<int> primes;

public:
  Sieve(int n) :n(n) {
    vector<bool> isprime(n+1, true); isprime[0]=isprime[1]=false;
    for(int p=2; p<=n; ++p) {
      if(!isprime[p]) continue;
      primes.push_back(p);
      for(int q=p*2; q<=n; q+=p) isprime[q]=false;
    }
  }
  bool isPrime(int val) {
    return val<n ? primes[val]:false;
  }
  int findClosestPrime(int val) {
    int l=0, r=n;
    while(l+1<r) {
      int m=l+(r-l)/2;
      if(primes[m]<=val) l=m;
      else r=m;
    }
    return l+1<n && abs(primes[l+1]-val)<abs(primes[l]-val) ? primes[l+1] : primes[l];
  }
};