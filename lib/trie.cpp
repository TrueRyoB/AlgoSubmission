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
  const int check(string s) {
    Node* node = root; int res=0;
    for(const auto& c:s) {
      if(!node->to.count(c)) return res;
      res+=node->to[c]->cnt;
      node=node->to[c];
    }
    return res;
  }
};