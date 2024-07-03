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
    ll id;
};

vector<vector<Edge>> graph(100005);
Vl ans(100005);

void dfs(ll v,ll banned=-1,ll p=-1){
    ll now=0;
    if(now==banned) now++;
    for(auto [u,id]:graph[v]){
        if(u==p) continue;
        ans[id]=now;
        dfs(u,now,v);
        now++;
        if(now==banned) now++;
    }
}

int main(){
    ll n;
    cin >> n;
    rep(i,n-1){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back({y,i});
        graph[y].push_back({x,i});
    }
    dfs(0);
    ll mxcolor=*max_element(all(ans));
    cout << mxcolor+1 << endl;
    rep(i,n-1) cout << ans[i]+1 << endl;
}