#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素  //遅延セグ木使うときは注意
#define S second //pairの二つ目の要素  //遅延セグ木使うときは注意
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pl = pair<ll, ll>;
using Vs = vector<string>;
const ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

#pragma once

template <typename T, typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) { return h * 2 * W + w; }

 public:
  int H, W;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree2D(int h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

ll fx(ll x,ll y){return max(x,y);}
ll ex=0;

int main(){
    ll h,w,h1,w1,h2,w2;
    cin >> h >> w >> h1 >> w1 >> h2 >> w2;
    chmin(h2,h1);
    chmin(w2,w1);
    VVl v(h,Vl(w));
    rep(i,h)rep(j,w) cin >> v[i][j];
    VVl sum(h+5,Vl(w+5));
    rep(i,h)rep(j,w) sum[i+1][j+1]=v[i][j];
    rep(i,h+1)rep(j,w+1) sum[i+1][j]+=sum[i][j];
    rep(i,h+1)rep(j,w+1) sum[i][j+1]+=sum[i][j];
    ll ans=0;
    VVl scorea(h+5,Vl(w+5));
    VVl scoreb(h+5,Vl(w+5));
    for(int i=0;i+h1<=h;i++){
        for(int j=0;j+w1<=w;j++){
            scorea[i][j]=sum[i+h1][j+w1]-sum[i][j+w1]-sum[i+h1][j]+sum[i][j];
        }
    }
    for(int i=0;i+h2<=h;i++){
        for(int j=0;j+w2<=w;j++){
            scoreb[i][j]=sum[i+h2][j+w2]-sum[i][j+w2]-sum[i+h2][j]+sum[i][j];
        }
    }

    SegmentTree2D seg(h+5,w+5,fx,ex);
    for(int i=0;i+h2<=h;i++){
        for(int j=0;j+w2<=w;j++){
            seg.set(i,j,scoreb[i][j]);
        }
    }
    seg.build();
    for(int i=0;i+h1<=h;i++){
        for(int j=0;j+w1<=w;j++){
            ll score=scorea[i][j];
            score-=seg.query(i,j,i+h1-h2+1,j+w1-w2+1);
            chmax(ans,score);
            //cout << scorea[i][j] << endl;
        }
    }
    cout << ans << endl;
}