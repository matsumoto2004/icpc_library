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

ll mysqrt(ll n){
    ll ret=floor(sqrtl(n));
    if((ret+1)*(ret+1)<=n) return ret+1;
    else if(ret*ret<=n) return ret;
    else return ret-1;
}

int main(){
    ll t;
    cin >> t;
    rep(query,t){
        ll n;
        cin >> n;
        vector<ll> dp(mysqrt(mysqrt(n))+1);
        for(ll i=1;i*i*i*i<=n;i++){
            ll mn=i*i,mx=mysqrt(n);
            dp[i]=(mx-mn+1);
        }
        while(dp.size()>2){
            Vl newdp(mysqrt(dp.size()-1)+1);
            rrep(i,1,dp.size()){
                newdp[1]+=dp[i];
                if(mysqrt(i)+1!=newdp.size())newdp[mysqrt(i)+1]-=dp[i];
            }
            rep(i,newdp.size()-1) newdp[i+1]+=newdp[i];
            swap(newdp,dp);
        }
        cout << dp[1] << endl;
    }
}