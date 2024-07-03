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

struct Compress{
    Vl v;
    
    void insert(ll x){
        v.push_back(x);
    }
    void init(){
        sort(all(v));
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }
    ll get(ll x){
        return lower_bound(all(v),x)-v.begin();
    }
    ll rev(ll x){
        return v[x];
    }
    ll getmax(){
        return v.size();
    }

};

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

Vl vx,vd;
Vl called;
ll n;
Vl vg;

void dfs(ll i){
    called[i]=1;
    ll now=vx[i]+vd[i];
}

int main(){
    cin >> n;
    vector<pair<ll,ll>> vp(n);
    rep(i,n) cin >> vp[i].first >> vp[i].second;
    sort(all(vp));
    vx.resize(n);
    vd.resize(n);
    vg.resize(n);
    called.resize(n,0);
    rep(i,n){
        vx[i]=vp[i].first;
        vd[i]=vp[i].second;
    }
    

    vector<mint> dp(n+5,0);
    vector<mint> dp2(n+5,0);
    //dp[0]=1;
    dp2[0]=1;

    rep(i,n){
        dp[i]+=dp2[i];
        ll next=lower_bound(all(vx),vg[i])-vx.begin();
        //cout << i << next << endl;
        dp2[next]+=dp2[i];
        dp2[i+1]+=dp[i];
    }
    mint ans=0;
    rep(i,n) ans+=dp[i];
    cout << ans.x+1 << endl;

}
