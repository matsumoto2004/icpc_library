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
Vl dist;

void dfs(ll v,ll p=-1){
    for(auto [u,cost]:graph[v]){
        if(u==p) continue;
        dist[u]=dist[v]+cost;
        dfs(u,v);
    }
}

int main(){
    ll n;
    cin >> n;
    graph.resize(2*n);
    dist.resize(2*n,0);
    Vl vd(n);
    rep(i,n-1){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].PB({b,c});
        graph[b].PB({a,c});
    }
    rep(i,n){
        ll d;
        cin >> d;
        vd[i]=d;
        graph[i].PB({n+i,d});
        graph[i+n].PB({i,d});
    }
    dfs(0);
    ll v1=-1;
    ll mx=-1;
    rep(i,2*n){
        if(dist[i]>mx){
            v1=i;
            mx=dist[i];
        }
    }
    dist.assign(2*n,0);
    dfs(v1);
    ll v2=-1;
    mx=-1;
    rep(i,2*n){
        if(dist[i]>mx){
            v2=i;
            mx=dist[i];
        }
    }
    Vl dist1=dist;
    dist.assign(2*n,0);
    dfs(v2);
    Vl dist2=dist;
    rep(i,n){
        ll ans=max(dist1[i],dist2[i]);
        if(v1==i+n) ans=dist2[i];
        if(v2==i+n) ans=dist1[i];
        cout << ans << endl;
    }


}