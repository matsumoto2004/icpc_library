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

ll h,w;

ll big=1e9;



struct Mypair{
    ll x;
    ll y;

    Mypair(ll xx=0,ll yy=0):x(xx),y(yy){}

    

};

ll num(Mypair p1){
    ll x=p1.x,y=p1.y;
        ll ret;
        if(x==0){
            ret=y;
        }
        else if(y==h){
            ret=big+x;
        }
        else if(x==w){
            ret=2*big+(h-y);
        }
        else if(y==0){
            ret=3*big+(w-x);
        }
        return ret;
}

bool operator<(const Mypair& p1,const Mypair& p2){
    return num(p1)<num(p2);
}



int main(){
    ll n;
    cin >> w >> h >> n;
    vector<pair<Mypair,ll>> v(2*n);
    rep(i,2*n){
        ll x,y,c;
        cin >> x >> y >> c;
        v[i]={{x,y},c};
    }
    sort(all(v));
    deque<ll> dq;
    rep(i,2*n){
        ll now=v[i].S;
        //cout << now << endl;
        if(dq.empty()){
            dq.push_front(now);
        }
        else{
            if(now==dq.front()) dq.pop_front();
            else dq.push_front(now);
        }
    }
    if(dq.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}