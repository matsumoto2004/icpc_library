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
    ll h,w;
    cin >> h >> w;
    vector<string> vs(h);
    rep(i,h) cin >> vs[i];
    VVl v(h,Vl(w,0));
    rep(i,h)rep(j,w){
        if(vs[i][j]=='+') v[i][j]=1;
        else v[i][j]=-1;
    }
    rep(i,h)rep(j,w){
        if((i+j)%2==0) v[i][j]=-v[i][j];
    }

    VVl dp(h+5,Vl(w+5,0));
    rrep(sum,1,h+w-1)rep(i,h){
        int j=sum-i;
        if(j>=w) continue;
        if(j<0) continue;
        if(sum%2==1){
            //先手
            ll ret=inf;
            if(i>0){
                chmin(ret,dp[i-1][j]+v[i][j]);
            }
            if(j>0){
                chmin(ret,dp[i][j-1]+v[i][j]);
            }
            dp[i][j]=ret;
        }
        else{
            //後手
            ll ret=-inf;
            if(i>0){
                chmax(ret,dp[i-1][j]+v[i][j]);
            }
            if(j>0){
                chmax(ret,dp[i][j-1]+v[i][j]);
            }
            dp[i][j]=ret;
        }
    }
    if(dp[h-1][w-1]>0){
        cout << "Takahashi" << endl;
    }
    if(dp[h-1][w-1]==0){
        cout << "Draw" << endl;
    }
    if(dp[h-1][w-1]<0){
        cout << "Aoki" << endl;
    }

}