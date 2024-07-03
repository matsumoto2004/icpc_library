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
    Vl cnt(n);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    VVl to(n);
    Vl ans;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        cnt[b]++;
        to[a].PB(b);
    }
    rep(i,n) if(cnt[i]==0) pq.push(i);
    while(!pq.empty()){
        ll x=pq.top();
        pq.pop();
        ans.PB(x);
        for(auto y:to[x]){
            cnt[y]--;
            if(cnt[y]==0) pq.push(y);
        }
    }
    if(ans.size()!=n){
        cout << -1 << endl;
    }
    else{
        rep(i,n) cout << ans[i]+1 << " ";
        cout << endl;
    }

}