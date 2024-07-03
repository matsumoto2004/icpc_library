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
    Vl vs(n-1),vm(m);
    rep(i,n-1) cin >> vs[i];
    rep(i,m) cin >> vm[i];
    Vl dp(n+5,0);
    VVl dp2(n+5,Vl(m+5,0));
    dp[0]=0;
    rep(i,m) dp2[0][i]=1;
    rrep(i,1,n){
        //i-1→i
        chmax(dp[i],dp[i-1]);
        rep(j,m) chmax(dp[i],dp2[i-1][j]);
        rep(j,m) chmax(dp2[i][j],dp[i-1]+1);
        rep(j,m)rep(k,m){
            if(vm[j]+vm[k]==vs[i-1]){
                chmax(dp2[i][k],dp2[i-1][j]+1);
            }
        }
    }
    ll ans=0;
    chmax(ans,dp[n-1]);
    rep(j,m) chmax(ans,dp2[n-1][j]);
    cout << ans << endl;
}