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
    Vl v(n);
    rep(i,n) cin >> v[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq,pq2;//下になる候補，上になった数字
    pq.push(inf);
    pq2.push(inf);
    ll ans=0;
    rep(i,n){
        ll x=v[i];
        ll y1=pq.top(),y2=pq2.top();
        if(x-y1<=0&&x-y2<=0) pq.push(x);
        else{
            if(x-y1>=x-y2){
                ans+=x-y1;
                pq.pop();
                pq2.push(x);
            }
            else{
                ans+=x-y2;
                pq2.pop();
                pq.push(y2);
                pq2.push(x);
            }
        }

        
    }
    cout << ans << endl;
}