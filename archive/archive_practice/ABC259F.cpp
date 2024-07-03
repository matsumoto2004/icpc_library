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
    ll cost;
};

vector<vector<Edge>> graph;
Vl vd;
Vl dp0,dp1;//余力あり，なし

void dfs(ll v,ll p=-1){
    ll now=0;
    priority_queue<ll> pq;
    for(auto [u,cost]:graph[v]){
        if(u==p) continue;
        dfs(u,v);
        now+=dp1[u];
        if(dp0[u]+cost-dp1[u]>0) pq.push(dp0[u]+cost-dp1[u]);
    }
    if(vd[v]==0){
        dp0[v]=-inf;
        dp1[v]=now;
        return;
    }
    rep(i,vd[v]-1){
        if(!pq.empty()){
            now+=pq.top();
            pq.pop();
        }
    }
    dp0[v]=now;
    if(!pq.empty()){
        now+=pq.top();
        pq.pop();
    }
    dp1[v]=now;
    return;
}

int main(){
    ll n;
    cin >> n;
    graph.resize(n);
    vd.resize(n);
    dp0.resize(n,0);
    dp1.resize(n,0);
    rep(i,n) cin >> vd[i];
    rep(i,n-1){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].PB({v,w});
        graph[v].PB({u,w});
    }
    dfs(0);
    cout << dp1[0] << endl;
}