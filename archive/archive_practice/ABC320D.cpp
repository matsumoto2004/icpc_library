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

struct Edge{
    ll to;
    ll x;
    ll y;
};

Vl vx,vy;
Vl seen;
vector<vector<Edge>> graph;

void dfs(ll v,ll p=-1){
    seen[v]=1;
    for(auto [u,x,y]:graph[v]){
        if(u==p) continue;
        if(seen[u]) continue;
        vx[u]=vx[v]+x;
        vy[u]=vy[v]+y;
        dfs(u,v);
    }
}

int main(){
    ll n,m;
    cin >> n >> m;
    vx.resize(n);
    vy.resize(n);
    graph.resize(n);
    seen.resize(n);
    rep(i,m){
        ll a,b,x,y;
        cin >> a >> b >> x >> y;
        a--;b--;
        graph[a].push_back({b,x,y});
        graph[b].push_back({a,-x,-y});
    }
    //cout << "ok" << endl;
    dfs(0);

    rep(i,n){
        if(seen[i]) cout << vx[i] << " " << vy[i] << endl;
        else cout << "undecidable" << endl;
    }
}
