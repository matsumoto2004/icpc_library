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
    ll a,b;
    cin >> a >> b; 
    Vl primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    VVl dp(b-a+1+5,Vl((1<<20)+5,0));
    Vl vbit(b-a+1,0);
    rep(i,b-a+1){
        ll bit=0;
        ll now=a+i;
        rep(i,20){
            if(now%primes[i]==0) bit^=(1<<i);
        }
        vbit[i]=bit;
    }

    dp[0][0]=1;
    rep(i,b-a+1)rep(j,(1<<20)){
        //選ぶ
        if((j&vbit[i])==0) dp[i+1][(j|vbit[i])]+=dp[i][j];
        //選ばない
        dp[i+1][j]+=dp[i][j];
    }
    ll ans=0;
    rep(j,(1<<20)) ans+=dp[b-a+1][j];

    cout << ans << endl;
}
