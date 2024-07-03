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
    string s;
    ll k;
    cin >> s >> k;
    ll n=s.size();
    Vl v;
    rep(i,n) if(s[i]=='Y') v.PB(i);
    ll ny=v.size();
    v.PB(inf);

    ll l=0,m=0,r=0;
    ll now=0;
    ll ans=0;
    while(r<ny){
        //l,rの更新
        if(now<=k){
            chmax(ans,r-l+1);
            r++;
            now+=v[r]-v[m]-(r-m);
        }
        else{
            now-=v[m]-v[l]-(m-l);
            l++;
        }
        //mの更新
        if(m<(l+r)/2){
            m++;
            now+=(v[m]-v[m-1]-1)*(m-l);
            now-=(v[m]-v[m-1]-1)*(r-m+1);
        }
        //cout << l << m << r << now << endl;
    }
    cout << ans << endl;
}