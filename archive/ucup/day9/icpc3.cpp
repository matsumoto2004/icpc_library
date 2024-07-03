#include<bits/stdc++.h>
#include<cassert>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/tag_and_trait.hpp>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(i, n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i, s, n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i, s, n, d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i, n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i, n, t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i, n, t, d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SUM(a) accumulate(all(a),0LL)
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SORT(a) sort(all(a));
#define REV(a) reverse(all(a));
#define SZ(a) int(a.size())
#define popcount(x) __builtin_popcountll(x)
#define pf push_front
#define pb push_back
#define ef emplace_front
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0);
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vp = vector<P>;
using vvp = vector<vp>;

ll linf=2e18;
ll inf=2e9;

void chmax(ll &x,ll y){
    x=max(x,y);
    return;
}

void chmin(ll &x,ll y){
    x=min(x,y);
    return;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vl v(n);
    rep(i,n) cin >> v[i];
    vector<LP> v2(n);
    rep(i,n) v2[i]={v[i],i};
    sort(all(v2));//v2は小さい順に並んでいる 同じなら
    vl  disc(n+5,0);//discount
    
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;
        disc[x]+=y;
    }
    rrep(i,n) disc[i]+=disc[i+1];
    ll now=0;
    ll fir=linf;

    vl memo(n+5);
    rep(i,n) memo[i]=disc[i]-v[i];
    rep(i,n) chmax(memo[i+1],memo[i]);

    rep(i,n){
        now+=v2[i].first;
        chmin(fir,v2[i].second);

        //下から順に貪欲に取る
        ll ans=now-disc[fir];

        //1個だけ変える
        if(fir!=0){
            ll cand=memo[fir-1];
            ans-=max(0LL,cand-(disc[fir]-v2[i].first));
        }
        cout << ans;
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    rep(i,t) solve();
}