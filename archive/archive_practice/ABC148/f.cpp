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

VVl graph(100005);
Vl dist(100005,0),dist2(100005,0);

void dfs(ll v,ll p=-1){
    for(auto u:graph[v]){
        if(u==p) continue;
        dist[u]=dist[v]+1;
        dfs(u,v);
    }
}

void dfs2(ll v,ll p=-1){
    for(auto u:graph[v]){
        if(u==p) continue;
        dist2[u]=dist2[v]+1;
        dfs2(u,v);
    }
}

ll ans=0;

void dfs3(ll v,ll p=-1){
    if(dist[v]>=dist2[v]) return;

    chmax(ans,dist2[v]);
    for(auto u:graph[v]){
        if(u==p) continue;
        dfs3(u,v);
    }
}

int main(){
    ll n,u,v;
    cin >> n >> u >> v;
    u--;v--;
    rep(i,n-1){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(u);
    dfs2(v);
    dfs3(u);
    cout << ans-1 << endl;


}