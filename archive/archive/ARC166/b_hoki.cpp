#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)

ll INF = __LONG_LONG_MAX__;

//拡張ユークリッドの互除法
//ap+bq = gcd(a,b)となるp,qを求め、gcd(a,b)を返す
ll extGCD(ll a, ll b, ll &p, ll &q){
  if(b == 0){
    p = 1;
    q = 0;
    return a;
  }
  
  ll d = extGCD(b, a%b, q, p);
  q -= a/b*p;
  
  return d;
  
}

int main(){
    int n;
    vl M(3), m(3);
    cin >> n;
    rep(i, 0, 3){
        cin >> M[i];
    }
    vl a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    ll ans = INF;
    vl ID = {0, 1, 2};
    m = M;
    //aから3箇所選ぶとき
    do{
        if(a.size() < 3){
            continue;
        }
        m = {M[ID[0]], M[ID[1]], M[ID[2]]};
        ll sum = 0;
        set<ll> id;
        rep(i, 0, 3){
            int idx = -1;
            ll mn = INF;
            rep(j, 0, n){
                if(mn > (m[i]-a[j]%m[i])%m[i] && !(id.count(j))){
                    idx = j;
                    mn = (m[i]-a[j]%m[i])%m[i];
                }
            }
            id.insert(idx);
            sum += mn;
        }
        ans = min(ans, sum);
        
    }while(next_permutation(ID.begin(), ID.end()));

    sort(ID.begin(), ID.end());
    do{
        if(a.size() < 2){
            continue;
        }
        m = {M[ID[0]], M[ID[1]], M[ID[2]]};
        ll p, q;
        ll gcd = extGCD(m[0], m[1], p, q);
        vl md = {m[0]/gcd*m[1], m[2]};
        ll sum = 0;
        set<ll> id;
        rep(i, 0, 2){
            int idx = -1;
            ll mn = INF;
            rep(j, 0, n){
                if(mn > (md[i]-a[j]%md[i])%md[i] && !(id.count(j))){
                    idx = j;
                    mn = (md[i]-a[j]%md[i])%md[i];
                }
            }
            id.insert(idx);
            sum += mn;
        }
        ans = min(ans, sum);
        
    }while(next_permutation(ID.begin(), ID.end()));

    sort(ID.begin(), ID.end());
    do{
        if(a.size() < 2){
            continue;
        }
        m = {M[ID[0]], M[ID[1]], M[ID[2]]};
        ll p, q;
        ll gcd = extGCD(m[0], m[1], p, q);
        vl md = {m[2], m[0]/gcd*m[1]};
        sort(md.begin(),md.end());
        do{
        ll sum = 0;
        set<ll> id;
        rep(i, 0, 2){
            int idx = -1;
            ll mn = INF;
            rep(j, 0, n){
                if(mn > (md[i]-a[j]%md[i])%md[i] && !(id.count(j))){
                    idx = j;
                    mn = (md[i]-a[j]%md[i])%md[i];
                }
            }
            id.insert(idx);
            sum += mn;
        }
        ans = min(ans, sum);
        }while(next_permutation(md.begin(),md.end()));
        
    }while(next_permutation(ID.begin(), ID.end()));

    ll p, q;
    ll gcd=extGCD(m[0], m[1], p, q);
    ll gcd1 = extGCD(m[0]/extGCD(m[0], m[1], p, q)*m[1], m[2], p, q);
    ll x = m[0]/gcd*m[1]/gcd1*m[2];
    rep(i, 0, n){
        ans = min(ans, (x-a[i]%x)%x);
    }

    cout << ans << endl;
    
    return 0;
    
}