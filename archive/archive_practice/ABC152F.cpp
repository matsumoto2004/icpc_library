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

vector<vector<Edge>> graph(55);
VVl edges(25);

Vl es;

void dfs(ll v,ll p,ll edgeid,ll &to,int &id){
    //cout << v << endl;
    if(edgeid!=-1) es.push_back(edgeid);
    if(v==to) edges[id]=es;
    for(auto [u,uedgeid]:graph[v]){
        if(u==p) continue;
        dfs(u,v,uedgeid,to,id);
    }
    if(edgeid!=-1) es.pop_back();
}

ll mypow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x;
        x = x*x;
        n = n >> 1;
    }
    return ans;
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
    ll m;
    cin >> m;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        dfs(x,-1,-1,y,i);
    }
    ll ans=mypow(2,n-1);
    rrep(bit,1,1<<m){
        Vl white(n-1,0);
        rep(i,m){
            if((bit>>i)&1){
                for(auto x:edges[i]) white[x]=1;
            }
        }
        ll cnt=accumulate(all(white),0LL);

        //cout << cnt << endl;
        if(__builtin_popcount(bit)%2==0){
            ans+=mypow(2,n-1-cnt);
        }
        else{
            ans-=mypow(2,n-1-cnt);
        }
    }
    cout << ans << endl;

}