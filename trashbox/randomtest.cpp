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
    vector<string> v(n),v2(n);
    Vl at(n);
    rep(i,n) at[i]=i;
    std::random_device get_rand_dev;
    std::mt19937 get_rand_mt( get_rand_dev() ); // seedに乱数を指定
    std::shuffle( at.begin(), at.end(), get_rand_mt );
    rep(i,n){

        string s;
        cin >> s;
        v[i]=s;
    }
    cout << "wanle" << endl;
    ll now=0;
    rep(i,17){
        string s;
        ll x;
        cin >> s >> x;
        rep(j,x){
            v2[now]=s;
            now++;
        }
    }
    rep(i,n){
        cout << v[at[i]] << " ";
        if(i%8==7) cout << endl;
    }

    rep(i,n){
        cout << v2[at[i]] << " ";
        if(i%8==7) cout << endl;
    }
}