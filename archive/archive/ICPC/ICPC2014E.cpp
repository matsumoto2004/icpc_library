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
    ll cost;
};

vector<vector<Edge> > graph(805);
ll dist[805][805];
ll dim[805];
ll hasi[805];

void dfs(ll now,ll st){
    for(auto next:graph[now]){
        if(dist[st][next.to]!=-1) continue;
        dist[st][next.to]=dist[st][now]+next.cost;
        dfs(next.to,st);
    }
}


int main(){
    while(1){
        ll n;
        cin >> n;
        rep(i,n)rep(j,n){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=-1;
        }
        rep(i,n) dim[i]=0;
        rep(i,n) hasi[i]=0;
        rep(i,n) graph[i]={};

        
        Vl vp(n),vd(n);
        rrep(i,1,n) cin >> vp[i];
        rep(i,n) vp[i]--;
        rrep(i,1,n) cin >> vd[i];
        rrep(i,1,n){
           Edge ed;
           ed.to=vp[i];ed.cost=vd[i];
           graph[i].PB(ed);
           ed.to=i;
           graph[vp[i]].PB(ed);
           dim[i]++;
           dim[vp[i]]++; 
        }
        
        rep(i,n) dfs(i,i);
        ll ans=0;
        rrep(i,1,n) ans+=vd[i]*3;
        rep(i,n){
            if(dim[i]==1){
                for(Edge next:graph[i]){
                    ans-=next.cost*2;
                    hasi[next.to]=1;
                }
            }
        }
        //cout << ans << endl;
        ll minus=0;
        rep(i,n)rep(j,n){
            if(hasi[i]==1&&hasi[j]==1){
                chmax(minus,dist[i][j]);
                //cout << i << j << minus;
            }
        }
        cout << ans-minus << endl;
        

    }
}