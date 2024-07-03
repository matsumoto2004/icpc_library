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

ll majority(Vl v){
    ll n=v.size();
    ll count=0,candidate=-1;
    rep(i,n){
        if(count==0){
            candidate=v[i];
            count=1;
        }
        else if(v[i]==candidate) count++;
        else count--;
    }
    ll ret=0;
    rep(i,n) if(v[i]==candidate) ret++;
    return ret;
}

int main(){
    ll n;
    cin >> n;
    Vl v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    set<ll> st;
    rep(i,n-1) st.insert(v[i+1]-v[i]);
    rep(i,n-2) st.insert(v[i+2]-v[i]);
    set<ll> st2;
    for(auto x:st){
        ll xx=x;
        for(ll i=2;i*i<x;i++){
            if(xx%i==0&&i>=5000) st2.insert(i);
            while(xx%i==0) xx/=i;
            
        }
        if(xx!=1) st2.insert(xx);
        
    }
    rrep(i,3,5000){
        ll ii=i;
        ll ok=1;
        rrep(j,2,i){
            if(ii%j==0) ok=0;
        }
        if(ok) st2.insert(i);
    }
    for(auto x:st2){
        if(x<=2) continue;
        Vl v2=v;
        rep(i,n) v2[i]%=x;
        if(majority(v2)*2>n){
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}