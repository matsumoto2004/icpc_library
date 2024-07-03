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

#define btcnt __builtin_popcountll

long double dp[20][1<<12][1<<5];

long double dist(ll x1,ll y1,ll x2,ll y2){
    long double ret=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    ret=sqrt(ret);
    return ret;
}

int main(){
    ll n,m;
    cin >> n >> m;
    Vl vx(n),vy(n);
    Vl vp(m),vq(m);
    rep(i,n) cin >> vx[i] >> vy[i];
    rep(i,m) cin >> vp[i] >> vq[i];
    rep(i,n+m)rep(j,1<<n)rep(ii,1<<m) dp[i][j][ii]=inf;
    //to街
    rep(i,n){
        dp[i][1<<i][0]=dist(0,0,vx[i],vy[i]);
    }
    //to宝箱
    rep(i,m){
        dp[n+i][0][1<<i]=dist(0,0,vp[i],vq[i]);
    }

    //dp開始
    rep(j,1<<n)rep(ii,1<<m)rep(i,n+m){
        if(i<n){
            if((j>>i)&1==0) continue;
        }
        else{
            if((ii>>(i-n))&1==0) continue;
        } 
        long double now=dp[i][j][ii];
        ll nowx,nowy;
        if(i<n) nowx=vx[i],nowy=vy[i];
        else nowx=vp[i-n],nowy=vq[i-n];
        rep(to,n){
            if((j>>to)&1) continue;
            long double pls=dist(nowx,nowy,vx[to],vy[to])/(1<<btcnt(ii));
            chmin(dp[to][j|(1<<to)][ii],now+pls);
        }
        rep(to,m){
            if((ii>>to)&1) continue;
            long double pls=dist(nowx,nowy,vp[to],vq[to])/(1<<btcnt(ii));
            chmin(dp[n+to][j][ii|(1<<to)],now+pls);
        }
        //cout << i << " " << j << " " << ii << " " << now << endl;
    }
    long double ans=inf;
    rep(i,n+m)rep(ii,1<<m){
        long double now=dp[i][(1<<n)-1][ii];
        long double pls;
        if(i<n){
            pls=dist(0,0,vx[i],vy[i])/(1<<btcnt(ii));
        }
        else{
            pls=dist(0,0,vp[i-n],vq[i-n])/(1<<btcnt(ii));
        }
        chmin(ans,now+pls);

    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}