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
    ll n,k;
    cin >> n >> k;
    ll ans=0;
    Vl v(n);
    rep(i,n) cin >> v[i];
    Vl sum1(n,0),sum2(n,0);
    sum1[0]=v[0];
    rrep(i,1,n) sum1[i]=sum1[i-1]+v[i];
    sum2[n-1]=v[n-1];
    rrepd(i,1,n) sum1[i-1]=sum1[i]+v[i-1];
    
    rep(i,n+1)rep(j,n+1){
        if(i+j>n) continue;
        if(i+j>k) continue;
        ll sum=0;
        priority_queue<ll> pq;
        rep(ii,i){
            sum+=v[ii];
            if(v[ii]<0) pq.push(-v[ii]);
        }
        rep(jj,j){
            sum+=v[n-1-jj];
            if(v[n-1-jj]<0) pq.push(-v[n-1-jj]);
        }
        rep(ii,k-i-j){
            if(!pq.empty()){
                sum+=pq.top();
                pq.pop();
            }
        }
        chmax(ans,sum);
    }
    cout << ans << endl;
}