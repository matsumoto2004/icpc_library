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
struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);//xのサイズのほうが大きくなるように(if文は逆ではない)
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};
 


int main(){
    ll n,m;
    cin >> n >> m;
    Vl vd(n);
    rep(i,n) cin >> vd[i];
    if(accumulate(all(vd),0)!=2*n-2) dame;
    VVl v(n);
    UnionFind uf(n);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        vd[a]--;vd[b]--;
        if(uf.root(a)==uf.root(b)) dame;
        uf.unite(a,b);
    }
    rep(i,n){
        if(vd[i]<0) dame;
        rep(j,vd[i]) v[uf.root(i)].PB(i);
    }

    priority_queue<pair<ll,ll>> pq;//(size,id)
    rep(i,n){
        if(v[i].size()!=0) pq.push({v[i].size(),i}); 
    }
    vector<pair<ll,ll>> ans;
    while(pq.size()>=2){
        auto [si,i]=pq.top();
        pq.pop();
        auto [sj,j]=pq.top();
        pq.pop();
        ans.emplace_back(v[i].back(),v[j].back());
        v[i].pop_back();
        v[j].pop_back();
        copy(all(v[j]),back_inserter(v[i]));
        if(si+sj>2) pq.push({si+sj-2,i});
    }
    if(ans.size()!=n-m-1) dame;
    for(auto [x,y]:ans) cout << x+1 << " " << y+1 << endl;
}

