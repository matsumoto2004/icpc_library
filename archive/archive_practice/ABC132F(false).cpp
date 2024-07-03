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
const ll mod = 1e9+7;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

//modint構造体

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

int main(){
    ll n,k;
    cin >> n >> k;
    ll mx=0;
    while(mx*mx<=n) mx++;//mx未満までok
    vector<vector<mint>> dp(k+5,vector<mint>(mx+5,0));//普通のdp
    vector<mint> dp2(k+5,0);//1になるしかないクソデカを管理
    rrep(i,1,mx) dp[0][i]=1;
    dp2[0]=n-mx+1;

    //配るdp
    rrep(i,0,k-1){
        rrep(j,1,mx){
            ll nextmx=k/j;
            if(nextmx<mx){
                dp[i+1][1]+=dp[i][j];//後で累積和
                dp[i+1][nextmx+1]-=dp[i][j];
            }
            else{
                dp2[i+1]+=nextmx-mx+1;
            }
            rep(j,mx) dp[i+1][j+1]+=dp[i+1][j];
            dp[i+1][0]+=dp2[i];
        }
    }
    mint ans=0;
    rrep(i,1,mx) ans+=dp[k-1][i];
    ans+=dp2[k-1];
    cout << ans.x << endl;

}
