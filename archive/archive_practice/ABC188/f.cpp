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

ll x,y;
ll ans=inf;

int main(){    
    cin >> x >> y;

    priority_queue<ll> pq;
    pq.push(y);

    map<ll,ll> dp,seen;

    while(!pq.empty()){
        ll now=pq.top();
        pq.pop();
        chmin(ans,dp[now]+abs(now-x));
        if(now%2==0){
            ll to=now/2;
            if(seen[to]) chmin(dp[to],dp[now]+1);
            else{
                dp[to]=dp[now]+1;
                seen[to]=1;
                pq.push(to);
            }
        }
        if(now%2==1){
            ll to=(now-1)/2;
            if(to<0) continue;
            if(seen[to]) chmin(dp[to],dp[now]+2);
            else{
                dp[to]=dp[now]+2;
                seen[to]=1;
                pq.push(to);
            }
        }
        if(now%2==1){
            ll to=(now+1)/2;
            if(seen[to]) chmin(dp[to],dp[now]+2);
            else{
                dp[to]=dp[now]+2;
                seen[to]=1;
                pq.push(to);
            }
        }
    }

    cout << ans << endl;
}