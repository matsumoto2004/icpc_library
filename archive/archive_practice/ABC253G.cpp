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
    ll n,l,r;
    cin >> n >> l >> r;
    pair<ll,ll> pl,pr;
    ll cnt=0;
    Vl v(n);
    rep(i,n) v[i]=i;
    rep(i,n){
        ll kind=n-i-1;
        if(l>cnt&&l<=cnt+kind){
            pl={i,i+l-cnt};
        }
        if(r>cnt&&r<=cnt+kind){
            pr={i,i+r-cnt};
        }
        cnt+=kind;
    }
    if(pl.F==pr.F){
        for(int i=pl.S;i<=pr.S;i++){
            swap(v[pl.F],v[i]);
        }
        rep(i,n) cout << v[i] + 1 << " ";
        cout << endl;
        return 0;
    }
    for(int j=pl.S;j<n;j++){
        swap(v[pl.F],v[j]);
    }
    Vl newv;
    rep(i,pl.F+1){
        newv.PB(v[i]);
    }
    rep(i,pr.F-pl.F-1){
        newv.PB(v[n-i-1]);
    }
    rep(i,n-pr.F){
        newv.PB(v[pl.F+1+i]);
    }
    for(int j=pr.F+1;j<=pr.S;j++){
        swap(newv[pr.F],newv[j]);
    }
    rep(i,n) cout << newv[i]+1 << " ";
    cout << endl;

}