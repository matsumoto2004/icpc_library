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

/* SegTreeLazy<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm, 単位元ex,em)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X, typename M>
struct SegTreeLazy {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazy(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
        : n(), fx(fx_), fa(fa_), fm(fm_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], lazy[k]);
        lazy[k] = em;
    }
    void update(int a, int b, M x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
};

struct X{
    ll value;
    ll size;
};
using M = ll;
auto fx = [](X x1, X x2) -> X { return {x1.value+x2.value,x1.size+x2.size}; };
auto fa = [](X x, M m) -> X {
    if(m!=-1) x.value=m*x.size;
    return x;
};
auto fm = [](M m1, M m2) -> M {
    if(m2!=-1) return m2;
    else return m1;
};
X ex = {0,0};
ll em = -1;

int main(){
    ll n,q,x;
    cin >> n >> q >> x;
    x--;
    Vl v(n);
    rep(i,n) cin >> v[i];
    rep(i,n) v[i]--;
    ll whe=-1;
    SegTreeLazy<X,M> seg1(n+5,fx,fa,fm,ex,em),seg2(n+5,fx,fa,fm,ex,em);
    rep(i,n){
        if(v[i]<x){
            seg1.set(i,{1,1});
            seg2.set(i,{0,1});
        }
        if(v[i]==x){
            whe=i;
            seg1.set(i,{0,1});
            seg2.set(i,{0,1});
        }
        if(v[i]>x){
            seg1.set(i,{0,1});
            seg2.set(i,{1,1});
        }
    }
    seg1.build();
    seg2.build();
    rep(query,q){
        ll c,l,r;
        cin >> c >> l >> r;
        l--;r--;
        ll cnt1=seg1.query(l,r+1).value;
        ll cnt2=seg2.query(l,r+1).value;

        if(c==1){
            seg1.update(l,l+cnt1,1);
            seg1.update(l+cnt1,r+1,0);
            seg2.update(l,r-cnt2+1,0);
            seg2.update(r-cnt2+1,r+1,1);
            if(whe>=l&&whe<=r){
                whe=l+cnt1;
            }
        }
        if(c==2){
            seg1.update(l,r-cnt1+1,0);
            seg1.update(r-cnt1+1,r+1,1);
            seg2.update(l,l+cnt2,1);
            seg2.update(l+cnt2,r+1,0);
            if(whe>=l&&whe<=r){
                whe=l+cnt2;
            }
        }
    }
    cout << whe+1 << endl;
}