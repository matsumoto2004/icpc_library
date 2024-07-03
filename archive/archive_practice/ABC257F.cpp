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
    VVl graph(n+1);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        graph[x].PB(y);
        graph[y].PB(x);
    }
    Vl dist1(n+1,inf),distn(n+1,inf);
    dist1[1]=0;
    distn[n]=0;
    //dist1の更新
    queue<ll> que;
    que.push(1);
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(auto u:graph[v]){
            if(dist1[u]!=inf) continue;
            dist1[u]=dist1[v]+1;
            que.push(u);
        }
    }
    que.push(n);
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(auto u:graph[v]){
            if(distn[u]!=inf) continue;
            distn[u]=distn[v]+1;
            que.push(u);
        }
    }
    rrep(i,1,n+1){
        ll ans=dist1[n];
        chmin(ans,dist1[0]+distn[i]);
        chmin(ans,dist1[i]+distn[0]);
        if(ans>=inf) cout << -1 << endl;
        else cout << ans << endl;
    }
}