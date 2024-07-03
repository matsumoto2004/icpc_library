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
    VVl v(n,Vl(n-1));
    VVl dist(n,Vl(n-1+5,-1));
    rep(i,n)rep(j,n-1) cin >> v[i][j];
    rep(i,n)rep(j,n-1) v[i][j]--;

    queue<ll> que;
    Vl whe(n,0);
    rep(i,n) que.push(i);
    ll ans=0;
    while(!que.empty()){
        ll x=que.front();
        que.pop();
        if(whe[x]==n-1) continue;
        ll oponent=v[x][whe[x]];
        if(whe[oponent]==n-1) continue;
        if(v[oponent][whe[oponent]]==x){
            ll day=0;
            if(whe[x]!=0) chmax(day,dist[x][whe[x]-1]);
            if(whe[oponent]!=0) chmax(day,dist[oponent][whe[oponent]-1]);
            dist[x][whe[x]]=day+1;
            dist[oponent][whe[oponent]]=day+1;
            whe[x]++;
            whe[oponent]++;
            chmax(ans,day+1);
            if(whe[x]!=n-1) que.push(x);
            if(whe[oponent]!=n-1) que.push(oponent);
        }
        //cout << x << " " << oponent << endl;
    }
    rep(i,n) if(dist[i][n-2]==-1) ans=-1;
    cout << ans << endl;
}