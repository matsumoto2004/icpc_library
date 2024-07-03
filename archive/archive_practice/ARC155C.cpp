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
    Vl va(n),vb(n);
    rep(i,n) cin >> va[i];
    rep(i,n) cin >> vb[i];
    Vl va2=va,vb2=vb;
    sort(all(va2));
    sort(all(vb2));
    if(va2!=vb2){
        cout << "No" << endl;
        return 0;
    }
    bool vafree=false,vbfree=false;
    rep(i,n-2){
        if(va[i]%2==1){
            if(va[i+1]%2==1||va[i+2]%2==1) vafree=true;
        }
    }
    if(va[n-2]%2==1&&va[n-1]%2==1) vafree=true;
    rep(i,n-2){
        if(vb[i]%2==1){
            if(vb[i+1]%2==1||vb[i+2]%2==1) vbfree=true;
        }
    }
    if(vb[n-2]%2==1&&vb[n-1]%2==1) vbfree=true;
    if(vafree&&vbfree){
        ll evencount=0;
        rep(i,n) if(va[i]%2==0) evencount++;
        if(evencount==2){
            ll x=-1;
        rep(i,n){
            if(va[i]%2==0) x=va[i];
        }
        ll y=-1;
        rep(i,n){
            if(vb[i]%2==0) y=vb[i];
        }
        if(x==y){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
        if(evencount==0&&va!=vb){
            cout << "No" << endl;
            return 0;
        }

        cout << "Yes" << endl;
        return 0;
    }
    else if(vafree||vbfree){
        cout << "No" << endl;
        return 0;
    }

    
    Vl va3,vb3;
    rep(i,n){
        if(va[i]%2==1||vb[i]%2==1){
            if(va[i]!=vb[i]){
                cout << "No" << endl;
                return 0;
            }
            if(va3.size()<=2&&va3!=vb3){
                cout << "No" << endl;
                return 0;
            }
            sort(all(va3));
            sort(all(vb3));
            if(va3!=vb3){
                cout << "No" << endl;
                return 0;
            }
            va3={};
            vb3={};
        }
        else{
            va3.push_back(va[i]);
            vb3.push_back(vb[i]);
        }
    }
    cout << "Yes" << endl;
}
