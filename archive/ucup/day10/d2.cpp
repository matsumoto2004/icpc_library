#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
using vl=vector<long long>;
using vvl=vector<vl>;
using pl=pair<ll,ll>;
#define pb push_back

/*
int main(){
    ll x,y;
    cin >> x >> y;
    ll ans=0;
    for(ll i=x;i<=y;i++){
        ll now=i;
        ll cnt=0;
        for(ll pr=2;pr<1000;pr++){
            if(now%pr==0) cnt++;
            while(now%pr==0) now/=pr;
        }
        ans+=cnt;
    }
    cout << ans << endl;
}
*/

int main(){
    ll x,y;
    cin >> x >> y;
    map<ll,ll> mp;
    for(int i=x;i<=y;i++){
        ll now=i;
        for(ll pr=2;pr<10000;pr++){
            while(now%(pr*pr)==0) now/=pr;
        }
        mp[now]++;
    }
    cout << mp.size() << endl;
    //for(auto [x,y]:mp) cout << x << endl;
}