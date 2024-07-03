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
    ll n,m;
    cin >> n >> m;
    VVl graph(n,Vl(n,0));
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    Vl is(1<<n,0);
    is[0]=1;
    rrep(bit,1,1<<n){
        rep(i,n){
            if(((bit>>i)&1)==0)continue;
            int pastbit=bit^(1<<i);
            ll ok=1;
            if(is[pastbit]==0) ok=0;
            rep(j,n){
                if(((pastbit>>j)&1)&&graph[i][j]==0) ok=0;
            }
            is[bit]=ok;
            break;
        }
    }

    Vl dp(1<<n,inf);
    dp[0]=0;
    rrep(bit,1,1<<n){
        if(is[bit]==1) dp[bit]=1;
        for(int bit1=bit;bit1>0;bit1=(bit1-1)&bit){
            int bit2=bit^bit1;
            chmin(dp[bit],dp[bit1]+dp[bit2]);
        }
        //cout << dp[bit] << endl;

    }
    cout << dp[(1<<n)-1] << endl;


}