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

//傾きが正のものと負のもの(と0のもの)に分けて

ll tilt(ll x1,ll y1,ll x2,ll y2){
    if(x1==x2) return inf;//y軸平行
    if()
    if((y1-y2)*(x1-x2)>0) return 1;
    else return -1;
}



int main(){
    ll n;
    cin >> n;
    Vl vx(n),vy(n);
    Vl vtilt(n);
    rep(i,n) cin >> vx[i] >> vy[i]; 
    ll s1=-1,g1=-1,s2=-1,g2=-1;
    ll mnx=inf,mxx=-inf,mny=inf,mxy=-inf;
    rep(i,n){
        ll x1=vx[i],y1=vy[i];
        ll x2=vx[(i+1)%n],y2=vy[(i+1)%n];
        vtilt[i]=tilt(x1,y1,x2,y2);
        chmin(mnx,x1);
        chmax(mxx,x1);
        chmin(mny,y1);
        chmax(mxy,y2);
    }
    rep(i,n){
        if(vtilt[i]!=1&&vtilt[(i+1)%n]==1){
            s1=i;
        }
        if(vtilt[i]==1&&vtilt[(i+1)%n]!=1){
            g1=i;
        }
        if(vtilt[i]!=-1&&vtilt[(i+1)%n]==-1){
            s2=i;
        }
        if(vtilt[i]==-1&&vtilt[(i+1)%n]!=-1){
            g2=i;
        }
    }
    Vl vx1,vy1,vx2,vy2;
    for(int i=s1;i!=(g1+1)%n;i=(i+1)%n){
        vx1.PB(vx[i]);vy1.PB(vy[i]);
    }
    for(int i=s2;i!=(g2+1)%n;i=(i+1)%n){
        vx2.PB(vx[i]);vy2.PB(vy[i]);
    }
    reverse(all(vx1));
    reverse(all(vy1));

    ll q;
    cin >> q;
    Vl vqx(q),vqy(q);
    rep(i,q) cin >> vqx[i] >> vqy[i];    
    Vl ans(q,-1);//0out,1in,2on
    rep(i,q){
        ll x=vqx[i],y=vqy[i];
        if(x<=mnx||x>=mxx||y<=mny||y>=mxy) ans[i]=0;
        ll id1=lower_bound(all(vx1),x)-vx1.begin();
        ll id2=lower_bound(all(vx2),x)-vx2.begin();
        ll x1=vx1[id1-1],y1=vy1[id1-1],x2=vx1[id1],y2=vy1[id1];
        if((y-y1)*(x2-x1)>(y2-y1)*(x-x1)){
            ans[i]=0;
            continue;
        }
        if((y-y1)*(x2-x1)==(y2-y1)*(x-x1)){
            ans[i]=2;
            continue;
        }
        x1=vx2[id2-1];y1=vy2[id2-1];x2=vx2[id2];y2=vy2[id2];
        if((y-y1)*(x2-x1)<(y2-y1)*(x-x1)){
            ans[i]=0;
            continue;
        }
        if((y-y1)*(x2-x1)==(y2-y1)*(x-x1)){
            ans[i]=2;
            continue;
        }
        ans[i]=1;
    }
    //on判定
    rep(i,q){
        ll x=vqx[i],y=vqy[i];
        if(x==mnx&&y<=vy1[0]&&y>=vy2[0]) ans[i]=2;
        if(x==mxx&&y<=vy1.back()&&y>=vy2.back()) ans[i]=2;
    }
    rep(i,q){
        if(ans[i]==0) cout << "OUT" << endl;
        if(ans[i]==1) cout << "IN" << endl;
        if(ans[i]==2) cout << "ON" << endl;
    }
    /*
    for(auto x:vx1) cout << x << " ";
    cout << endl;
    for(auto x:vy1) cout << x << " ";
    cout << endl;
    for(auto x:vx2) cout << x << " ";
    cout << endl;
    for(auto x:vy2) cout << x << " ";
    cout << endl;
    */

}