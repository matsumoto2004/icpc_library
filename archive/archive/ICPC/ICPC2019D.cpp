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

void show(VVl v){
    for(auto vv:v){
        for(auto x:vv){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    while(1){
        ll n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;

        Vl va(n),vb(n);
        rep(i,n) cin >> va[i];
        rep(i,n) cin >> vb[i];
        Vl dist(n+1,0);//1indexed
        rep(i,n){
            ll x=va[i],y=vb[i];
            if(y>=x) dist[i+1]=y-x;
            else dist[i+1]=(m-x)+y;
        }

        VVl dp(n+5,Vl(n+5,inf));//1indexed
        Vl table(n+5);
        Vl tablemin(n+5,inf);
        Vl tablemin2(n+5,inf);
        dp[0][0]=0;
        rep(i,n){
            rep(ii,n) table[ii]=dp[i][ii]-m*ii;
            tablemin[0]=table[0];
            rrep(ii,1,n) tablemin[ii]=min(table[ii],tablemin[ii-1]);
            rrepd(ii,0,n) tablemin2[ii]=min(dp[i][ii],tablemin2[ii+1]);
            rep(j,n){
                if(dist[i+1]>dist[i]){
                    chmin(dp[i+1][j],tablemin[j]+dist[i+1]-dist[i]+m*j);
                    chmin(dp[i+1][j],tablemin2[j+1]);
                }
                if(dist[i+1]<=dist[i]){
                    if(j!=0)chmin(dp[i+1][j],tablemin[j-1]+dist[i+1]-dist[i]+m*j);
                    chmin(dp[i+1][j],tablemin2[j]);
                }
            }
        }
        ll ans=inf;
        rep(i,n) chmin(ans,dp[n][i]);
        cout << ans << endl;


    }
}