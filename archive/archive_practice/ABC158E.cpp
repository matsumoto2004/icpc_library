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
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

int main(){
    ll n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    mod=p;
    if(p==2){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%2==0){
                ans+=i+1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(p==5){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%5==0){
                ans+=i+1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    ll now=0;
    map<ll,ll> mp;
    mp[now]++;
    rep(i,n){
        now+=(s[n-1-i]-'0')*mpow(10,i);
        now%=mod;
        mp[now]++;
    }
    ll ans=0;
    for(auto [x,y]:mp){
        ans+=y*(y-1)/2;
    }
    cout << ans << endl;
}