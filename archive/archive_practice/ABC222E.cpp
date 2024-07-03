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

struct Edge{
    ll to;
    ll id;
};

vector<vector<Edge>> graph;
Vl edcnt;
ll n,m,k;

bool dfs(ll goal,ll v,ll p=-1){
    if(v==goal) return true;
    for(auto [u,id]:graph[v]){
        if(u==p) continue;
        if(dfs(goal,u,v)){
            edcnt[id]++;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    graph.resize(n);
    edcnt.resize(n-1);
    Vl va(m);
    rep(i,m) cin >> va[i];
    rep(i,m) va[i]--;
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].PB({b,i});
        graph[b].PB({a,i});
    }
    rep(i,m-1){
        dfs(va[i+1],va[i]);
    }
    ll s=0;
    rep(i,n-1) s+=edcnt[i];
    if((k+s)%2!=0){
        cout << 0 << endl;
        return 0;
    }
    ll r=(k+s)/2;
    //cout << r << endl;
    if(r<0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<mint>> dp(n+5,vector<mint>(r+5));
    dp[0][0]=1;
    rep(i,n-1)rep(j,r+1){
        dp[i+1][j]+=dp[i][j];
        if(j-edcnt[i]>=0) dp[i+1][j]+=dp[i][j-edcnt[i]];
    }
    //cout << r << endl;
    cout << dp[n-1][r].x << endl;
}