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

vector<ll> Z_algorithm(string S) {
	ll c = 0, n = S.size();
	//接頭辞の長さを保存する配列を返す。
	//i = 1からやるとする。
	//Z[1]には赤下線が存在しないので、「溢れるor共通部分がない」のところにまずいく。
	//実装上、上のような挙動をしてもらうため、Z[0]=n;は[1, n - 1]まで計算が終わった後に入れる。
	//cは、赤下線の左端の位置。
	vector<ll> Z(n, 0);
	for (ll i = 1; i < n; i++) {
		ll l = i - c;
		//今着目してる部分が赤下線の左端から何個分離れているかをlに入れる。
		if (i + Z[l] < c + Z[c]) {
			//この条件を満たすのは、「青下線が赤下線に収まる」。
			//この時、すでに計算されてるなのでそれを流用する。
			Z[i] = Z[l];
		}
		else {
			//この条件を満たすのは、「赤下線から青下線が溢れる」or「赤下線と青下線の共通部分がない」。
			ll j = max((ll)0, c + Z[c] - i);
			//c + Z[c] - i > 0の時、これは「溢れる」が該当する。
			//溢れてるのなら、収まる分は計算せずに、溢れた分(j番目から)だけ愚直に突き合わせればよい。
			//そもそも共通部分がないならば、全部突き合わせる。この時、式からj = 0;となるとわかる。

			//愚直に突き合せてる部分
			while (i + j < n && S[j] == S[i + j])j++;
			
			Z[i] = j;
			//今の見てるiで、赤下線に完全に含まれなくなったので、今のiを赤下線の左端として、次のiをまた計算する。
			c = i;
		}
	}

	//最後にこれを忘れずに
	Z[0] = n;
	return Z;
}

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

using X = ll;
using M = ll;
auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
auto fa = [](X x, M m) -> X { return min(x,m); };
auto fm = [](M m1, M m2) -> M { return min(m1,m2); };
ll ex = inf;
ll em = inf;

int main(){
    string s,t;
    cin >> s >> t;
    ll ns=s.size(),nt=t.size();
    Vl vv=Z_algorithm(s+t);
    Vl v;
    rep(i,nt) v.PB(vv[ns+i]);
    rep(i,nt) chmin(v[i],ns);
    SegTreeLazy<X,M> seg(nt+6e5,fx,fa,fm,ex,em);
    rep(i,nt+5) seg.set(i,inf);
    seg.set(0,0);
    seg.build();
    rep(i,nt){
        ll x=seg.query(i,i+1);
        seg.update(i+1,i+v[i]+1,x+1);

    }
    ll ans=seg.query(nt,nt+1);
    if(ans>=inf/2) ans=-1;
    cout << ans << endl;

}