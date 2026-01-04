#ifndef LIB_MAT
#define LIB_MAT

#ifdef LOCAL
#include "std.hpp"
#endif

template<class T, class = void>
struct Field : false_type {};

template<class T>
struct Field<T, void_t<
  decltype(T{0}),
  decltype(T{1}),
  decltype(T{} + T{}),
  decltype(T{} * T{})
>> : true_type {};


struct zero_init_t {};
struct identity_init_t {};

inline constexpr zero_init_t zero_init{};
inline constexpr identity_init_t identity_init{};

template<class T>
struct Mat {
  int H, W, HW;
  vector<T> m;
  T det; //det:
  bool det_valid;

private:
  Mat(int H, int W, bool): H(H), W(W), HW(H*W), det_valid(true) {
    m.resize(HW);
  }

public:
  Mat(int H, int W, zero_init_t)
    : Mat(H, W, true) 
  {
    for(auto& e:m)e=T{};
    det=T{0};//det:
  }

  Mat(int N, zero_init_t)
    : Mat(N, N, true)
  {
    for(auto& e:m)e=T{};
    det=T{0};//det:
  }

  Mat(int N, identity_init_t)
    : Mat(N, N, true)
  {
    for(auto& e:m)e=T{};
    for(int i=0; i<N; ++i) m[i*W+i]=T{1};
    det=T{1};//det:
  }
  
  static Mat identity(int N) {
    Mat r(N, N, zero_init);
    for(int i=0; i<N; ++i) r.m[i*N + i] = T{1};
    r.det=T{1};//det:
    return r;
  }
  inline int h() const {
    return H;
  }
  inline int w() const {
    return W;
  }
  inline pair<int, int> size() const {
    return {H, W};
  }

  inline Mat& fill() {
    for(auto& e:m) cin>>e;
    return *this;
  }

  void print(ostream& os) const {
    for(int i=0; i<H; ++i) {
      for(int j=0; j<W; ++j) os<<m[i*W+j]<<'\t';
      os<<endl;
    }
  }

  friend ostream& operator<<(ostream& os, const Mat& a) {
    return a.print(os), os;
  }

  inline const T& operator()(int i, int j) {
    assert(0<=i && i<H); assert(0<=j && j<W);
    return m[i*W+j];
  }

  vector<T> col(int j) const {
    assert(0<=j && j<W);
    vector<T> res; res.reserve(H);
    for(int i=0; i<H; ++i) res.push_back(m[i*W+j]);
    return res;
  }
  
  vector<T> row(int i) const {
    assert(0<=i && i<H);
    vector<T> res; res.reserve(W);
    for(int j=0; j<W; ++j) res.push_back(m[i*W+j]);
    return res;
  }

  template<T (*F)(T, T)>
  inline Mat& apply(const Mat& t) {
    assert(size() == t.size());
    T* __restrict__ a=m.data();
    const T* __restrict__ b=t.m.data();
    for(int i=0; i<HW; ++i) F(a[i], b[i]);
    return *this;
  }

  static T add(T a, T b) { return a+b; }
  static T sub(T a, T b) { return a-b; }
  Mat& operator+=(const Mat &t) { return apply<add>(t); }
  Mat& operator-=(const Mat &t) { return apply<sub>(t); }

  template<class G>
  Mat& operator*=(const G mul) {
    static_assert(is_integral_v<G>);
    det*=mul; //det: 
    for(auto& e:m) e*=mul; //TODO: lazy application might be better for a static value
    return *this;
  }

  Mat& operator*=(const Mat &t) {
    assert(W==t.H);
    Mat res(H, t.W, zero_init);

    const T* __restrict__ a=m.data();
    const T* __restrict__ b=t.m.data();
    T* __restrict__ c=res.m.data();

    for(int i=0; i<H; ++i) for(int j=0; j<t.W; ++j) {
      T sum=0;
      for(int k=0; k<W; ++k) sum+=a[i*W+k]*b[k*t.W+j];
      c[i*t.W+j]=sum;
    }
    res.det = det*t.det; //det: 
    return *this=move(res);
  }

  template<class G>
  Mat& pow(G N) {
    static_assert(is_integral_v<G>, "matrix power requires an integral exponent");
    assert(N>=0 && W==H);
    Mat base=*this;
    Mat res(H, identity_init);
    while(N>0) {
      if(N&1) res*=base;
      base*=base;
      N>>=1;
    }
    return *this=move(res);
  }

  bool allzero(int i) const {
    assert(0<=i && i<H);
    for(int j=0; j<W; ++j) if(m[i*W+j]!=0) return false;
    return true;
  }
  void swap_row(int a, int b) {
    assert(0<=a && a<H && 0<=b && b<H);
    if(a==b)return;
    for(int j=0; j<W; ++j) swap(m[a*W+j], m[b*W+j]);
  }

  Mat<T>& rref() {
    static_assert(Field<T>::value, "T must satisfy Field");
    int zrcnt=0;
    for(int i=H-1; i>=0; --i) {
      if(!allzero(i)) continue;
      swap_row(i, H-zrcnt-1); ++zrcnt;
    }

    int pivot_row=0;
    for(int col=0; col<W && pivot_row<H-zrcnt; ++col) {
      int p=-1;
      for(int row=pivot_row; row<H-zrcnt; ++row) if(m[row*W+col]!=0) {
        p=row; break;
      }
      if(p==-1) continue;
      if(p!=pivot_row) swap_row(p, pivot_row);

      T pval=m[pivot_row*W+col];
      for(int j=col; j<W; ++j) m[pivot_row*W+j] /=pval;

      for(int row=0; row<H-zrcnt; ++row) {
        if(row==pivot_row) continue;
        T factor=m[row*W+col];
        if(factor!=0) for(int j=col; j<W; ++j) m[row*W+j]-=factor*m[pivot_row*W+j];
      }
      ++pivot_row;
    }

    det=(zrcnt==0)?1:0;
    return *this;
  }

  template<class R, class Op, class F>
  R fold(R init, Op&& op, F&& f) const {
    R res = init;
    for(int i=0; i<HW; ++i) res=op(res, f(m[i]));
    return res;
  }
  template<class F>
  T fold_sum(F&& f) const {
    return fold(T{}, plus<T>{}, forward<F>(f));
  }
  T sum() const {
    return fold_sum([](const T& x){ return x; });
  }
  template<class F>
  T fold_xor(F&& f) const {
    return fold(T{}, bit_xor<T>{}, forward<F>(f));
  }
  T fold_min() const {
    return fold(
      numeric_limits<T>::max(),
      [](const T& a, const T& b){ return min(a, b); },
      [](const T& x){ return x; }
    );
  }

  //inverse matrix

  //transpose

  //det
};


#endif