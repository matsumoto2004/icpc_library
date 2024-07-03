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
ll n,q;
Vl vx;
VVl graph;
VVl vint;

void dfs(ll v,ll p=-1){
    for(auto u:graph[v]){
        if(u==p) continue;
        dfs(u,v);
        for(auto x:vint[u]){
            vint[v].PB(x);
        }
    }
    vint[v].PB(vx[v]);
    sort(all(vint[v]));
    reverse(all(vint[v]));
    while(vint[v].size()>20) vint[v].pop_back();

}

int main(){
    cin >> n >> q;
    vx.resize(n);
    rep(i,n) cin >> vx[i];
    graph.resize(n);
    vint.resize(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    dfs(0);
    rep(query,q){
        ll v,k;
        cin >> v >> k;
        v--;
        cout << vint[v][k-1] << endl;
    }
}