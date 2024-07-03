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
    set<Pl> notedge;
    VVl notfrom(n);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        notedge.insert(make_pair(x,y));
        notedge.insert(make_pair(y,x));
        notfrom[x].push_back(y);
        notfrom[y].push_back(x);
    }
    set<ll> st;
    rrep(i,1,n) st.insert(i);
    Vl dist(n,-1);
    queue<ll> que;
    que.push(0);
    dist[0]=0;

    //cout << "ok" << endl;

    while(!que.empty()){
        ll from=que.front();
        que.pop();

        auto it=st.begin();
        while(it!=st.end()){
            ll to=*it;
            if(notedge.find(make_pair(from,to))!=notedge.end()){
                it++;
                continue;
            }
            dist[to]=dist[from]+1;
            que.push(to);
            it++;
            st.erase(st.find(to));
        }
    }

    //cout << "ok" << endl;

    ll mx=dist[n-1];

    if(mx==-1){
        cout << -1 << endl;
        return 0;
    }

    VVl disttov(200005);
    rep(i,n) if(dist[i]<=mx&&dist[i]>=0)disttov[dist[i]].push_back(i);

    vector<mint> cnt(n,0);
    cnt[0]=1;

    rrep(i,1,mx+1){
        mint sum=0;
        for(auto x:disttov[i-1]) sum+=cnt[x];
        for(auto x:disttov[i]){
            cnt[x]=sum;
            for(auto y:notfrom[x]){
                if(dist[y]!=-1)if(dist[y]+1==dist[x]) cnt[x]-=cnt[y];
            }
        }
    }
    cout << cnt[n-1].x << endl;

}