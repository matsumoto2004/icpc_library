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
Vl seen,finished;
ll ans=1;
void dfs(ll x){
    if(seen[x]&&(!finished[x])){
        ans=0;
        return;
    }
    if(seen[x]&&finished[x]) return;
    seen[x]=1;
    for(auto to:graph[x]){
        dfs(to);
    }
    finished[x]=1;
}

int main(){
    ll n,m;
    cin >> n >> m;
    graph.assign(n,Vl(0,0));
    seen.assign(n,0);
    finished.assign(n,0);
    rep(i,m){
        ll k;
        cin >> k;
        Vl v(k);
        rep(j,k) cin >> v[j];
        rep(j,k) v[j]--;
        rep(j,k-1) graph[v[j]].PB(v[j+1]);
    }
    rep(i,n){
        if(!seen[i]) dfs(i);
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}