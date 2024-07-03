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

struct Edge {
    long long from;
    long long to;
    long long cost;
};
using Edges = vector<Edge>;
const long long INF = 1LL << 60;
/* bellman_ford(Es,s,t,dis)
    入力: 全ての辺Es, 頂点数V, 開始点 s, 最短経路を記録するdis
    出力: 負の閉路が存在するなら ture
    計算量：O(|E||V|)
    副作用：dis が書き換えられる
*/
bool bellman_ford(const Edges &Es, int V, int s, vector<long long> &dis,Vl &oks) {
    dis.resize(V, INF);
    dis[s] = 0;
    int cnt = 0;
    while (cnt < accumulate(all(oks),0LL)) {
        bool end = true;
        for (auto e : Es) {
            if(oks[e.to]!=1) continue;
            if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if (end) break;
        cnt++;
    }
    return (cnt == accumulate(all(oks),0LL));
}

int main(){
    ll n,m,p;
    cin >> n >> m >> p;
    Edges ed;
    VVl graph(n);
    VVl revgraph(n);
    Vl dist(n,inf);
    Vl oks(n,0);
    Vl oks2(n,0);
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        ed.push_back({a,b,p-c});
        revgraph[b].push_back(a);
        graph[a].push_back(b);
    }
    auto dfs=[&](auto dfs,ll v,ll p2=-1)->void {
        if(oks[v]==1) return;
        oks[v]++;
        for(auto u:revgraph[v]){
            if(u==p2) continue;
            if(oks[u]==1) continue;
            dfs(dfs,u,v);
        }
        return;
    };
    auto dfs2=[&](auto dfs2,ll v,ll p2=-1)->void {
        if(oks2[v]==1) return;
        oks2[v]++;
        for(auto u:graph[v]){
            if(u==p2) continue;
            if(oks2[u]==1) continue;
            dfs2(dfs2,u,v);
        }
        return;
    };
    dfs(dfs,n-1);
    dfs2(dfs2,0);
    rep(i,n) oks[i]=oks[i]*oks2[i];
    //cout << accumulate(all(oks),0LL) << endl;
    if(bellman_ford(ed,n,0,dist,oks)){
        cout << -1 << endl;
        return 0;
    }
    ll ans=max(-dist[n-1],0LL);
    cout << ans << endl;

}