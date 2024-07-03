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
    ll n,x;
    cin >> n >> x;
    Vl v(n);
    rep(i,n) cin >> v[i];
    reverse(all(v));

    vector<set<ll>> dp1(n),dp2(n);
    Vl ue(n),sita(n);

    rep(i,n){
        sita[i]=(x/v[i])*v[i];
        if(sita[i]==x) ue[i]=x;
        else ue[i]=sita[i]+v[i];

    }

    dp1[0].insert(0);
    dp2[0].insert(0);
    if(x%v[0]==0){
        cout << 1 << endl;
        return 0;
    }

    rrep(i,1,n){
        //11
        for(auto x:dp1[i-1]){
            if(abs(ue[i-1]-ue[i])>=v[i-1]) continue;
            if(ue[i-1]>ue[i]){
                dp1[i].insert(x+ue[i-1]-ue[i]);
            }
            else dp1[i].insert(x);
        }
        //12
        for(auto x:dp1[i-1]){
            if(abs(ue[i-1]-sita[i])>=v[i-1]) continue;
            if(ue[i-1]>sita[i]){
                dp2[i].insert(x+ue[i-1]-sita[i]);
            }
            else dp2[i].insert(x);
        }
        //21
        for(auto x:dp2[i-1]){
            if(abs(sita[i-1]-ue[i])>=v[i-1]) continue;
            if(sita[i-1]>ue[i]){
                dp1[i].insert(x+sita[i-1]-ue[i]);
            }
            else dp1[i].insert(x);
        }

        //22
        for(auto x:dp2[i-1]){
            if(abs(sita[i-1]-sita[i])>=v[i-1]) continue;
            if(sita[i-1]>sita[i]){
                dp2[i].insert(x+sita[i-1]-sita[i]);
            }
            else dp2[i].insert(x);
        }
        /*
        cout << i << endl;
        for(auto x:dp1[i]) cout << x << " ";
        cout << endl;
        for(auto x:dp2[i]) cout << x << " ";
        cout << endl;
        */
    }

    set<ll> ans;
    for(auto x:dp1[n-1]) ans.insert(x);
    for(auto x:dp2[n-1]) ans.insert(x);

    cout << ans.size() << endl;
    

}