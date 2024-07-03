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

VVl to;
Vl t;
Vl dis;
Vl ans;
ll n;

void tfs(ll v,ll p=-1){
    if(p!=-1) dis[v]=dis[p]+1;
    t[v]=1;
    for(ll next:to[v]){
        if(next==p) continue;
        tfs(next,v);
        
        t[v]+=t[next];
    }
}

void dfs(ll v,ll p=-1){
    for(ll next:to[v]){
        if(next==p) continue;
        ans[next]=ans[v]+(n-t[next])-t[next];
        dfs(next,v);

    }
}

int main(){
    cin >> n;
    to.resize(n);
    t.resize(n);
    dis.resize(n,0);
    ans.resize(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        to[a].PB(b);
        to[b].PB(a);
    }
    tfs(0);
    rep(i,n) ans[0]+=dis[i];
    dfs(0);
    rep(i,n) cout << ans[i] << endl;
}