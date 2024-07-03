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

ll big=1e9;

pair<ll,ll> topair(ll x){
    return {x/big,x%big};
}

ll toll(ll x,ll y){
    ll ret=x*big+y;
    return ret;
}

Vl dx={1,0,-1,0};
Vl dy={0,1,0,-1};

bool safe(ll x,ll y,ll h,ll w){
    if(x<0||y<0) return false;
    if(x>=h||y>=w) return false;
    return true;
}

int main(){
    ll h,w,k;
    cin >> h >> w >> k;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;

    vector<string> v(h);
    rep(i,h) cin >> v[i];

    vector<vector<vector<ll>>> dist(h+5,VVl(w+5,Vl(4,inf)));

    priority_queue<pair<ll,tuple<ll,ll,ll>>> pq;//負の数つっこむ

    //rep(ii,4) dist[x1][y1][ii]=0;
    rep(ii,4) pq.push({-big,{x1,y1,ii}});

    while(!pq.empty()){
        auto [pf,ps]=pq.top();
        pq.pop();
        pf*=-1;
        auto [dis,cnt]=topair(pf);
        auto [x,y,dir]=ps;
        if(dist[x][y][dir]<=pf) continue;
        else dist[x][y][dir]=pf;

        //cout << x << y << dir << " " << dist[x][y][dir] << endl;
        rep(i,4){
            if(i==dir){
                ll tox=x+dx[i],toy=y+dy[i];
                if(safe(tox,toy,h,w)==false) continue;
                if(v[tox][toy]=='@') continue;
                if(cnt<k) pq.push({-toll(dis,cnt+1),{tox,toy,i}});
                else pq.push({-toll(dis+1,1),{tox,toy,i}});
            }
            else{
                pq.push({-toll(dis+1,0),{x,y,i}});
            }
        }
    }
    
    ll ans=inf;
    rep(ii,4) chmin(ans,dist[x2][y2][ii]);

    if(ans==inf){
        cout << -1 << endl;
        return 0;
    }
    else{
        auto p=topair(ans);
        ans=p.first;
    }
    cout << ans << endl;

}