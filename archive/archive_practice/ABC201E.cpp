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
const ll mod = 1000000007;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

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


struct edge{
    ll to;
    ll cost;
};

vector<vector<edge>> g;
vector<ll> dist;

void dfs(int x){
    for(auto next:g[x]){
        if(dist[next.to]!=-1) continue;
        dist[next.to]=dist[x]^next.cost;
        dfs(next.to);   
    }
}

int main(){
    ll n;
    cin >> n;
    g.resize(n,vector<edge>(0));
    dist.assign(n,-1);
    rep(i,n-1){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        g[x].PB({y,z});
        g[y].PB({x,z});
    }
    dist[0]=0;
    dfs(0);
    Vl bitcount(65,0);
    Vl bitcount2(65,0);
    rep(i,n)rep(j,62){
        if((dist[i]>>j)&1) bitcount[j]++;
        else bitcount2[j]++;
    }
    mint ans=0;
    rep(i,62){
        mint pls=((ll)1<<i);
        pls*=(bitcount[i]);
        pls*=(bitcount2[i]);
        ans+=pls;
    }
    cout << ans.x << endl;

}