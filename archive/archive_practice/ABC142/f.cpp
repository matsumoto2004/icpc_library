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

VVl graph;
Vl seen;

ll start=-1;
Vl iscycle(n,0);
bool comeback=false;

bool dfs(ll v){
    seen[v]++;
    for(auto u:graph[v]){
        if(u==p) continue;
        if(seen[u]){
            start=u;
            iscycle[v]=1;
            return true;
        }
        if(dfs(u)){
            if(comeback==false) iscycle[v]=1;
            if(v==start) comeback=true;
            return true;
        }
    }
    return false;
}

void dfs2(){
    
}

int main(){
    ll n,m;
    cin >> n >> m;
    graph.resize(n);
    seen.resize(n,0);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(dfs(0)==false){
        cout << -1 << endl;
        return 0;
    }


}