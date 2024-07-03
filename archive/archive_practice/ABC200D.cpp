#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rrep(i, k, n) for (long long i = k; i < (long long)(n); i++)
#define repd(i, n) for (long long i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (long long i = n-1; i >= (long long)(k); i--)
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
#define btcnt(n) __builtin_popcountll(n)
const ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

int main(){
    ll n;
    cin >> n;
    Vl v(n);
    rep(i,n) cin >> v[i];

    Vl memo(205,-1);

    rrep(bit,1,(1<<min(n,(ll)30))){
        ll x=0;
        rep(i,min(n,(ll)30)){
            if((bit>>i)&1) x+=v[i];
        }
        x%=200;
        if(memo[x]!=-1){
            cout << "Yes" << endl;
            cout << btcnt(memo[x]) << " ";
            rep(i,min(n,(ll)30)){
                if((memo[x]>>i)&1) cout << i+1 << " ";
            }
            cout << endl;
            cout << btcnt(bit) << " ";
            rep(i,min(n,(ll)30)){
                if((bit>>i)&1) cout << i+1 << " ";
            }
            cout << endl;
            return 0;
        }
        else memo[x]=bit;
    }
    cout << "No" << endl;
}