#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* TODO */
constexpr int seed = -1;
constexpr string_view fpath = "dist/input.txt";
constexpr string_view opath = "dist/output.txt";

/*<struct, method, and constant>*/

ll rd_uniform(ll L, ll R, mt19937_64& rng) {
  uniform_int_distribution<ll> dist(L,R);
  return dist(rng);
}
void rd_uniform_fill(vector<ll>& v, ll L, ll R, mt19937_64& rng) {
  uniform_int_distribution<ll> dist(L,R);
  for(auto& e:v) e=dist(rng);
}

ll rd_norm(double mu, double std, ll L, ll R, mt19937_64& rng) {
  normal_distribution<double> dist(mu, std);
  while(true) {
    ll x=llround(dist(rng));
    if(L<=x&&x<=R) return x;
  }
}
void rd_norm_fill(vector<ll>& v, double mu, double std, ll L, ll R, mt19937_64& rng) {
  normal_distribution<double> dist(mu, std);
  for(auto& e:v) while(true) {
    ll x=llround(dist(rng));
    if(x<L||R<x) continue;
    e=x; break; 
  }
}

ll rd_geometric(double p, ll L, ll R, mt19937_64& rng) {
  geometric_distribution<ll> dist(p);
  return min(dist(rng), R-L)+L;
}
void rd_geometric_fill(vector<ll>& v, double p, ll L, ll R, mt19937_64& rng) {
  geometric_distribution<ll> dist(p);
  for(auto& e:v) e=min(dist(rng), R-L)+L;
}

ll rd_log(ll L, ll R, mt19937_64& rng) {
  uniform_real_distribution<double> dist(log(L), log(R));
  return llround(exp(dist(rng)));
}
void rd_log_fill(vector<ll>& v, ll L, ll R, mt19937_64& rng) {
  uniform_real_distribution<double> dist(log(L), log(R));
  for(auto& e:v) e=llround(exp(dist(rng)));
}

// For an output
int32_t generate(ifstream& cin, ofstream& cout) {

  /* TODO */
  /* TODO */
  return 0;
}

// For an input
int32_t generate(ofstream& cout) {
  static mt19937_64 rng(seed<0?chrono::steady_clock::now().time_since_epoch().count():seed);
  
  /* TODO */
  /* TODO */
  return 0;
}

int32_t genIn() {
  ofstream dist(fpath.data());

  if(!dist.is_open()) {
    cerr<<"Error: Unable to open file " << fpath << endl;
    return 1;
  }

  try{
    generate(dist);
  }
  catch (const exception&) {
    cerr<<"Error: input file generation aborted"<<endl;
    return 1;
  }
  cout << "File " << fpath << " generated successfully!" << endl;
  return 0;
}

int32_t genOut() {
  ifstream from(fpath.data());
  ofstream dist(opath.data());

  if(!from.is_open()) {
    cerr<<"Error: Unable to open file "<< fpath << endl;
    return 1;
  }

  if(!dist.is_open()) {
    cerr<<"Error: Unable to open file "<< opath << endl;
    return 1;
  }

  try {
    generate(from, dist);
  }
  catch (const exception&) {
    cerr<<"Error: output file generation aborted"<<endl;
    return 1;
  }
  cout << "File " << opath << " generated successfully!" << endl;
  from.close();
  return 0;
}

int32_t main() {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);

  if(genIn()==1) return 1;
  return genOut();
}