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

ll dp[10005][2];

int main(){
    ll n,k;
    cin >> n >> k;
    Vl v(k);
    rep(i,k) cin >> v[i];
    dp[0][0]=0;
    dp[0][1]=0;
    rrep(i,1,n+1){
        dp[i][0]=0;
        dp[i][1]=inf;
        //先手
        for(auto x:v){
            if(i-x<0) continue;
            chmax(dp[i][0],dp[i-x][1]+x);
        }
        //後手
        for(auto x:v){
            if(i-x<0) continue;
            chmin(dp[i][1],dp[i-x][0]);

        }

    }
    cout << dp[n][0] << endl;
}