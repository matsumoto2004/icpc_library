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
const ll mod = 1000000007;
const ll inf = 1000000000000000000;//10の18乗
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}
#define int long long
vector<vector<int>> G(200005);
vector<int> dp(200005);
function<int(int, int)> mergen = [](int dp_cum, int d) -> int {  // 1.の二項演算を表す
    return max(dp_cum, d);
};
function<int(int)> add_root = [](int d) -> int {  // 2.を表す。まとめたDPを用いて、新たな部分木のDPを計算する
    return d + 1;
};

void dfs(int v, int p = -1) {  // 頂点v, 親p
    int deg = G[v].size();     // 頂点vの次数
    if (deg == 1&&p!=-1) {            // 末端にいる時
        dp[v] = 0;
        return;
    }
    int dp_cum = 0;
    for (int i = 0; i < deg; i++) {
        int u = G[v][i];          // u: vの子
        if (u == p) continue;        // 親なら探索しない
        dfs(u, v);                   // dp[u] の計算
        dp_cum = mergen (dp_cum, dp[u]);  // 1.の二項演算
    }
    dp[v] = add_root(dp_cum);  // 2.の計算
    //cout << dp_cum << endl;
}

signed main() {
    int n;
    cin >> n;
    int m=n-1;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        G[x].PB(y);
        G[y].PB(x);
    }
    dfs(0);
    ll ans=-1;
    rep(i,n) chmax(ans,dp[i]);
    cout << ans << endl;
}