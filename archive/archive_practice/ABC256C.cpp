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
    Vl vh(3),vw(3);
    rep(i,3) cin >> vh[i];
    rep(i,3) cin >> vw[i];
    VVl v(3,Vl(3,0));
    ll ans=0;
    rrep(i0,1,31)rrep(i1,1,31)rrep(i2,1,31)rrep(i3,1,31){
        v[0][0]=i0;
        v[0][1]=i1;
        v[1][0]=i2;
        v[1][1]=i3;
        rep(i,3){
            v[2][i]=vh[i]-v[0][i]-v[1][i];
        }
        rep(i,3){
            v[i][2]=vw[i]-v[i][0]-v[i][1];
        }
        if(v[0][2]+v[1][2]+v[2][2]!=vh[2]) continue;
        ll ok=1;
        rep(i,3)rep(j,3) if(v[i][j]<=0) ok=0;
        if(ok) ans++;
    }
    cout << ans << endl;
}