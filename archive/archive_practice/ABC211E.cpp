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

ll ans=0;
ll n,k;
set<vector<string>> st;

Vl dx={1,0,-1,0};
Vl dy={0,1,0,-1};

void dfs(vector<string> vs,ll rest){
    auto it=st.find(vs);
    if(it!=st.end()){
        return;
    }
    st.insert(vs);
    if(rest==0){
        ans++;
        return;
    }
    rep(i,n)rep(j,n){
        if(vs[i][j]!='.') continue;
        ll ok=0;
        rep(k,4){
            ll tox=i+dx[k],toy=j+dy[k];
            if(tox<0||tox>=n||toy<0||toy>=n) continue;
            if(vs[tox][toy]=='@') ok=1;
        }
        if(ok){
            vs[i][j]='@';
            dfs(vs,rest-1);
            vs[i][j]='.';
        }
    }
    return;

}

int main(){

    cin >> n >> k;
    vector<string> vs(n);
    rep(i,n) cin >> vs[i];

    rep(i,n)rep(j,n){
        if(vs[i][j]=='#') continue;
        vs[i][j]='@';
        dfs(vs,k-1);
        vs[i][j]='.';
    }
    cout << ans << endl;
}