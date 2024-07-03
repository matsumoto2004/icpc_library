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
};

auto fx = [](long double x1, long double x2) -> long double { return x1+x2; };
long double ex = 0LL;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    SegTree<long double> goal(n+m+5,fx,ex);
    SegTree<long double> reset(n+m+5,fx,ex);
    rep(i,m) goal.set(n+i,1);
    Vl isreset(n+m+5);
    rep(i,k){
        ll x;
        cin >> x;
        reset.set(x,1);
        isreset[x]++;
    }
    goal.build();
    reset.build();
    repd(i,n){
        if(isreset[i]) continue;
        goal.update(i,goal.query(i+1,i+m+1)/m);
        reset.update(i,reset.query(i+1,i+m+1)/m);
    }
    long double getreset=reset.query(0,1);
    if(abs(getreset-1)<=0.00001){
        cout << -1 << endl;
        return 0;
    }
    //これでresetを食らわない確率は求まった
    
    SegTree<long double> expect(n+m+5,fx,ex);
    vector<long double> visitprob(n+m+5,0);
    visitprob[0]=1;
    visitprob[1]=-1;
    expect.build();

    rep(i,n){
        if(i!=0) visitprob[i]+=visitprob[i-1];
        if(isreset[i]) continue;
        visitprob[i+1]+=visitprob[i]/m;
        visitprob[i+m+1]-=visitprob[i]/m;
    }
    visitprob[n]=1-getreset;
    rrep(i,1,n+1){
        long double now=expect.query(max(i-m,0LL),i);
        now+=visitprob[i];
        expect.update(i,now);
    }
    long double ans=expect.query(n,n+1);
    ans/=(1-getreset);
    ans/=(1-getreset);
    cout << fixed << setprecision(12);
    cout << ans << endl;
}
