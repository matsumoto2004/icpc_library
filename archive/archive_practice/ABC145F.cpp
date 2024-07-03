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
    ll n,K;
    cin >> n >> K;
    Vl v(n);
    rep(i,n) cin >> v[i];
    rep(i,301)rep(j,301)rep(k,301) dp[i][j][k]=inf;
    dp[0][0][0]=0;
    rep(i,n)rep(j,i+1)rep(k,j+1){
        //nochange
        if(i!=k) chmin(dp[i+1][j][0],dp[i][j][k]+max(0LL,v[i]-v[i-k-1]));
        else chmin(dp[i+1][j][0],dp[i][j][k]+max(0LL,v[i]));
        //change
        chmin(dp[i+1][j+1][k+1],dp[i][j][k]);
    }
    ll ans=inf;
    rep(j,K+1)rep(k,j+1) chmin(ans,dp[n][j][k]);
    cout << ans << endl;
}
