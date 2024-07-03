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

VVl g;
Vl dep;
Vl in;
Vl out;
ll now=-1;
VVl vdep;

void dfs(ll v,ll d){
    now++;
    in[v]=now;
    dep[v]=d;
    vdep[d].PB(now);
    for(auto to:g[v]){
        dfs(to,d+1);
    }
    out[v]=now;
}

int main(){
    ll n;
    cin >> n;
    g.assign(n,Vl(0));
    dep.assign(n,0);
    in.assign(n,0);
    out.assign(n,0);
    vdep.assign(n,Vl(0));
    rep(i,n-1){
        ll x;
        cin >> x;
        x--;
        g[x].PB(i+1);
        //g[i+1].PB(x);
    }
    dfs(0,0);
    rep(i,n) vdep[i].PB(inf);

    ll q;
    cin >> q;
    rep(query,q){
        ll x,y;
        cin >> x >> y;
        x--;
        if(y<dep[x]){
            cout << 0 << endl;
        }
        else{
            ll d=y;
            ll ans=lower_bound(all(vdep[d]),out[x]+1)-lower_bound(all(vdep[d]),in[x]);
            cout << ans << endl;
        }

    }

}