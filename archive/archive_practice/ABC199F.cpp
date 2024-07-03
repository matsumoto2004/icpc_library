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
const ll mod = 1e9+7;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

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

//行列の乗算
vector<vector<mint>> matrix_multiply(vector<vector<mint>> X, vector<vector<mint>> Y) {
	vector<vector<mint>> Z(X.size(), vector<mint>(Y[0].size()));
	rep(i, X.size()) {
		rep(k, Y.size()) {
			rep(j, Y[0].size()) {
				Z[i][j] = Z[i][j] + X[i][k] * Y[k][j];
			}
		}
	}
	return Z;
}

//A^nの計算
vector<vector<mint>> matrix_pow(vector<vector<mint>> A, ll n) {
	vector<vector<mint>> B(A.size(), vector<mint>(A[0].size()));
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


int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    Vl notchangeprob(n,m);

    vector<vector<mint>> v(n,vector<mint>(1));
    rep(i,n){
      ll x;
      cin >> x;
      v[i][0]=x;
    }

    vector<vector<mint>> mat(n,vector<mint>(n,0));
    mint kake=1;
    kake/=m;

    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        notchangeprob[x]--;
        notchangeprob[y]--;
        mat[x][x]+=kake/2;
        mat[x][y]+=kake/2;
        mat[y][x]+=kake/2;
        mat[y][y]+=kake/2;
    }
    rep(i,n){
      mat[i][i]+=kake*notchangeprob[i];
    }

    vector<vector<mint>> ans=matrix_multiply(matrix_pow(mat,k),v);
    rep(i,n){
      cout << ans[i][0].x << endl;
    }
}
