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
    ll bsum=0;
    priority_queue<ll,vector<ll>,greater<ll>> ue;
    priority_queue<ll> sita;
    ll uesum=0,sitasum=0;
    rep(qi,q){
        ll type;
        cin >> type;
        if(qi==0){
            ll a,b;
            cin >> a >> b;
            sita.push(a);
            sitasum+=a;
            bsum+=b;
        }
        else if(type==1){
            ll a,b;
            cin >> a >> b;
            if(a>=sita.top()){
                ue.push(a);
                uesum+=a;
            }
            else{
                sita.push(a);
                sitasum+=a;
            }
            if(ue.size()>sita.size()){
                ll x=ue.top();
                ue.pop();
                uesum-=x;
                sita.push(x);
                sitasum+=x;
            }
            if(sita.size()>ue.size()+1){
                ll x=sita.top();
                sita.pop();
                sitasum-=x;
                ue.push(x);
                uesum+=x;
            }
            bsum+=b;
        }
        else{
            ll x=sita.top();
            ll ans=bsum+uesum-x*ue.size()+x*sita.size()-sitasum;
            cout << x << " " << ans << endl;
        }
    }
}