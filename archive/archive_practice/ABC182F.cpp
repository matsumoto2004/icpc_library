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
    ll n,x;
    cin >> n >> x;
    Vl v(n);
    rep(i,n) cin >> v[i];
    reverse(all(v));

    Vl dp(n+5,0),dp2(n+5,0);
    dp[0]=1;
    dp2[0]=1;
    Vl ue(n),sita(n);

    rep(i,n){
        sita[i]=(x/v[i])*v[i];
        if(sita[i]==x) ue[i]=x;
        else ue[i]=sita[i]+v[i];
    }

    if(x%v[0]==0){
        cout << 1 << endl;
        return 0;
    }

    rrep(i,1,n){
        if(abs(ue[i]-ue[i-1])<v[i-1]) dp[i]+=dp[i-1];
        if(abs(ue[i]-sita[i-1])<v[i-1]) dp[i]+=dp2[i-1];
        if(abs(sita[i]-ue[i-1])<v[i-1]) dp2[i]+=dp[i-1];
        if(abs(sita[i]-sita[i-1])<v[i-1]) dp2[i]+=dp2[i-1];
        if(x%v[i]==0){
            cout << dp[i] << endl;
            return 0;
        }
    }

}