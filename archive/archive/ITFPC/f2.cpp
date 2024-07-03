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

template<class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
struct RerootingDP {
    struct edge{
        int from, to, idx, rev_idx;
    };
    RerootingDP (int _n = 0) : n(_n) { es.resize(n);}
    void add_edge(int u, int v, int idx1, int idx2){
        es[u].push_back({u,v,idx1,idx2});
        es[v].push_back({v,u,idx2,idx1});
    }
    V build(int v = 0){
        root = v;
        vis.resize(n,0);
        outs.resize(n);
        return dfs(root);
    }
    vector<V> reroot(){
        reverse_edge.resize(n);
        reverse_edge[root] = e();
        answers.resize(n);
        bfs(root);
        return answers;
    }
  private:
    int n, root;
    vector<vector<edge>> es;
    vector<int> vis;
    vector<vector<E>> outs;
    vector<E> reverse_edge;
    vector<V> answers;
    V dfs(int v){
        vis[v]++;
        E val = e();
        for (auto &p : es[v]){
            if (vis[p.to] > 0 && p.to != es[v].back().to) swap(p,es[v].back());
            if (vis[p.to] > 0) continue;
            E nval = put_edge(dfs(p.to),p.idx);
            outs[v].emplace_back(nval);
            val = merge(val,nval);
        }
        return put_vertex(val,v);
    }
    void bfs(int v){
        int siz = outs[v].size();
        vector<E> lui(siz+1), rui(siz+1);
        lui[0] = e(), rui[siz] = e();
        for (int i = 0; i < siz; i++) lui[i+1] = merge(lui[i],outs[v][i]);
        for (int i = siz-1; i >= 0; i--) rui[i] = merge(outs[v][i],rui[i+1]);
        for (int i = 0; i < siz; i++){
            reverse_edge[es[v][i].to] = put_edge(put_vertex(merge(merge(lui[i],rui[i+1]),reverse_edge[v]),v),es[v][i].rev_idx);
            bfs(es[v][i].to);
        }
        answers[v] = put_vertex(merge(lui[siz],reverse_edge[v]), v);
    }
};

struct DP{
    ll dp;
    ll id;
    DP(ll dp=-1,ll id=-1):dp(dp),id(id) {};
};

DP merge(DP a, DP b){
    if(a.id>b.id) return a;
    else return b;
}
DP e(){
    return DP(-1,-1);
}
DP put_edge(DP v, int i){
    return  v;
}
DP put_vertex(DP e, int v){
    if(e.dp!=-1) return DP(e.dp,v);
    else return DP(v,v);
}

int main(){
    ll n;
    cin >> n;
    RerootingDP<DP,DP,merge,e,put_edge,put_vertex> g(n);
    rep(i,n-1){
        ll x;
        cin >> x;
        x--;
        g.add_edge(i+1,x,i,i);

    }
    g.build();
    vector<DP> ans=g.reroot();
    for(auto x:ans) cout << x.dp+1 << endl;

}