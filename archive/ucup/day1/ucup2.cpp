#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i< ll(n);i++)
#define rep2(i,s,n) for(ll i=ll(s);i< ll(n);i++)
using vl = vector<ll>;
#define pb push_back

//ll mod=1000000007;
ll mod=998244353;

ll mpow(ll a,ll x){
    ll ret=1;
    ll now=a;
    rep(i,60){
        if((x>>i)&1) ret*=now;
        now*=now;

        ret%=mod;
        now%=mod;
    }
    ret%=mod;
    return ret;
}

template<typename T>
void print(vector<T> &a){
    for(T x:a)cout << x << " ";
    cout << endl;
}

void solve(){
    ll n;
    cin >> n;
    vl v(n);
    rep(i,n) cin >> v[i];
    ll ans=mod-1;
    rep(bit,(1<<n)){
        ll xr=0;
        rep(i,n){
            if((bit>>i)&1) xr^=v[i];
        }
        bool ok=1;
        rep(i,n){
            if((bit>>i)&1){
                if(xr%v[i]!=0) ok=0;
            }
        }
        if(ok){
            ans+=1;
            ans%=mod;
        }
    }
    cout << ans << endl;
}

int main(){
    ll t;
    cin >> t;
    rep(i,t) solve();
}