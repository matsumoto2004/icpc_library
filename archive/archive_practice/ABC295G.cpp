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
    vector<int> vmn;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
        rep(i,N) vmn.PB(i);
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
        vmn[x]=min(vmn[x],vmn[y]);
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }

    int mn(int x){
        return vmn[root(x)];
    }
};
 
 

int main(){
    ll n;
    cin >> n;
    Vl vp(n);
    rep(i,n-1) cin >> vp[i+1];
    rep(i,n-1) vp[i+1]--;

    UnionFind uf(n);

    ll q;
    cin >> q;
    rep(qi,q){
        ll type;
        cin >> type;
        if(type==1){
            ll x,y;
            cin >> x >> y;
            x--;y--;
            ll now=x;
            while(now!=uf.mn(y)){
                ll to=uf.mn(vp[now]);
                uf.unite(now,to);
                now=to;
            }
        }
        else{
            ll x;
            cin >> x;
            x--;
            cout << uf.mn(x)+1 << endl;
        }
    }

}