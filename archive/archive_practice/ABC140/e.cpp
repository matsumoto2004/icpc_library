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
    Vl v(n);
    rep(i,n) cin >> v[i];
    rep(i,n) v[i]--;
    map<ll,ll> rev;
    rep(i,n) rev[v[i]]=i;
    multiset<ll> st;
    st.insert(-1);
    st.insert(-1);
    st.insert(n);
    st.insert(n);

    ll ans=0;

    repd(i,n){
        ll now=rev[i];
        auto it=st.upper_bound(now);
        ll a,b,c,d;
        c=*it;
        it++;
        d=*it;
        it--;it--;
        b=*it;
        it--;
        a=*it;

        ans+=(now-b)*(d-c)*(i+1);
        ans+=(c-now)*(b-a)*(i+1);
        st.insert(now);
    }
    cout << ans << endl;
}