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


struct Edge{
    ll to;
    ll id;
};

int main(){

    ll n,m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back({y,i});
    }

    vector<long double> expect(n,0);

    Vl candidate;
    //期待値求めつつ候補を列挙
    repd(i,n-1){
        long double mx=-inf;
        ll mxid=-1;
        long double sum=0;
        ll sz=graph[i].size();
        for(auto [to,id]:graph[i]){
            sum+=expect[to];
            if(expect[to]>mx){
                mxid=id;
                mx=expect[to];
            }
        }
        if(sz>1) candidate.push_back(mxid);
        expect[i]=sum/sz+1;

    }
    //全部調べる
    if(candidate.empty()){
        cout << fixed << setprecision(12);
        cout << expect[0] << endl;
        return 0;
    }

    long double ans=expect[0];

    for(auto delid:candidate){
        vector<long double> expect2(n,0);
        
        
        repd(i,n-1){
            ll sz=0;
            long double sum=0;
            for(auto [to,id]:graph[i]){
                if(id==delid) continue;
                sum+=expect2[to];
                sz++;
            }
            expect2[i]=sum/sz+1;
        }
        chmin(ans,expect2[0]);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;

}
