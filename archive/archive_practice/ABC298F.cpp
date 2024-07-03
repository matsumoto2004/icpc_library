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
    ll n;
    cin >> n;
    map<Pl,ll> mp;
    map<ll,ll> mph,mpw;
    rep(i,n){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        mp[make_pair(x,y)]+=z;
        mph[x]+=z;
        mpw[y]+=z;
    }
    vector<Pl> vh,vw;
    for(auto p:mph) vh.PB(make_pair(p.S,p.F));
    for(auto p:mpw) vw.PB(make_pair(p.S,p.F));
    sort(all(vh));
    reverse(all(vh));
    sort(all(vw));
    reverse(all(vw));

    priority_queue<tuple<ll,ll,ll>> pq;
    pq.push({vh[0].F+vw[0].F,0,0});
    ll ans=0;

    set<Pl> seen;
    while(!pq.empty()){
        auto[z,x,y]=pq.top();
        pq.pop();
        if(seen.find({x,y})!=seen.end()) continue;
        seen.insert({x,y});
        ll score=z-mp[make_pair(vh[x].S,vw[y].S)];
        chmax(ans,score);
        if(mp[make_pair(vh[x].S,vw[y].S)]==0){
            cout << ans << endl;
            return 0;
        }
        if(x!=vh.size()-1){
            pq.push({vh[x+1].F+vw[y].F,x+1,y});
        }
        if(y!=vw.size()-1){
            pq.push({vh[x].F+vw[y+1].F,x,y+1});
        }

    }
    cout << ans << endl;
}