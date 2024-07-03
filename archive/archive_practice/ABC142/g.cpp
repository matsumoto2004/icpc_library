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

VVl graph(1005);
ll n,m;

Vl bfs(ll s){
    Vl dist(n,inf);
    Vl from(n,-1);
    queue<ll> que;
    que.push(s);
    dist[s]=0;

    ll mn=inf;
    ll end=-1;
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(auto u:graph[v]){
            if(u==s&&dist[v]<mn){
                mn=dist[v];
                end=v;
                continue;
            }

            if(dist[u]!=inf) continue;
            dist[u]=dist[v]+1;
            from[u]=v;
            que.push(u);
        }
    }
    if(end==-1) return Vl(n+1,-1);


    Vl ret;
    while(end!=-1){
        ret.push_back(end);
        end=from[end];
    }
    return ret;
}

int main(){
    cin >> n >> m;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
    }


    Vl ans(n+1,-1);
    rep(i,n){
        Vl now=bfs(i);
        if(now.size()<ans.size()) ans=now;
    }
    if(ans.size()==n+1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(ll v:ans) cout << v+1 << endl;
}