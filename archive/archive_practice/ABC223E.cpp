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

bool solve(ll x,ll y,ll a,ll b,ll c){
    ll need=a/x;
    if(a%x!=0) need++;
    ll xx=x,yy=y-need;
    if(yy<=0) return false;
    ll need2=(b/xx+(b%xx!=0)+c/xx+(c%xx!=0));
    if(need2<=yy) return true;
    ll need3=(b/yy+(b%yy!=0)+c/yy+(c%yy!=0));
    if(need3<=xx) return true;
    return false;
}

int main(){
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    if(solve(x,y,a,b,c)||solve(x,y,b,c,a)||solve(x,y,c,a,b)||solve(y,x,a,b,c)||solve(y,x,b,c,a)||solve(y,x,c,a,b)){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}