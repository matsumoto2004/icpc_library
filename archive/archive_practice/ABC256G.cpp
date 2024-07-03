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
//行列の乗算
VVl matrix_multiply(VVl X, VVl Y) {
	VVl Z(X.size(), Vl(Y[0].size()));
	rep(i, X.size()) {
		rep(k, Y.size()) {
			rep(j, Y[0].size()) {
				Z[i][j] = (Z[i][j] + X[i][k] * Y[k][j]) % mod;
			}
		}
	}
	return Z;
}

//A^nの計算
VVl matrix_pow(VVl A, ll n) {
	VVl B(A.size(), Vl(A[0].size()));
	//単位行列でBを初期化
	rep(i, B.size()) {
		B[i][i] = 1;
	}

	while (n>0) {
		if (n & 1) { B = matrix_multiply(B, A); }
		A = matrix_multiply(A, A);
		n = n >> 1;
	}
	return B;
}

//modint構造体

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

vector<ll> fac(3000001); //n!(mod M)
vector<ll> ifac(3000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

VVl init(VVl vv){
    rep(i,vv.size()){
        rep(j,vv[i].size()){
            vv[i][j]=vv[i][j]%mod;
        }
    }
    return vv;
}

int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<3000000; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    ll n,d;
    cin >> n >> d;
    mint ans=1;
    rep(i,d+1){
        VVl v00={{comb(d-1,i-2),comb(d-1,i-1)}};
        VVl v01={{comb(d-1,i-2),comb(d-1,i-1)},{comb(d-1,i-1),comb(d-1,i)}};
        VVl v10={{comb(d-1,i-1),comb(d-1,i)}};
        VVl v11={{comb(d-1,i-2),comb(d-1,i-1)},{comb(d-1,i-1),comb(d-1,i)}};
        v00=init(v00);
        v01=init(v01);
        v10=init(v10);
        v11=init(v11);
        ans+=matrix_multiply(v00,matrix_pow(v01,n-1))[0][0];
        ans+=matrix_multiply(v10,matrix_pow(v11,n-1))[0][1];
    }
    cout << ans.x << endl;

}