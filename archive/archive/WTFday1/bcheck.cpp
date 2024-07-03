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

ll n;

void dfs(Vl v,vector<Pl>operate,ll p=0){
    ll ok=1;
    rep(i,n) if(v[i]!=i)ok=0;
    if(ok){
        cout << p << endl;
        for(auto [x,y]:operate){
            cout << x << " " << y << endl;
        }
        return;
    }
    if(p==n-1) return;
    Pl past=operate.back();
    rep(i,n)rrep(j,i,n){
        Vl vret=v;
        vector<Pl> operateret=operate;
        if(j>past.F&&past.S>i) continue;
        swap(vret[i],vret[j]);
        operateret.emplace_back(i,j);
        dfs(vret,operateret,p+1);
    }
    return;
}

int main(){
    cin >> n;
    Vl v(n);
    rep(i,n) cin >> v[i];//0-indexed
    dfs(v,{{0,0}});
    
}