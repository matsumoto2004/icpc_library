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

struct Points{
    vector<Pl>  ps;
    Points(){}
    void add(Pl p){
        ps.push_back(p);
    }
    void add(ll i,ll j){
        ps.emplace_back(i,j);
    }
    void init(){
        sort(all(ps));
    }
    P operator[](int i) const{return ps[i];}
    ll operator()(const Pl& p) const{
        return lower_bound(ps.begin(),ps.end(),p)-ps.begin();
    }

};

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};

int main(){
    ll h,w,n;
    cin >> h >> w >> n;
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    sx--;sy--;gx--;gy--;
    Points ps;
    map<ll,set<ll>> xtoy,ytox;
    ps.add(sx,sy);
    ps.add(gx,gy);
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        rep(j,4){
            ll tox=x+dx[j],toy=y+dy[j];
            ps.add(tox,toy);
        }
        xtoy[x].insert(y);
        ytox[y].insert(x);
    }
    ps.init();
    ll m=ps.ps.size();
    Vl dist(m,inf);
    queue<ll> que;
    auto push = [&](ll i,ll j,ll d){
        ll v=ps({i,j});
        if(dist[v]!=inf) return;
        dist[v]=d+1;
        que.push(v);
    };

    push(sx,sy,-1);

    while(!que.empty()){
        ll v=que.front();que.pop();
        ll d=dist[v];
        auto [x,y]=ps.ps[v];
        //cout << x << " " << y << endl;
        //横移動
        {
        auto it=xtoy[x].lower_bound(y);
        if(it!=xtoy[x].end()){
            push(x,*it-1,d);
        }
        if(it!=xtoy[x].begin()){
            it--;
            push(x,*it+1,d);
        }
        }
        //縦移動
        {
        auto it=ytox[y].lower_bound(x);
        if(it!=ytox[y].end()){
            push(*it-1,y,d);
        }
        if(it!=ytox[y].begin()){
            it--;
            push(*it+1,y,d);
        }
        }
    }
    ll ans=dist[ps({gx,gy})];
    if(ans==inf) ans=-1;
    cout << ans << endl;
}