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
    ll q;
    cin >> q;
    multiset<ll> st;
    rep(query,q){
        ll type;
        cin >> type;
        if(type==1){
            ll x;cin >> x;
            st.insert(x);
        }
        if(type==3){
            ll x,k;
            cin >> x >> k;
            auto it=st.lower_bound(x);
            ll ok=1;
            rep(i,k-1){
                if(it==st.end()){
                    ok=0;
                    break;
                }
                it++;
            }
            if(ok&&it!=st.end()) cout << *it << endl;
            else cout << -1 << endl;
        }
        if(type==2){
            ll x,k;
            cin >> x >> k;
            auto it=st.upper_bound(x);
            ll ok=1;
            rep(i,k){
                if(it==st.begin()){

                    ok=0;
                    break;
                }
                it--;
            }
            if(ok) cout << *it << endl;
            else cout << -1 << endl;
        }
    }
}