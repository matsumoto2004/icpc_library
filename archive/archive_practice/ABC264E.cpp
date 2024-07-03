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
    ll n,m,e;
    cin >> n >> m >> e;
    Vl vu(e),vv(e);
    Vl broken(e,0);
    rep(i,e){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        vu[i]=u;vv[i]=v;
    }
    ll q;
    cin >> q;
    Vl vq(q);
    rep(i,q){
        cin >> vq[i];
        vq[i]--;
        broken[vq[i]]=1;
    }
    Vl ans(q);
    VVl graph(n+m);
    rep(i,e){
        if(!broken[i]){
            graph[vu[i]].PB(vv[i]);
            graph[vv[i]].PB(vu[i]);
        }
    }
    ll cnt=0;
    Vl on(n+m,0);
    queue<ll> que;
    rep(i,m) que.push(n+i);
    repd(i,q){
        while(!que.empty()){
        
        ll v=que.front();
        que.pop();
        if(on[v]) continue;
       
        on[v]=1;
        cnt++;
        for(auto u:graph[v]){
            if(on[u]) continue;
            que.push(u);
        }
        }
        ans[i]=cnt;
        ll x=vu[vq[i]],y=vv[vq[i]];
        graph[x].PB(y);
        graph[y].PB(x);
        if(on[x]==0&&on[y]==1){
            que.push(x);
        }
        if(on[x]==1&&on[y]==0){
            que.push(y);
        }
    }
    rep(i,q) cout << ans[i]-m << endl;
}