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

ll dp[2005][2005][2][2];

int main(){
    ll h,w;
    cin >> h >> w;
    Vl vr(h),vc(w);
    rep(i,h) cin >> vr[i];
    rep(i,w) cin >> vc[i];
    vector<string> v(h);
    rep(i,h) cin >> v[i];
    ll ans=inf;
    rep(i,h)rep(j,w)rep(ii,2)rep(jj,2) dp[i][j][ii][jj]=inf;
    rep(ii,2)rep(jj,2){
        ll co=0;
        if(ii) co+=vr[0];
        if(jj) co+=vc[0];
        dp[0][0][ii][jj]=co;
    }
    rep(i,h)rep(j,w)rep(ii,2)rep(jj,2){
        ll now=(v[i][j]-'0'+ii+jj)%2;
        if(i+1<h){
            ll next=v[i+1][j]-'0';
            if(jj) next=1-next;
            if(now==next) chmin(dp[i+1][j][0][jj],dp[i][j][ii][jj]);
            else chmin(dp[i+1][j][1][jj],dp[i][j][ii][jj]+vr[i+1]);
        }
        if(j+1<w){
            ll next=v[i][j+1]-'0';
            if(ii) next=1-next;
            if(now==next) chmin(dp[i][j+1][ii][0],dp[i][j][ii][jj]);
            else chmin(dp[i][j+1][ii][1],dp[i][j][ii][jj]+vc[j+1]);
        }
    }
    rep(ii,2)rep(jj,2) chmin(ans,dp[h-1][w-1][ii][jj]);
    cout << ans << endl;
}