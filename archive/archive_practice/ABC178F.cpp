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

ll tomod(ll x,ll md){
    return (x+md)%md;
}

int main(){
    ll n;
    cin >> n;
    Vl va(n),vb(n);
    rep(i,n) cin >> va[i];
    rep(i,n) va[i]--;
    rep(i,n) cin >> vb[i];
    rep(i,n) vb[i]--;
    Vl memoa1(n,inf),memoa2(n,-inf);
    Vl memob1(n,inf),memob2(n,-inf);
    rep(i,n){
        chmin(memoa1[va[i]],(ll)i);
        chmax(memoa2[va[i]],(ll)i);
        chmin(memob1[vb[i]],(ll)i);
        chmax(memob2[vb[i]],(ll)i);
    }
    Vl nglist(n+5,0);
    rep(i,n){
        if(memoa1[i]==inf||memob1[i]==inf) continue;
        ll cnt1=memoa2[i]-memoa1[i]+1;
        ll cnt2=memob2[i]-memob1[i]+1;
        if(cnt1+cnt2>n){
            cout << "No" << endl;
            return 0;
        }
        ll rot1=tomod(memoa1[i]-memob2[i],n);
        ll rot2=tomod(memoa2[i]-memob1[i],n);
        if(rot1<=rot2){
            nglist[rot1]++;
            nglist[rot2+1]--;
        }
        else{
            nglist[0]++;
            nglist[rot2+1]--;
            nglist[rot1]++;
            nglist[n]--;
        }

    }
    rep(i,n) nglist[i+1]+=nglist[i];
    ll rot=-1;
    rep(i,n){
        if(nglist[i]==0)rot=i;
    }
    Vl ans(n);
    rep(i,n) ans[(i+rot)%n]=vb[i];
    cout << "Yes" << endl;
    for(auto x:ans) cout << x+1 << " ";
    cout << endl;

}