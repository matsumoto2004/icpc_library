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
    ll n,m;
    cin >> n >> m;
    ll q;
    cin >> q;
    rep(query,q){
        //(a,c)(b,d)
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        ll a1=a,a2=a;
        ll b1=b,b2=b;
        ll c1=c,c2=c;
        ll d1=d,d2=d;
        if(a%2==1) a1++;
        else a2++;
        if(b%2==1) b1--;
        else b2--;
        if(c%2==1) c1++;
        else c2++;
        if(d%2==1) d1--;
        else d2--;
        //1
        ll avg1=m*(a1+b1)+(c1+d1)+2;
        ll cnt1=((b1-a1)/2+1)*((d1-c1)/2+1);
        //2
        ll avg2=m*(a2+b2)+(c2+d2)+2;
        ll cnt2=((b2-a2)/2+1)*((d2-c2)/2+1);
        mint ans=0;
        mint ans1=avg1;
        ans1*=cnt1;
        ans1/=2;
        mint ans2=avg2;
        ans2*=cnt2;
        ans2/=2;
        ans=ans1+ans2;
        cout << ans.x << endl;

    }
}