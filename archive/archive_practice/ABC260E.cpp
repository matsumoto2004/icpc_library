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
    ll n,m;
    cin >> n >> m;
    Vl va(n),vb(n);
    rep(i,n) cin >> va[i] >> vb[i];
    Vl atob(m,-1);
    ll rightmin=-1;
    ll leftmax=inf;
    rep(i,n){
        va[i]--;
        vb[i]--;
        if(va[i]>vb[i]) swap(va[i],vb[i]);
        chmax(rightmin,va[i]);
        chmin(leftmax,vb[i]);
        chmax(atob[va[i]],vb[i]);
    }
    Vl ans(m+5,0);
    int right=rightmin;
    rep(left,m){
        if(left!=0) chmax(right,(int)atob[left-1]);
        if(left<=leftmax){
        ans[right-left+1]++;
        ans[m-left+1]--;
        }
        //cout << right-left+1 << m-left+1 << endl;
    }

    rep(i,m+1) ans[i+1]+=ans[i];
    rrep(i,1,m+1) cout << ans[i] << " ";
    cout << endl;

}