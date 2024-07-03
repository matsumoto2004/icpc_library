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
    ll nn,m;
    cin >> nn >> m;
    ll n=min(nn,(ll)5e5);
    VVl pawn(2*n+1);
    VVl can(2*n+1);
    Vl ok(2*n+1,0);
    pawn[n].PB(0);
    can[n].PB(0);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        y-=(nn-n);
        if(y<0||y>2*n) continue;
        pawn[y].PB(x);
        can[y].PB(0);
    }
    rep(i,2*n+1){
        sort(all(pawn[i]));
        pawn[i].PB(inf);
    }

    queue<pair<ll,ll>> que;
    que.push({n,0}); 
    while(!que.empty()){
        
        auto p=que.front();
        que.pop();
        ll x=p.F,y=p.S;
        if(can[x][y]==1) continue;
        can[x][y]=1;
        //cout << x << y << endl;
        if(pawn[x][y+1]==inf) ok[x]=1;

        ll sita=pawn[x][y]+1,ue=pawn[x][y+1];
        chmin(ue,2*nn+1);
        if(x!=0){
            ll left=lower_bound(all(pawn[x-1]),sita)-pawn[x-1].begin();
            ll right=lower_bound(all(pawn[x-1]),ue+1)-pawn[x-1].begin();
            for(int i=left;i<right;i++) que.push({x-1,i});
        }
        if(x!=2*n){
            ll left=lower_bound(all(pawn[x+1]),sita)-pawn[x+1].begin();
            ll right=lower_bound(all(pawn[x+1]),ue+1)-pawn[x+1].begin();
            for(int i=left;i<right;i++) que.push({x+1,i});
        }
    }
    ll ans=0;
    rep(i,2*n+1) ans+=ok[i];
    cout << ans << endl;

}