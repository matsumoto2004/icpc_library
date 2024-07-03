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
vector<vector<Edge>> graph(200005);
Vl dist(200005,-1);
bool isng=true;
void dfs(ll v,ll p,ll &mx){
    for(auto [u,cost]:graph[v]){
        if(u==p) continue;
        if(cost>mx) continue;
        if(dist[u]!=-1){
            if((dist[u]+dist[v])%2==0) isng=false;
        }
        else{
            dist[u]=dist[v]+1;
            dfs(u,v,mx);
        }

    }
}

int main(){
    ll n,m;
    cin >> n >> m;
    VVl list(n);
    rep(i,m){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
        list[a].push_back(w);
        list[b].push_back(w);

    }
    ll ans=inf;
    rep(i,n){
        if(list[i].size()>=2){
            sort(all(list[i]));
            chmin(ans,list[i][0]+list[i][1]);
        }
    }
    
    ll ok=0,ng=inf;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        isng=true;
        dist.assign(200005,-1);
        rep(i,n){
            if(dist[i]==-1) dfs(i,-1,mid);
        }
        if(isng==false) ng=mid;
        else ok=mid;
    }
    cout << min(ok+1,ans) << endl;
    

}