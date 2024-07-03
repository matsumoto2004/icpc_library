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
 
int main() {
    ll t;
    cin >> t;
    rep(query,t){
        ll n,m;
        cin >> n >> m;
        ll k;
        cin >> k;
        string s;
        cin >> s;
        VVl v(n,Vl(m,-1));
        ll x=0,y=0;
        v[x][y]=0;
        rep(i,s.size()){
            if(s[i]=='R') y++;
            else x++;
            v[x][y]=0;

        }
        rep(i,n)rep(j,m){
            if(i>0&&j<m-1){
                if(v[i-1][j]==0&&v[i][j+1]==0) v[i][j]=1;
            }
            if(i<n-1&&j>0){
                if(v[i][j-1]==0&&v[i+1][j]==0) v[i][j]=1;
            }
        }
        VVl dp(n,Vl(m,0));
        rep(i,n)rep(j,m){
            ll now=0;
            if(i!=0) chmax(now,dp[i-1][j]);
            if(j!=0) chmax(now,dp[i][j-1]);
            if(v[i][j]==1) now++;
            dp[i][j]=now;
        }
        if(dp[n-1][m-1]<=k) yn;
    }
    

}