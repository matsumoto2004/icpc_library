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
 


vector<Pl> ans;

void myswap(ll x,ll y,Vl &v,map<ll,ll> &rev){
    if(x>y) swap(x,y);
    rev[v[x]]=y;
    rev[v[y]]=x;
    swap(v[x],v[y]);
    ans.emplace_back(x,y);
}

void solve(){
    ans={};
    ll n;
    cin >> n;
    Vl v(n);
    rep(i,n) cin >> v[i];
    rep(i,n) v[i]--;
    map<ll,ll> rev;
    rep(i,n) rev[v[i]]=i;

    UnionFind uf(n);
    rep(i,n) uf.unite(i,v[i]);
    Vl strangesort;
    for(int i=0;i<=n-i-1;i++){
        strangesort.PB(i);
        strangesort.PB(n-i-1);
    }
    for(auto i:strangesort){
        if(rev[i]==i) continue;
        ll whe=rev[i];
        //cout << i << whe << endl;
        ll to=v[i];
        if(i<whe){
            if(to>=whe){
                myswap(i,whe,v,rev);
            }
            else{
                myswap(whe,to,v,rev);
                myswap(to,i,v,rev);
            }
        }
        if(i>whe){
            if(to<=whe){
                myswap(i,whe,v,rev);
            }
            else{
                myswap(whe,to,v,rev);
                myswap(to,i,v,rev);
            }
        }
    }
    vector<vector<Pl>> newans(n);
    for(auto p:ans){
        newans[uf.root(p.F)].emplace_back(p.F,p.S);
    }

    ll pastx=-1,pasty=-1;
    vector<Pl> finalans;
    for(auto hoge:newans)for(auto[x,y]:hoge){
        if(y>pastx&&pasty>x) finalans.emplace_back(0,0);
        finalans.emplace_back(x,y);
        pastx=x;
        pasty=y;
    }

    cout << finalans.size() << endl;
    for(auto p:finalans){
        cout << p.F+1 << " " << p.S+1 << endl;
    }


}


int main(){
    ll t;
    cin >> t;
    rep(i,t) solve();
}