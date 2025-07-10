#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

int32_t main() {
    //0にするやつをbit全探索で決めて
    //その分配を順列でする
    //ガチ脳死戦法

    int N; cin>>N;
    for(int i=1; i<(1<<N); ++i) {//1:残る　0:死ぬ
        //分配方法わからん...
        //dfsでも使ってみる..?
        //vectorのコピー作ることに恐怖心しか感じないので、却下...
    }
    //これ4分で解いたんか...
    //C2分も衝撃

    return 0;
}