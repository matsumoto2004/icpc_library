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
    ll id;
};

struct Mypair{
    ll dis;
    ll v;
    ll id;

};

bool operator>(const Mypair &mp1,const Mypair &mp2){
    if(mp1.dis>mp2.dis) return true;
    else return false;
}
    

vector<vector<Edge>> graph;
Vl dist;
Vl ans;

int main(){
    ll n,m;
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n,inf);
    rep(i,m){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        graph[x].PB({y,z,i});
        graph[y].PB({x,z,i});
    }
    priority_queue<Mypair,vector<Mypair>,greater<Mypair>> pq;
    pq.push({0,0,-1});
    while(!pq.empty()){
        auto [dis,v,id]=pq.top();
        pq.pop();
        if(dis>=dist[v]) continue;
        ans.PB(id);
        dist[v]=dis;
        for(auto [u,cost,uid]:graph[v]){
            pq.push({dis+cost,u,uid});
        }
    }
    for(auto x:ans){
        if(x!=-1) cout << x+1 << " ";
    }
    cout << endl;

}