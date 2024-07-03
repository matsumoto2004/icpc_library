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

/* SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X get(int a){return query(a,a+1);}
};

auto fx = [](ll x1, ll x2) -> ll { return min(x1, x2); };
ll ex = numeric_limits<ll>::max();

struct Compress{
    Vl v;
    void insert(ll x){
        v.push_back(x);
    }
    void init(){
        sort(all(v));
    }
    ll get(ll x){
        return lower_bound(all(v),x)-v.begin();
    }
};

int main(){
    ll n;
    cin >> n;
    VVl v(n,Vl(3));
    rep(i,n)rep(j,3) cin >> v[i][j];
    rep(i,n) sort(all(v[i]));
    Compress cp;
    rep(i,n)rep(j,3) cp.insert(v[i][j]);
    cp.init();
    rep(i,n)rep(j,3) v[i][j]=cp.get(v[i][j]);
    map<ll,vector<Pl>> mp;
    rep(i,n) mp[v[i][0]].emplace_back(v[i][1],v[i][2]);
    SegTree<ll> seg(6e5+5,fx,ex);
    seg.build();
    for(auto [a,bcs]:mp){
        for(auto bc:bcs){
            ll b=bc.F,c=bc.S;
            if(seg.query(0,b)<c){                
                cout << "Yes" << endl;
                return 0;
            }
        }
        for(auto bc:bcs){
            ll b=bc.F,c=bc.S;
            seg.update(b,min(seg.get(b),c));
        } 
    }
    cout << "No" << endl;
}