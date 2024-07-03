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

vector<long long> compress(vector<long long> v){
    vector<long long> v2=v;
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());

    vector<long long> ret(v.size());
    for(int i=0;i<v.size();i++){
        ret[i]=lower_bound(v2.begin(),v2.end(),v[i])-v2.begin();
    }
    return ret;
}

int main(){
    ll n;
    cin >> n;
    Vl vx(n),vc(n);
    rep(i,n) cin >> vx[i] >> vc[i];
    vc=compress(vc);
    ll color=0;
    rep(i,n) chmax(color,vc[i]);
    color++;
    Vl mx(color,-inf),mn(color,inf);
    rep(i,n){
        chmax(mx[vc[i]],vx[i]);
        chmin(mn[vc[i]],vx[i]);
    }
    Vl dp1(color+5,inf),dp2(color+5,inf);
    dp1[0]=abs(0-mx[0])+abs(mx[0]-mn[0]);
    dp2[0]=abs(0-mn[0])+abs(mn[0]-mx[0]);

    rrep(i,1,color){
        chmin(dp1[i],dp1[i-1]+abs(mn[i-1]-mx[i])+abs(mn[i]-mx[i]));
        chmin(dp1[i],dp2[i-1]+abs(mx[i-1]-mx[i])+abs(mn[i]-mx[i]));
        chmin(dp2[i],dp1[i-1]+abs(mn[i-1]-mn[i])+abs(mn[i]-mx[i]));
        chmin(dp2[i],dp2[i-1]+abs(mx[i-1]-mn[i])+abs(mn[i]-mx[i]));
    }
    ll ans=inf;
    chmin(ans,dp1[color-1]+abs(0-mn[color-1]));
    chmin(ans,dp2[color-1]+abs(0-mx[color-1]));
    cout << ans << endl;
}