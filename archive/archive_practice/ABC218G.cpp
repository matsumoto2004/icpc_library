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
    ll n;
    cin >> n;
    Vl vec(n);
    rep(i,n) cin >> vec[i];
    
    VVl graph(n);
    Vl dist(n,0);
    //Vl size(n,0);
    Vl dp(n,0);
    Vl memo1(n,-1),memo2(n,-1);

    rep(i,n-1){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].PB(y);
        graph[y].PB(x);
    }

    auto dfs=[&](auto dfs,ll v,ll p=-1)->void{
        if(p!=-1) dist[v]=dist[p]+1;
        for(auto u:graph[v]){
            if(u==p) continue;
            dfs(dfs,u,v);
        }
    };
    dfs(dfs,0);

    ll mid=-1;
    auto dfs2=[&](auto dfs2,ll v,ll p=-1)->void{
        //先攻
        ll now=0;
        if(dist[v]%2==0){
            now=-inf;
            for(auto u:graph[v]){
                if(u==p) continue;
                dfs2(dfs2,u,v);
                chmax(now,dp[u]);
            }
            if(now==-inf) now=0;
        }
        //後攻
        if(dist[v]%2==1){
            now=inf;
            for(auto u:graph[v]){
                if(u==p) continue;
                dfs2(dfs2,u,v);
                chmin(now,dp[u]);
            }
            if(now==inf) now=0;
        };

        if(vec[v]>=mid) now+=1;
        else now-=1;
        dp[v]=now;
    };

    ll ok=0,ng=inf;
    while(ng-ok>1){
        mid=(ok+ng)/2;
        dp.resize(n,0);
        dfs2(dfs2,0);
        if(dp[0]>=0) ok=mid;
        else ng=mid;
    }
    cout << ok << endl;
}