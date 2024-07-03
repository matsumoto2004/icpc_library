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
    VVl graph(n);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].PB(y);
        graph[y].PB(x);
    }
    ll q;
    cin >> q;
    rep(query,q){
        ll x,k;
        cin >> x >> k;
        x--;
        map<ll,ll> dist;
        dist[x]=1;
        queue<ll> que;
        que.push(x);
        ll ans=0;
        while(!que.empty()){
            ll v=que.front();
            que.pop();
            ans+=v+1;
            if(dist[v]==k+1) continue;
            for(auto u:graph[v]){
                if(dist[u]!=0) continue;
                dist[u]=dist[v]+1;
                que.push(u);
            }
        }
        cout << ans << endl;
    }
}