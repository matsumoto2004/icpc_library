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
ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

const ll D=32000;

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

ll solve(){
    ll p;
    cin >> p;
    mod=p;
    ll aa,bb,ss,gg;
    cin >> aa >> bb >> ss >> gg;
    mint a=aa,b=bb,s=ss,g=gg;

    
    if(aa==0){
        if(ss==gg) return 0;
        else if(gg==bb) return 1;
        else return -1;
    }
    map<ll,ll> ma;

    vector<mint> as(D+2),bs(D+2);
    as[0]=1;bs[0]=0;
    rep(i,D+1){
        as[i+1]=as[i]*a;
        bs[i+1]=bs[i]*a+b;
        mint h=(g-bs[i])/as[i];
        if(h.x==s.x) return i;
        if(!ma.count(h.x)) ma[h.x]=i;
    }
    mint c=as[D],d=bs[D];
    rep(i,D){
        if(ma.count(s.x)) return i*D+ma[s.x];
        s=c*s+d;
    }
    return -1;
}

int main(){
    ll t;
    cin >> t;
    rep(i,t) cout << solve() << endl;
}