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

//実装みたい

int main(){
    ll n;
    cin >> n;
    Vl vx(n),vy(n);
    rep(i,n) cin >> vx[i] >> vy[i];
    
    ll m;
    cin >> m;
    Vl whex(m+5),whey(m+5);
    Vl xaxis(m+5),yaxis(m+5);//0は何もしないとき
    whex[0]=0;whey[0]=0;
    xaxis[0]=0;yaxis[0]=1;
    
    rep(i,m){
        ll query;
        cin >> query;
        if(query==2){
            whex[i+1]=-whey[i];
            whey[i+1]=whex[i];
            xaxis[i+1]=xaxis[i]+1;
            yaxis[i+1]=yaxis[i]+1;
        }
        if(query==1){
            whex[i+1]=whey[i];
            whey[i+1]=-whex[i];
            xaxis[i+1]=xaxis[i]+3;
            yaxis[i+1]=yaxis[i]+3;
        }
        if(query==3){
            ll p;
            cin >> p;
            if(xaxis[i]%2==0){
                xaxis[i+1]=xaxis[i]+2;
                yaxis[i+1]=yaxis[i];
                whex[i+1]=2*p-whex[i];
                whey[i+1]=whey[i];
            }
            else{
                xaxis[i+1]=xaxis[i];
                yaxis[i+1]=yaxis[i]+2;
                whey[i+1]=2*p-whey[i];
                whex[i+1]=whex[i];
            }
        }
        if(query==4){
            ll p;
            cin >> p;
            if(xaxis[i]%2==1){
                xaxis[i+1]=xaxis[i]+2;
                yaxis[i+1]=yaxis[i];
                whex[i+1]=2*p-whex[i];
                whey[i+1]=whey[i];
            }
            else{
                xaxis[i+1]=xaxis[i];
                yaxis[i+1]=yaxis[i]+2;
                whey[i+1]=2*p-whey[i];
                whex[i+1]=whex[i];
            }
        }
        cout << whex[i+1] << " " << whey[i+1] << " " << xaxis[i+1]%4 << " " << yaxis[i+1]%4 << endl;
    }
    rep(i,m+1){
        whex[i]%=4;
        whey[i]%=4;
        xaxis[i]%=4;
        yaxis[i]%=4;
    }

    ll q;
    cin >> q;
    rep(query,q){
        ll a,b;
        cin >> a >> b;
        b--;
        ll x=vx[b],y=vy[b];
        ll ox=whex[a],oy=whey[a];
        ll xziku=xaxis[a],yziku=yaxis[a];

        if(xziku%2==0){
            if(xziku==2) x=-x;
            if(yziku==3) y=-y;
        }
        else{
            swap(x,y);
            x=-x;
            xziku--;yziku--;
            if(xziku==2) x=-x;
            if(yziku==-1) y=-y;
        }
        cout << ox+x << " " << oy+y << endl;

    }

}