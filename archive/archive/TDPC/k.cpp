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
    ll n;
    cin >> n;
    Vl vx(n),vr(n);
    rep(i,n) cin >> vx[i] >> vr[i];
    vector<Pl> v(n);
    rep(i,n) v[i]={vx[i]-vr[i],vx[i]+vr[i]};
    sort(all(v));
    Vl v2(n);
    rep(i,n) v2[i]=v[n-i-1].S;
    Vl dp(n+5,inf);
    for(auto x:v2){
        ll whe=lower_bound(all(dp),x)-dp.begin();
        dp[whe]=x;
        //cout << whe << endl;
    }
    ll ans=0;
    rep(i,n+1) if(dp[i]!=inf) ans=i;
    cout << ans+1 << endl;
}

/*
0 2
-3 3
1 5
*/

/*
*/