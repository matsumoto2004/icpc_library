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
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    ll cnt1=0,cnt2=0;
    rep(i,n){
        for(char c:v[i]){
            if(c=='(') cnt1++;
            else cnt2++;
        }
    }
    if(cnt1!=cnt2){
        cout << "No" << endl;
        return 0;
    }

    Vl sum(n,0),mn(n,0);
    rep(i,n){
        ll now=0;
        for(char c:v[i]){
            if(c=='(') now++;
            else now--;
            chmin(mn[i],now);
        }
        sum[i]=now;
    }
    vector<pair<ll,ll>> pls,mns;
    rep(i,n){
        if(sum[i]>=0) pls.emplace_back(mn[i],sum[i]);
        else mns.emplace_back(mn[i]-sum[i],sum[i]);
    }
    sort(all(pls));
    reverse(all(pls));

    ll now=0;
    for(auto p:pls){
        if(now+p.F<0){
            cout << "No" << endl;
            return 0;
        }
        now+=p.S;
    }
    
    //これはおかしい希ガス
    sort(all(mns));
    for(auto p:mns){
        if(now+p.F+p.S<0){
            cout << "No" << endl;
            return 0;
        }
        now+=p.S;
    }

    cout << "Yes" << endl;

}