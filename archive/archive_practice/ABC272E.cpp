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



ll mex(Vl v){
    sort(all(v));
    ll now=0;
    rep(i,v.size()){
        if(v[i]>now) return now;
        chmax(now,v[i]+1);
    }
    return now;
}

int main(){
    ll n,m;
    cin >> n >> m;
    Vl v(n);
    rep(i,n) cin >> v[i];
    VVl stock(m+5);
    rep(i,n){
        ll pls=i+1,x=v[i];
        ll sita=0,ue=0;
        if(v[i]<0){
            sita=(-v[i])/pls;
            if(-v[i]%pls!=0) sita++;
        }
        if(v[i]<=m){
            ue=(m-v[i])/pls;
            if((m-v[i])%pls!=0) ue++;
        }
        chmin(ue,m+1);
        rrep(j,sita,ue){
            stock[j].PB(x+pls*j);
        }

    }
    //cout << "ok" << endl;
    rrep(i,1,m+1){
        cout << mex(stock[i]) << endl;
    }
}