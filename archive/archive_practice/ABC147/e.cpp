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

ll cango[85][85][20005];

int main(){
    ll h,w;
    cin >> h >> w;
    VVl va(h,Vl(w)),vb(h,Vl(w));
    rep(i,h)rep(j,w) cin >> va[i][j];
    rep(i,h)rep(j,w) cin >> vb[i][j];
    VVl v(h,Vl(w));
    rep(i,h)rep(j,w) v[i][j]=va[i][j]-vb[i][j];
    cango[0][0][abs(v[0][0])]=1;
    rep(i,h)rep(j,w)rep(ii,10000){
        if(cango[i][j][ii]==0) continue;
        if(i!=h-1){
            cango[i+1][j][abs(ii+v[i+1][j])]=1;
            cango[i+1][j][abs(ii-v[i+1][j])]=1;
        }
        if(j!=w-1){
            cango[i][j+1][abs(ii+v[i][j+1])]=1;
            cango[i][j+1][abs(ii-v[i][j+1])]=1;

        }
    }
    ll ans=inf;
    rep(ii,10000) if(cango[h-1][w-1][ii]) chmin(ans,(ll)ii);
    cout << ans << endl;

}