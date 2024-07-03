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

ll dist[1505][1505][4];

Vl dx={1,1,-1,-1},dy={1,-1,1,-1};

struct Mypair{
    ll x;
    ll y;
    ll dir;
};

int main(){
    ll n;
    cin >> n;
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    ax--;ay--;bx--;by--;
    vector<string> vs(n);
    rep(i,n) cin >> vs[i];
    rep(i,n)rep(j,n)rep(k,4) dist[i][j][k]=inf;
    rep(k,4) dist[ax][ay][k]=1;
    deque<Mypair> dq;
    rep(k,4) dq.push_back({ax,ay,k});
    while(!dq.empty()){
        auto [x,y,dir]=dq.front();
        dq.pop_front();
        rep(k,4){
            if(k==dir){
                ll tox=x+dx[k];
                ll toy=y+dy[k];
                if(tox<0||tox>=n||toy<0||toy>=n) continue;
                if(vs[tox][toy]=='#') continue;
                if(dist[tox][toy][dir]<=dist[x][y][dir]) continue;
                dist[tox][toy][dir]=dist[x][y][dir];
                dq.push_front({tox,toy,dir});
            }
            else{
                if(dist[x][y][k]<=dist[x][y][dir]) continue;
                dist[x][y][k]=dist[x][y][dir]+1;
                dq.push_back({x,y,k});
            }
        }
        
    }
    ll ans=inf;
    rep(k,4) chmin(ans,dist[bx][by][k]);
    if(ans==inf) ans=-1;
    cout << ans << endl;
}