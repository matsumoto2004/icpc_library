
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
    ll ans=mod-1;//modとるのを忘れるな//なんもないを予め抜いてる

    map<ll,ll> cnt;
    rep(i,n) cnt[v[i]]++;

    //総xorが0
    {
        vl base;
        rep(i,n){
            ll x=v[i];
            for(auto y:base){
                x=min(x,x^y);
                
            }
            if(x!=0) base.pb(x);
        }

        ans+=mpow(2,n-base.size());
        ans%=mod;

        //print(base);
    }
    //cout << "a" << ans << endl;
    //総xorがvの要素
    rep2(i,1,n+1){
        if(cnt[i]==0) continue;
        ll pls=mpow(2,cnt[i]-1);
        ll num=0;
        vl base;
        for(ll j=1;(j*j<=i);j++){
            if(i%j!=0) continue;

            if(j==i) continue;
            
            if(cnt[j]!=0){
            num+=cnt[j];
            num%=mod;

            ll x=j;
            for(auto y:base){
                x=min(x,x^y);
                
            }
            if(x!=0) base.pb(x);
            }

            if(j*j!=i){
                ll jj=i/j;
                if(jj==i) continue;
                if(cnt[jj]!=0){
                num+=cnt[jj];
                num%=mod;
                ll xx=jj;
                for(auto y:base){
                    xx=min(xx,xx^y);
                   
                }
                if(xx!=0) base.pb(xx);
                }
            }
        }
        pls*=mpow(2,num-base.size());
        pls%=mod;
        ans+=pls;
        ans%=mod;

        //cout << i << ans << endl;    
    }

    cout << ans << endl;
}

int main(){
    //cout << mpow(2,10) << endl;
    ll t;
    cin >> t;
    rep(i,t) solve();
}
