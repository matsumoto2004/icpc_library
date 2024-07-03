#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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

long double dp[205][105][105];
long double newdp[205][105][105];

int main(){
    ll n,d;
    cin >> n >> d;
    ll two=0,three=0,five=0;
    while(d%2==0){
        two++;
        d/=2;
    }
    while(d%3==0){
        three++;
        d/=3;
    }
    while(d%5==0){
        five++;
        d/=5;
    }
    if(d!=1){
        cout << 0 << endl;
        return 0;
    }
    dp[0][0][0]=1;

    //cout << "ok" << endl;

    rep(trial,n){
        rep(i,two+1)rep(j,three+1)rep(k,five+1){
            newdp[i][j][k]=0;
        }
        rep(i,two+1)rep(j,three+1)rep(k,five+1){
            long double now=dp[i][j][k];
            now/=6;
            newdp[i][j][k]+=now;
            newdp[min(i+1,two)][j][k]+=now;
            newdp[i][min(j+1,three)][k]+=now;
            newdp[min(i+2,two)][j][k]+=now;
            newdp[i][j][min(k+1,five)]+=now;
            newdp[min(i+1,two)][min(j+1,three)][k]+=now;
            //cout << i << j << k << endl;
        }
        swap(dp,newdp);
    }
    cout << fixed << setprecision(12);
    long double ans=0;
    rrep(i,two,71)rrep(j,three,51)rrep(k,five,31){
        ans+=dp[i][j][k];
    }
    cout << ans<< endl;
}