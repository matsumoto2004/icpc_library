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
Vl rest;
Vl ans;
void dfs(ll v,ll p=-1){
    seen[v]++;
    ans.PB(v);
    rest[v]++;
    for(auto u:graph[v]){
        if(seen[u]) continue;
        dfs(u,v);
        ans.PB(v);
        rest[v]++;
    }
    if(rest[v]%2==1&&p!=-1){
        ans.PB(p);
        ans.PB(v);
        rest[p]++;
        rest[v]++;
    }

}

int main(){
    ll n,m;
    cin >> n >> m;
    graph.resize(n);
    seen.resize(n);
    rest.resize(n);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].PB(y);
        graph[y].PB(x);
    }
    string s;
    cin >> s;
    rep(i,n) rest[i]+=s[i]-'0';
    dfs(0);
    if(rest[0]%2==1){
        ll to=graph[0][0];
        ans.PB(to);
        ans.PB(0);
        if(rest[to]%2==0) ans.PB(to);
    }
    cout << ans.size() << endl;
    for(auto x:ans) cout << x+1 << " ";
    cout << endl;
}