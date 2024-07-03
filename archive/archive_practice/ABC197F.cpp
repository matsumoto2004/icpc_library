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
    char c;
};

vector<vector<Edge>> graph(1005),graph2(1005);

int main(){
    ll n,m;
    cin >> n >> m;
    set<Pl> edges;
    rep(i,m){
        ll x,y;
        char c;
        cin >> x >> y >> c;
        x--;y--;
        graph[x].push_back({y,c});
        graph[y].push_back({x,c});
        graph2[y].push_back({x,c});
        graph2[x].push_back({y,c});
        edges.insert({x,y});
        edges.insert({y,x});
    }
    VVl dist(n,Vl(n,inf));
    dist[0][n-1]=0;

    queue<Pl> que;
    que.push({0,n-1});

    //cout << "ok" << endl;
    ll ans=inf;

    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop();
        if(x==y){
            chmin(ans,dist[x][y]);
        }
        if(edges.find({x,y})!=edges.end()){
            chmin(ans,dist[x][y]+1);
        }

        for(auto [tox,cx]:graph[x]){
            for(auto [toy,cy]:graph2[y]){
                if(cx!=cy) continue;
                if(dist[tox][toy]!=inf) continue;
                dist[tox][toy]=dist[x][y]+2;
                que.push({tox,toy});
            }
        }

    }
    if(ans==inf) ans=-1;
    cout << ans << endl;

}