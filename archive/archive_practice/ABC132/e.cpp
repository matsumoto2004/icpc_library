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
        graph[x].push_back(y);
        //graph[y].push_back(x);
    }
    ll s,t;
    cin >> s >> t;
    s--;t--;
    VVl dist(n,Vl(3,inf));
    dist[s][0]=0;
    deque<Pl> que;
    que.push_front({s,0});
    while(!que.empty()){
        auto p=que.front();
        que.pop_front();
        if(p.S!=2){
            for(auto to:graph[p.first]){
                if(dist[to][p.second+1]!=inf) continue;
                dist[to][p.second+1]=dist[p.first][p.second];
                que.push_front({to,p.second+1});
            }
        }
        else{
            for(auto to:graph[p.first]){
                if(dist[to][0]!=inf) continue;
                dist[to][0]=dist[p.first][p.second]+1;
                que.push_back({to,0});
            }
        }
    }
    ll ans=dist[t][0];
    if(ans==inf) ans=-1;
    cout << ans << endl;
}