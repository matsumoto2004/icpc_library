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
//const ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

ll dp[105][105][105];//どこまで，個数，あまり　のmax

int main(){
    ll n,x;
    cin >> n >> x;
    Vl v(n);
    rep(i,n) cin >> v[i];
    ll ans=inf;
    rrep(mod,1,101){
       rep(i,101)rep(j,101)rep(k,101) dp[i][j][k]=-inf;
       dp[0][0][0]=0;
       dp[0][1][v[0]%mod]=v[0];
       rrep(i,1,n)rrep(j,1,mod+1)rep(k,mod){
          chmax(dp[i][j][k],dp[i-1][j-1][(k-v[i]+mod*10000000)%mod]+v[i]);
          chmax(dp[i][j][k],dp[i-1][j][k]);
       }
       if(dp[n-1][mod][x%mod]>0)chmin(ans,(x-dp[n-1][mod][x%mod])/mod);
    }
    cout << ans << endl;

}