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
    Vl vsq;
    rrep(i,1,100005) vsq.PB((ll)i*i);
    ll ans=0;
    rrep(i,1,n+1){
        int j=1;
        ll ii=i,jj=1;
        rrep(div,2,sqrt(i)+1){
            while(ii%div==0){
                if(ii%(div*div)==0){
                    ii/=(div*div);
                }
                else{
                    ii/=div;
                    jj*=div;
                }
            }
        }
        if(ii!=1) jj*=ii;
        if(jj>n) continue;
        ll ok=0,ng=100003;
        while(ng-ok>1){
            ll mid=(ok+ng)/2;
            if(vsq[mid]*jj>n) ng=mid;
            else ok=mid;
        }
        ans+=ok+1;
    }
    cout << ans << endl;
}