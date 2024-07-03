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

long double prob(ll pp,ll qq){
    long double p=pp,q=qq;
    long double ret=1;
    ret/=1+pow(10,(q-p)/400);
    return ret;
}

int main(){
    ll logk;
    cin >> logk;
    ll k=(1<<logk);
    Vl v(k);
    rep(i,k) cin >> v[i];
    vector<long double> dp(k,0);
    rep(i,k) dp[i]=1;
    rep(i,logk){
        vector<long double> newdp(k,0);
        rep(j,k){
            long double now=0;
            ll mn=(j/(1<<i))*(1<<i);
            mn^=(1<<i);
            ll mx=(j/(1<<i)+1)*(1<<i)-1;//[mn,mx]
            mx^=(1<<i);
            rrep(ii,mn,mx+1){
                now+=dp[j]*dp[ii]*prob(v[j],v[ii]);
            }
            newdp[j]=now;
        }
        swap(dp,newdp);
    }
    cout << fixed << setprecision(12);
    rep(i,k) cout << dp[i] << endl;
}