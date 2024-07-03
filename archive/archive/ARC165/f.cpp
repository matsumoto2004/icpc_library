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

}

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
vector<vector<Edge>> graph(200005);



int main(){
    ll n,m;
    cin >> n >> m;
    rep(i,m){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});

    }
    
    Vl dist0(n,inf);
    dist0[0]=0;
    priority_queue<Pl,vector<Pl>,greater<Pl>> pq0;
    pq0.push({0,0});
    while(!pq0.empty()){
        auto [dis,whe]=pq0.top();
        pq0.pop();
        if(dis<=dist0[whe]) continue;
        dist0[whe]=dis;
        for(auto [u,cost]:graph[whe]){
            if(dist0[u]!=inf) continue;
            pq0.push({dist0[whe]+cost,u});
        }
    }
    ll a=-1;
    ll mx=-1;
    rep(i,n){
        if(dist0[i]>mx){
            a=i;
            mx=dist0[i];
        }
    }
    Vl dista(n,inf);
    dista[a]=0;
    priority_queue<Pl,vector<Pl>,greater<Pl>> pqa;
    pqa.push({a,0});
    while(!pqa.empty()){
        auto [dis,whe]=pqa.top();
        pqa.pop();
        if(dis<=dista[whe]) continue;
        dista[whe]=dis;
        for(auto [u,cost]:graph[whe]){
            if(dista[u]!=inf) continue;
            pq0.push({dista[whe]+cost,u});
        }
    }
    ll b=-1;
    mx=-1;
    rep(i,n){
        if(dista[i]>mx){
            b=i;
            mx=dista[i];
        }
    }
    Vl distb(n,inf);
    distb[b]=0;
    priority_queue<Pl,vector<Pl>,greater<Pl>> pqb;
    pqb.push({a,0});
    while(!pqb.empty()){
        auto [dis,whe]=pqb.top();
        pqb.pop();
        if(dis<=distb[whe]) continue;
        distb[whe]=dis;
        for(auto [u,cost]:graph[whe]){
            if(distb[u]!=inf) continue;
            pq0.push({distb[whe]+cost,u});
        }
    }
    ll ans=0;
    rep(i,n){
        chmax(ans,min(dista[i],distb[i]));
    }
    cout << ans << endl;


    

}