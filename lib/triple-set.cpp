#include <unordered_set>
#include <tuple>
#include <functional>
using namespace std;

struct TupleHash {
  template<typename T>
  size_t operator()(const tuple<T,T,T>& t) const {
    auto [a, b, c]=t;
    size_t seed = hash<T>{}(a);
    seed^=hash<T>{}(b)+0x9e3779b9+(seed<<6)+(seed>>2);
    seed^=hash<T>{}(c)+0x9e3779b9+(seed<<6)+(seed>>2);
    return seed;
  }
};

struct TripleSet {
  unordered_set<
    tuple<int,int,int>,
    TupleHash,
    equal_to<tuple<int,int,int>>
  > tripleSet;

  void emplace(int a,int b, int c){
    tripleSet.emplace(a, b, c);
  }
  bool contains(int a, int b, int c){
    return tripleSet.find(make_tuple(a,b,c))!=tripleSet.end();
  }
  size_t size() const {
    return tripleSet.size();
  }
  void reserve(size_t n) {
    tripleSet.reserve(n);
  }
};