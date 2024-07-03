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
    Vl v(n);
    rep(i,n) cin >> v[i];
    ll pos=0,zero=0,neg=0;
    Vl vpos,vneg;
    rep(i,n){
        if(v[i]>0){
            pos++;
            vpos.push_back(v[i]);
        }
        if(v[i]==0) zero++;
        if(v[i]<0){
            neg++;
            vneg.push_back(-v[i]);
        }
    }
    sort(all(vpos));
    sort(all(vneg));
    if(k<=pos*neg){
        ll ok=0,ng=inf;
        while(ng-ok>1){
            ll mid=(ok+ng)/2;
            ll cnt=0;
            for(auto x:vneg){
                ll mx=mid/x;
                cnt+=upper_bound(all(vpos),mx)-vpos.begin();
            }
            if(cnt>=pos*neg-k+1) ng=mid;
            else ok=mid;
        }
        cout << -ok-1 << endl;
    }
    else if(k<=pos*neg+zero*(n-1)-zero*(zero-1)/2){
        cout << 0 << endl;
    }
    else{
        ll ok=0,ng=inf;
        while(ng-ok>1){
            ll mid=(ok+ng)/2;
            ll cnt=0;
            rep(i,vneg.size()){
                ll mx=mid/vneg[i];
                ll whe=upper_bound(all(vneg),mx)-vneg.begin();
                if(whe<=i) continue;
                cnt+=whe-i-1;
            }
            rep(i,vpos.size()){
                ll mx=mid/vpos[i];
                ll whe=upper_bound(all(vpos),mx)-vpos.begin();
                if(whe<=i) continue;
                cnt+=whe-i-1;
            }
            if(cnt>=k-pos*neg-zero*(n-1)+zero*(zero-1)/2) ng=mid;
            else ok=mid;
        }
        cout << ok+1 << endl;
    }
}