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

Vl toa,tob;
Vl vp2,vi2;
void dfs(ll v){
    vp2.PB(v);
    //left
    if(toa[v]!=-1) dfs(toa[v]);
    //
    vi2.PB(v);
    if(tob[v]!=-1) dfs(tob[v]);
}

int main(){
    ll n;
    cin >> n;
    Vl vp(n),vi(n);
    rep(i,n) cin >> vp[i];
    rep(i,n) cin >> vi[i];
    rep(i,n) vp[i]--;
    rep(i,n) vi[i]--;
    if(vp[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    Vl ansl(n,-1),ansr(n,-1);
    ll now=0;
    ll state=0;//左か右か
    map<ll,ll> ma;
    ma[0]++;
    ll whe=0;
    if(vi[0]==0){
        whe++;
        state=1;
    }
    rrep(i,1,n){
        ll x=vp[i];
        ma[x]++;
        if(state==0){
            ansl[now]=x;
            now=x;
        }
        else{
            ansr[now]=x;
            now=x;
            state=0;
        }
        if(whe<n)while(ma[vi[whe]]==1){
            now=vi[whe];
            state=1;
            whe++;
            if(whe==n) break;
        }
        
    }
    toa=ansl;
    tob=ansr;
    dfs(0);
    if(0) cout << -1 << endl;
    else rep(i,n) cout << ansl[i]+1 << " " << ansr[i]+1 << endl;
}