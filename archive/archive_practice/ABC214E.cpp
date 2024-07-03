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

//追加クエリ，x以上，かつ要素に含まれない数の最小値

int main(){
    //実装気になる
    ll t;
    cin >> t;
    rep(query,t){
        ll n;
        cin >> n;
        Vl vl(n),vr(n);
        rep(i,n) cin >> vl[i] >> vr[i];
        vector<pair<ll,ll>> vp(n);
        rep(i,n) vp[i]={vl[i],vr[i]};
        sort(all(vp));
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        vp.emplace_back(inf,inf);
        ll x=1; 
        ll ans=1;
        rep(i,n+1){
            ll l=vp[i].F,r=vp[i].S;
            while(x<l&&(!pq.empty())){
                if(pq.top()<x){
                    ans=0;
                    
                }
                pq.pop();
                x++;
            }
            x=l;
            pq.push(r);
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}