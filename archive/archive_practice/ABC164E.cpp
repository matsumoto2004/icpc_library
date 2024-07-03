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

ll big=4000;

ll toll(pair<ll,ll> p){
    return p.F*big+p.S;
}
pair<ll,ll> topair(ll x){
    return {x/big,x%big};
}

struct Edge{
    ll to;
    ll cost;
    ll time;
};

struct Mypair{
    ll dis;
    ll whe;
    ll cnt;
    ll getnum(){
        return toll({whe,cnt});
    }
    
};

bool operator<(const Mypair& one,const Mypair& other) {
    return one.dis < other.dis;
}

bool operator>(const Mypair& one,const Mypair& other) {
    return one.dis > other.dis;
}

int main(){
    ll n,m,s;
    cin >> n >> m >> s;
    chmin(s,big-1);

    Vl dist(n*big+5,inf);
    priority_queue<Mypair,vector<Mypair>,greater<Mypair>> pq;
    pq.push({0,0,s});

    vector<vector<Edge>> graph(n);
    Vl vc(n),vd(n);
    rep(i,m){
        ll x,y,xx,yy;
        cin >> x >> y >> xx >> yy;
        x--;y--;
        graph[x].push_back({y,xx,yy});
        graph[y].push_back({x,xx,yy});
    }
    rep(i,n) cin >> vc[i] >> vd[i];

    while(!pq.empty()){
        auto [dis,whe,cnt]=pq.top();
        pq.pop();
        if(dist[toll({whe,cnt})]==inf) dist[toll({whe,cnt})]=dis;
        else continue;

        //cout << "ok" << endl;

        ll now=dist[toll({whe,cnt})];

        for(auto [to,cost,time]:graph[whe]){
            if(cost>cnt) continue;
            pq.push({now+time,to,cnt-cost});            
        }
        pq.push({now+vd[whe],whe,min(cnt+vc[whe],big-1)});
    }
    Vl ans(n,inf);
    rep(i,n)rep(j,big) chmin(ans[i],dist[toll({i,j})]);
    rrep(i,1,n){
        cout << ans[i] << endl;
    }
}