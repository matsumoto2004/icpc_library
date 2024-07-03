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

int main(){
    ll n,m;
    cin >> n >> m;
    Vl va(n),vb(m);
    rep(i,n) cin >> va[i];
    rep(i,m) cin >> vb[i];
    vector<vector<mint>> dp(n+5,vector<mint>(m+5,0));
    vector<vector<mint>> sum1(n+5,vector<mint>(m+5,0));//横に
    vector<vector<mint>> sum2(n+5,vector<mint>(m+5,0));//縦に
    dp[0][0]=1;
    sum1[0][0]=1;
    sum2[0][0]=1;
    rep(i,n+2) sum2[i][0]=1;
    rep(i,m+2){
        sum1[0][i]=1;
        sum2[0][i]=1;
    }
    rep(i,n)rep(j,m){
        if(va[i]==vb[j]) dp[i+1][j+1]+=sum2[i][j];
        sum1[i+1][j+1]=sum1[i+1][j]+dp[i+1][j+1];
        sum2[i+1][j+1]=sum2[i][j+1]+sum1[i+1][j+1];
    }
    cout << sum2[n][m].x << endl;
}