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
    ll h,w,k;
    cin >> h >> w >> k;
    vector<string> v(h);
    rep(i,h) cin >> v[i];

    ll ans=inf;
    rep(bit,(1<<(h-1))){
        Vl group(h,0);
        rep(i,h-1) group[i+1]=group[i]+((bit>>i)&1);
        Vl cnt(h,0);
        ll now=__builtin_popcount(bit);
        rep(j,w){
            rep(i,h){
                cnt[group[i]]+=v[i][j]-'0';            
            }
            if(*max_element(all(cnt))>k){
                now++;
                rep(i,h) cnt[i]=0;
                rep(i,h) cnt[group[i]]+=v[i][j]-'0';   
                if(*max_element(all(cnt))>k){
                    now=inf;
                    j=w;
                }    
            }
            
            //cout << bit << j << now << endl;
            //rep(i,h) cout << cnt[i] << " ";
            //cout << endl;

        }
        chmin(ans,now);
    }
    cout << ans << endl;
}