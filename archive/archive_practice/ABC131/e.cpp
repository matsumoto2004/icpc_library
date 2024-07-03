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
    if(k>(n-1)*(n-2)/2){
        cout << -1 << endl;
        return 0;
    }
    vector<Pl> ans;
    rep(i,n-1){
        ans.push_back({0,i+1});
    }
    ll x=1,y=2;
    rep(i,(n-1)*(n-2)/2-k){
        ans.push_back({x,y});
        if(y!=n-1) y++;
        else{
            x++;
            y=x+1;
        }
    }
    cout << ans.size() << endl;
    for(auto p:ans) cout << p.first+1 << " " << p.second+1 << endl;
}