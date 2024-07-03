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
    ll n,x,y;
    cin >> n >> x >> y;
    Vl dp(1<<n,inf);
    Vl va(n),vb(n);
    rep(i,n) cin >> va[i];
    rep(i,n) cin >> vb[i];
    dp[0]=0;
    rep(bit,(1<<n)){
        if(bit==0)continue;
        ll whe=__builtin_popcountll(bit)-1;
        rep(j,n){
            if(((bit>>j)&1)==0) continue;
            int past=bit^(1<<j);
            ll pos=j;
            rrep(ii,j+1,n) if((past>>ii)&1) pos++;
            ll cost=dp[past]+abs(pos-whe)*y+abs(va[j]-vb[whe])*x;
            chmin(dp[bit],cost);
            //cout << bit << j << pos << " " << cost << endl;
        }
    }
    cout << dp[(1<<n)-1] << endl;
    
}