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

struct Compress{
    Vl v;
    
    void insert(ll x){
        v.push_back(x);
    }
    void init(){
        sort(all(v));
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }
    ll get(ll x){
        return lower_bound(all(v),x)-v.begin();
    }
    ll rev(ll x){
        return v[x];
    }
    ll getmax(){
        return v.size();
    }

};


int main(){
    ll n,c;
    cin >> n >> c;
    Vl va(n),vb(n),vc(n);
    rep(i,n) cin >> va[i] >> vb[i] >> vc[i];
    rep(i,n){
        va[i]--;vb[i]--;
    }
    Compress cp;
    rep(i,n){
        cp.insert(va[i]);
        cp.insert(vb[i]);
        cp.insert(va[i]+1);
        cp.insert(vb[i]+1);
    }
    cp.insert(inf);
    cp.init();
    rep(i,n){
        va[i]=cp.get(va[i]);
        vb[i]=cp.get(vb[i]);
    }
    ll mx=cp.getmax();
    Vl rui(mx+5,0);

    rep(i,n){
        rui[va[i]]+=vc[i];
        rui[vb[i]+1]-=vc[i];
    }
    rep(i,mx) rui[i+1]+=rui[i];
    rep(i,mx) chmin(rui[i],c);

    ll ans=0;
    rep(i,mx){
        ans+=rui[i]*(cp.rev(i+1)-cp.rev(i));
        //cout << i << " " << rui[i] << endl;
    }
    cout << ans << endl;
}