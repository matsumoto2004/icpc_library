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
    ll now=n-k;
    ll nowvalue=inf;
    rrep(i,n-k,n) chmin(nowvalue,v[i]);
    if(now!=0){
        while(v[now-1]<nowvalue){
            now--;
            nowvalue=v[now];
            if(now==0) break;
        }
    }
    ll mx=1;
    ll now2=1;
    rrep(i,1,n){
        if(v[i]>v[i-1]) now2++;
        else now2=1;
        chmax(mx,now2);
        if(i==n-k) chmin(now,n-k-now2+1);
    }
    if(mx<k) sort(v.begin()+now,v.begin()+now+k);
    rep(i,n) cout << v[i] << " ";
    cout << endl;
    //cout << mx << endl;//////
}