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
    vector<pair<ll,ll>> vp(n),ans;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        vp[i]={x,y};
    }
    sort(all(vp));
    ll nowl=vp[0].F,nowr=vp[0].S;
    for(auto[l,r]:vp){
        if(nowr<l){
            ans.PB({nowl,nowr});
            nowl=l;
            nowr=r;
        }
        if(nowr<r) nowr=r;
    }
    ans.PB({nowl,nowr});
    cout << ans.size() << endl;
    for(auto [l,r]:ans) cout << l << " " << r << endl;
}