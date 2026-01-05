#ifndef LIB_TRIE
#define LIB_TRIE

#include <stack>
#include <map>

#ifdef LOCAL
#include "std.hpp"
#endif

class Trie {
struct Node {
  int cnt=0;
  map<char, Node*> g;
};

private:
Node* root;

public:
  Trie() {
    root = new Node();
  }
  ~Trie() {
    stack<Node*> s; s.push(root);
    while(!s.empty()) {
      const Node* n = s.top(); s.pop();
      for(const auto& e: n->g) s.push(e.second);
      delete n;
    }
  }
  bool remove(string s) {
    Node* u = root;
    queue<Node*> q;
    for(const auto& e:s) {
      if(!u->g.count(e)) return false;
      u=u->g[e];
      q.push(u);
    }
    while(!q.empty()) {
      const auto u = q.front(); q.pop();
      --(u->cnt);
    }
    return true;
  }
  int insert(string s) {
    Node* u = root;
    int res=0, N=(int)s.size();
    for(int i=0; i<N; ++i) {
      const auto v=s[i];
      if(!u->g.count(v)) u->g[v]=new Node;
      if(u->g[v]->cnt++>0)  res=i+1;
      u=u->g[v];
    }
    return res;
  }
};

#endif