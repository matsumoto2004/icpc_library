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

vector<vector<Edge>> graph(305);

ll mx=1e13;

ll toll(ll x,ll y){
    return x*mx+y;
}

pair<ll,ll> topair(ll x){
    return {x/mx,x%mx};
}

int main(){
    ll n,m,l;
    cin >> n >> m >> l;
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<Pl,vector<Pl>,greater<Pl>> pq;
    VVl dist(n,Vl(n,inf)); //燃料の使用量

    rep(i,n){
        pq.push({0,i});
        while(!pq.empty()){
            auto [dis,now]=pq.top();
            //cout << dis << " " << now << endl;
            pq.pop();
            if(dist[i][now]<=dis) continue;
            dist[i][now]=dis;

            ll cnt=dis/mx,used=dis%mx;

            for(auto [to,cost]:graph[now]){
                if(cost>l) continue;
                if(used+cost<=l&&dist[i][to]==inf) pq.push({cnt*mx+used+cost,to});
                else if(dist[i][to]==inf) pq.push({(cnt+1)*mx+cost,to});
            }
        }
    }

    ll q;
    cin >> q;
    rep(qi,q){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        ll ans=inf;
        rep(i,n+1){
            if(dist[x][y]!=inf) chmin(ans,dist[x][y]/mx);
        }
        if(ans==inf) ans=-1;
        cout << ans << endl;
    }

}