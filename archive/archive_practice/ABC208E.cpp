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
    ll n,k;
    cin >> n >> k;
    map<ll,ll> dp1,dp2;
    ll over1=0;
    ll over2=0;
    ll now=1e18;
    rep(i,19){
        ll digit=(n%(now*10))/now;
        //cout << digit << endl;
        map<ll,ll> newdp1,newdp2;
        ll newover1=0,newover2=0;
        //つけたし
        for(auto p:dp1){
            if(p.F*digit<=k) newdp1[p.F*digit]+=p.S;
            else newover1+=p.S;

            rrep(j,0,digit){
                if(p.F*j<=k) newdp2[p.F*j]+=p.S;
                else newover2+=p.S;
            }
        }
        for(auto p:dp2){
            rrep(j,0,10){
                if(p.F*j<=k) newdp2[p.F*j]+=p.S;
                else newover2+=p.S;
            }
        }
        //おnew
        if(n/now>=10){
            rrep(j,1,10){
                if(j<=k) newdp2[j]++;
                else newover2++;
            }
        }
        else{
            if(digit>0){
                if(digit<=k) newdp1[digit]++;
                else newover1++;
            }
            rrep(j,1,digit){
                if(j<=k) newdp2[j]++;
                else newover2++;
            }
        }
        
        //overの処理

        if(digit!=0){
            newover1+=over1;
            newover2+=over1*(digit-1)+over2*9;
            newdp2[0]+=over1+over2;
        }
        if(digit==0){
            newdp1[0]+=over1;
            newdp2[0]+=over2;
            newover2+=over2*9;
        }

        now/=10;
        swap(dp1,newdp1);
        swap(dp2,newdp2);
        swap(over1,newover1);
        swap(over2,newover2);
        //cout << now*10 << endl;
        //for(auto p:dp1) cout << p.F << " " << p.S << endl;
        //for(auto p:dp2) cout << p.F << " " << p.S << endl;
    }
    ll ans=0;
    for(auto p:dp1) ans+=p.S;
    for(auto p:dp2) ans+=p.S;
    cout << ans << endl;
}