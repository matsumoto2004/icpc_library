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

VVl graph;

pair<ll,ll> dfs(ll v,ll d=0,ll p=-1){
    pair<ll,ll> res(d,v);
    for(auto u:graph[v]){
        if(u==p) continue;
        chmax(res,dfs(u,d+1,v));
    }
    return res;
}
Vl path;

bool dfs2(ll v,ll g,ll p=-1){
    if(v==g){
        path.PB(v);
        return true;
    }
    for(auto u:graph[v]){
        if(u==p) continue;
        if(dfs2(u,g,v)){
            path.PB(v);
            return true;
        }
    }
    return false;
}

ll dfs3(ll v,ll d,ll dmax,ll p=-1){
    ll ret=0;
    if(d==dmax) ret++;
    for(auto u:graph[v]){
        if(u==p) continue;
        ret+=dfs3(u,d+1,dmax,v);
    }
    return ret;
}

int main(){
    ll n;
    cin >> n;
    graph.resize(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    ll v1=dfs(0).S;
    ll v2=dfs(v1).S;
    //cout << "ok" << endl;
    dfs2(v1,v2);
    ll d=path.size()-1;
    if(d%2==1){
        ll l=path[d/2],r=path[d/2+1];
        mint ans=dfs3(l,0,d/2,r);
        ans*=dfs3(r,0,d/2,l);
        cout << ans.x << endl;
    }
    else{
        ll cent=path[d/2];
        mint ans=1;
        mint mns=0;
        for(auto x:graph[cent]){
            ans*=(dfs3(x,1,d/2,cent)+1);
            mns+=dfs3(x,1,d/2,cent);
        }
        ans-=mns;
        ans-=1;
        cout << ans.x << endl;

    }
}