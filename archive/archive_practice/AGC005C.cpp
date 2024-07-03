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
    sort(all(v));
    map<ll,ll> mp;
    rep(i,n) mp[v[i]]++;



    Vl vx,vy;
    for(auto [x,y]:mp){
        vx.push_back(x);
        vy.push_back(y);
    }
    ll ok=1;
    ll mx=-1;

    if(vy[0]>2) ok=0;
    if(vy[0]==2) mx=2*vx[0]-1;
    if(vy[0]==1) mx=2*vx[0];
    if(vx.back()>mx) ok=0;
    
    rrep(i,1,vx.size()){
        if(vx[i]!=vx[i-1]+1) ok=0;
        if(vy[i]<=1) ok=0;
    }
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

}
