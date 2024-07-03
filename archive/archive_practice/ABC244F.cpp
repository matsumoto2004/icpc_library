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



int main(){
    ll n,m;
    cin >> n >> m;
    VVl to(n);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        to[x].PB(y);
        to[y].PB(x);
    }
    VVl dist(n,Vl(1<<n,inf));
    rep(i,n) dist[i][0]=0;
    queue<pair<ll,ll>> que;
    rep(i,n) que.push({i,0});
    while(!que.empty()){
        auto [v,vbit]=que.front();
        que.pop();
        for(ll u:to[v]){
            ll ubit=vbit^(1<<u);
            if(dist[u][ubit]!=inf) continue;
            dist[u][ubit]=dist[v][vbit]+1;
            que.push({u,ubit});
        }
    }
    ll ans=0;
    rep(bit,1<<n){
        ll mn=inf;
        rep(i,n) chmin(mn,dist[i][bit]);
        ans+=mn;
    }
    cout << ans << endl;

}