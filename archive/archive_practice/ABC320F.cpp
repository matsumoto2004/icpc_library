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

ll dp[305][305][305];

int main(){
    ll n,h;
    cin >> n >> h;
    Vl vx(n+1,0);
    rep(i,n) cin >> vx[i+1];
    Vl vp(n-1),vf(n-1);
    rep(i,n-1) cin >> vp[i] >> vf[i];

    //cout << "ok" << endl;

    rep(i,n+1)rep(j,h+1)rep(ii,h+1) dp[i][j][ii]=inf;
    dp[0][h][h]=0;

    //cout << "ok" << endl;

    rep(i,n-1)rep(j,h+1)rep(k,h+1){
        ll nowx=vx[i],tox=vx[i+1];
        ll dis=tox-nowx;
        if(j<dis||k<dis) continue;
        //たさない
        chmin(dp[i+1][j-dis][k-dis],dp[i][j][k]);

        chmin(dp[i+1][min(j-dis+vf[i],h)][k-dis],dp[i][j][k]+vp[i]); 
        chmin(dp[i+1][j-dis][min(k-dis+vf[i],h)],dp[i][j][k]+vp[i]);
    }
    rep(j,h+1)rep(k,h+1){
        ll nowx=vx[n-1],tox=vx[n];
        ll dis=tox-nowx;
        if(j<dis||k<dis) continue;
        //たさない
        chmin(dp[n][j-dis][k-dis],dp[n-1][j][k]);
    }

    ll ans=inf;

    rep(j,h+1)rep(k,h+1){
        if(j+k<h) continue;
        chmin(ans,dp[n][j][k]);
    }
    if(ans==inf) ans=-1;

    cout << ans << endl;

}
