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

template<typename T>
struct TripleSet {
  unordered_set<
    tuple<T,T,T>,
    TupleHash,
    equal_to<tuple<T,T,T>>
  > tripleSet;

  void emplace(T a,T b, T c){
    tripleSet.emplace(a, b, c);
  }
  bool contains(T a, T b, T c){
    return tripleSet.find(make_tuple(a,b,c))!=tripleSet.end();
  }
  size_t size() const {
    return tripleSet.size();
  }
  void reserve(size_t n) {
    tripleSet.reserve(n);
  }
};