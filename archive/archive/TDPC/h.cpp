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

#define int long long

int dp[20005][105][2];
int newdp[20005][105][2];

signed main(){
    int n,w,c;
    cin >> n >> w >> c;
    vector<tuple<int,int,int>> v(n);
    rep(i,n){
        int x,y,z;
        cin >> x >> y >> z;
        //z--;
        v[i]={z,x,y};
    }
    sort(all(v));
    int nowc=-1;
    rep(j,w+1)rep(ii,c+1)rep(jj,2) newdp[j][ii][jj]=-inf;
    dp[0][0][0]=0;
    
    rep(i,n){
        auto [z,x,y]=v[i];

        rep(j,w+1)rep(ii,c+1)rep(jj,2) newdp[j][ii][jj]=-inf;
        rep(j,w+1)rep(ii,c+1)rep(jj,2){
            //選ばない
            if(z==nowc&&jj==1) chmax(newdp[j][ii][1],dp[j][ii][jj]);
            else chmax(newdp[j][ii][0],dp[j][ii][jj]);
            
            if(j+x>w) continue;

            //選ぶ
            if(z==nowc&&jj==1){
                chmax(newdp[j+x][ii][1],dp[j][ii][jj]+y);
            }
            else{
                chmax(newdp[j+x][ii+1][1],dp[j][ii][jj]+y);
            }
        }
        swap(dp,newdp);
        nowc=z;
    }
    int ans=0;
    rep(j,w+1)rep(ii,c+1)rep(jj,2) chmax(ans,dp[j][ii][jj]);
    cout << ans << endl;
}