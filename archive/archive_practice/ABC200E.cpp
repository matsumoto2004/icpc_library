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
    //0~n-1で考える
    ll n,k;
    cin >> n >> k;
    Vl dp(3*n-2,0);
    Vl rui(3*n-2,0);
    Vl num(3*n-2,0);
    rep(i,n){
        dp[i]=i+1;
        dp[2*n-2-i]=i+1;
    }
    rep(i,2*n-1){
        rui[i+1]=rui[i]+dp[i];
    }
    rep(i,3*n-2){
        ll ue=i;
        ll sita=i-n+1;
        if(ue>=2*n-2) ue=2*n-2;
        if(sita<=0) sita=0;
        num[i]=rui[ue+1]-rui[sita];
    }
    //rep(i,3*n-2) cout << num[i] << endl;

    ll sum=0;
    while(k-num[sum]>0){
        k-=num[sum];
        sum++;
    }
    //cout << sum << " " << k << endl;
    //和がsumの中でk番目のもの
    rep(i,n){
        ll left=sum-i;
        ll sita=left-(n-1),ue=left;
        if(sita<0) sita=0;
        if(ue>n-1) ue=n-1;
        ll kosuu=ue-sita+1;
        //cout << kosuu << endl;
        if(k>kosuu)k-=max((ll)0,kosuu);
        else{
            cout << i+1 << " " << sita+k-1+1 << " " << sum-(sita+k-1)-i+1 << endl;
            return 0;
        }
    }



}