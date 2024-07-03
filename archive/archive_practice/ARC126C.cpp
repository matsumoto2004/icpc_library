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


ll myceil(ll x,ll y){
    ll ret=x/y;
    if(x%y!=0) ret++;
    return ret;
}

ll big=600;

int main(){
    ll n,k;
    cin >> n >> k;
    Vl v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    
    Vl required(3e5+5,0);
    rep(i,n){
        ll x=v[i];
        ll prev=3e5+1;
        required[prev]++;
        ll now=1;
        while(1){
            ll next=myceil(x,now)-1;
            now++;
            if(next<big) break;
            required[next]++;

        }

    }
    rrepd(i,big,3e5+1) required[i]+=required[i+1];
    rrep(i,1,big){
        rep(j,n){
            required[i]+=myceil(v[j],i);
        }
    }
    ll ans=1;
    ll sum=accumulate(all(v),0LL);
    rrep(i,2,3e5+2){
        ll mns=required[i]*i;
        if(mns-sum<=k) chmax(ans,(ll)i);
    }

    if((sum+k)/n>=3e5) chmax(ans,(sum+k)/n);
    cout << ans << endl;
}
