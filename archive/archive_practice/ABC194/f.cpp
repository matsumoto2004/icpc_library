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

mint dp[200005][17];
ll past[200005][16];

ll chartoll(char c){
    ll ret=0;
    if(c>='0'&&c<='9') ret=c-'0';
    else ret=c-'A'+10;
    return ret;
}

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n=s.size();
    Vl v(n);
    rep(i,n) v[i]=chartoll(s[i]);

    past[0][v[0]]=1;
    rrep(i,1,n){
        rep(j,16){
            past[i][j]=past[i-1][j];
        }
        past[i][v[i]]=1;
    }

    dp[0][1]=v[0]-1;
    rrep(i,1,n){
        //
        rrep(j,1,17){
            dp[i][j]+=dp[i-1][j]*j;
            dp[i][j]+=dp[i-1][j-1]*(16-(j-1));
        }
        //
        dp[i][1]+=15;
        //
        ll cnt=0;
        rep(j,16) cnt+=past[i-1][j];
        rep(j,v[i]){
            if(past[i-1][j]==0) dp[i][cnt+1]+=1;
            else dp[i][cnt]+=1;
        }
    }
    ll cnt=0;
    rep(j,16) cnt+=past[n-1][j];

    dp[n-1][cnt]+=1;
    cout << dp[n-1][k].x << endl;


}
