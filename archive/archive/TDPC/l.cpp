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
    ll n;
    cin >> n;
    VVl v(n,Vl(n));
    rep(i,n)rep(j,n) cin >> v[i][j];
    rep(i,n)repd(j,i) v[i][j]+=v[i][j+1];
    VVl dp(n+5,Vl(n+5,-inf));
    dp[0][0]=0;
    rrep(i,1,n){
        ll mx=-inf;
        rep(j,i+1){
            chmax(mx,dp[i-1][j]);
            chmax(dp[i][j],mx+v[i][j]);
        }
    }
    ll ans=0;
    rep(i,n) chmax(ans,dp[n-1][i]);
    cout << 2*ans << endl;
}