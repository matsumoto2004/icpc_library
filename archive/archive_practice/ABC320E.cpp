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
    //次のそうめん+次の戻ってくる時間　並んでいる人 priqueで管理
    ll n,m;
    cin >> n >> m;
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq1;
    priority_queue<ll,vector<ll>,greater<ll>> pq2;
    rep(i,n) pq2.push(i);
    rep(i,m){
        ll t,w,s;
        cin >> t >> w >> s;
        pq1.push({t,w,s});
    }
    Vl ans(n);

    while(!pq1.empty()){
        auto [t,w,s]=pq1.top();
        pq1.pop();
        if(w==-1){
            pq2.push(s);
        }
        else{
            if(!pq2.empty()){
                ll x=pq2.top();
                pq2.pop();
                ans[x]+=w;
                pq1.push({t+s,-1,x});
            }
        }
    }
    rep(i,n) cout << ans[i] << endl;
}
