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
    ll n;
    cin >> n;
    Vl yaku;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            yaku.push_back(i);
            if(i*i!=n){
                yaku.push_back(n/i);
            }
        }
    }

    ll nn=n-1;
    ll ans=0;
    for(ll i=1;i*i<=nn;i++){
        if(nn%i==0){
            if(i!=1) ans++;
            if(i*i!=nn) ans++;
        }
    }

    for(auto x:yaku){
        if(x==1) continue;
        ll now=n;
        while(now%x==0){
            now/=x;
        }
        if((now-1)%x==0) ans++;
    }
    cout << ans << endl;
}