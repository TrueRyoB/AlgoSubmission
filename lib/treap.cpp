#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  ll val, sum;
  int prio, cnt, sz;
  Node *l, *r;
  Node(ll v): val(v), sum(v), prio(rng()), cnt(1), sz(1), l(nullptr), r(nullptr){}
};

int size(Node* t) {return t?t->sz:0;}
ll sum(Node* t) {return t?t->sum:0;}

void pushup(Node* t) {
  if(!t) return;
  t->sz = t->cnt+size(t->l)+size(t->r);
  t->sum = (ll)t->cnt*t->val+sum(t->l)+sum(t->r);
}
void split(Node* t, ll key, Node*& a, Node*& b) {
  if(!t) {a=b=nullptr; return; }
  if(t->val <=key) {
    split(t->r, key, t->r, b);
    a=t;
  }else {
    split(t->l, key, a, t->l);
    b=t;
  }
  pushup(t);
}
Node* merge(Node* a, Node* b) {
  if(!a || !b) return a?a:b;
  if(a->prio > b->prio) {
    a->r=merge(a->r, b);
    pushup(a); 
    return a;
  }
  b->l=merge(a, b->l);
  pushup(b);
  return b;
}
void insert(Node*& t, ll x) {
  Node *a, *b;
  split(t, x, a, b);
  Node *c, *d;
  split(a, x-1, c, d);
  if(d) {
    d->cnt++;
    pushup(d);
  }else {
    d=new Node(x);
  }
  t=merge(merge(c,d),b);
}
ll k_sum(Node* t, int k) {
  if(!t || k<=0) return 0;
  int rs=size(t->r);
  if(rs>=k) return k_sum(t->r, k);

  ll res=sum(t->r);
  int take=min(k-rs, t->cnt);
  res+=(ll)take*t->val;
  return res+k_sum(t->l, k-rs-take);
}


//使用例
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Node* treap=nullptr;
  int N, Q; cin>>N>>Q;
  while(N--) {
    ll x; cin>>x;
    insert(treap, x);
  }
  while(Q--) {
    int k; cin>>k;
    cout << k_sum(treap, k) << endl;
  }

  return 0;
}