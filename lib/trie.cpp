#include <bits/stdc++.h>
using namespace std;

class Trie {
struct Node {
  int cnt=0;
  map<char, Node*> to;
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
      for(const auto e: n->to) s.push(e.second);
      delete n;
    }
  }
  int insert(string s) {
    Node* node = root; int res=0;
    for(const auto& c:s) {
      if(node->to.count(c)) res+= node->to[c]->cnt;
      else node->to[c] = new Node;

      node->to[c]->cnt++;
      node = node->to[c];
    }
    return res;
  }
};