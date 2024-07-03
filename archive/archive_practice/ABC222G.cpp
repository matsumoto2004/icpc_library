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
ll mod = 998244353;
ll phi=-1;
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
  mint inv() const { return pow(phi-1);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

ll big=10005;

int64_t euler_phi(int64_t n) {
  int64_t ret = n;
  for(int64_t i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ret -= ret / n;
  return ret;
}


int main(){
    ll t;
    cin >> t;
    rep(ti,t){
        ll k;
        cin >> k;
        if(k==1||k==2){
            cout << 1 << endl;
            continue;
        }
        mod=k;
        phi=euler_phi(k);

        //ax+bのa,bを求める
        vector<mint> va(big+5,0),vb(big+5,0);
        va[0]=1;vb[0]=0;
        rep(i,big){
            va[i+1]=va[i]*10; 
            vb[i+1]=vb[i]*10+2;
        }

        //まずはbabyに存在するか判定
        ll ans=inf;
        map<ll,ll> mp;
        rep(i,big){
            mint now=va[i]*2+vb[i];
            if(now.x==0){
                chmin(ans,(ll)(i+1));
            }
            if(mp.count(now.x)==0) mp[now.x]=i;
        }

        if(ans!=inf){
            cout << ans << endl;
            continue;
        }

        //giant
        vector<mint> va2(big+5,0),vb2(big+5,0);
        va2[0]=va[big];vb2[0]=vb[big];//big回合成

        rep(i,big){
            va2[i+1]=va2[i]*va[big]; 
            vb2[i+1]=vb2[i]*va[big]+vb[big];
        }

        rep(i,big){
            mint req=-vb2[i];
            req/=va2[i];
            if(mp.count(req.x)){
                chmin(ans,big*(i+1)+mp[req.x]+1);
            }
        }

        if(ans==inf) ans=-1;
        cout << ans << endl;



    }
}
