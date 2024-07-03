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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
VVl yakunumlist;
void dfs(Vl ret,Vl& yakunum){
    if(ret.size()==yakunum.size()){
        yakunumlist.PB(ret);
    }
    else{
        rep(i,yakunum[ret.size()]+1){
            Vl next=ret;
            next.PB(i);
            dfs(next,yakunum);
        }
    }
    return;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int checked[(int)4e7];

int main(){    
    Vl prime;
    for(ll i=2;i*i<=1e15;i++){
        if(checked[i]!=0) continue;
        prime.PB(i);
        ll now=i*i;
        while(now<4e7){
            checked[now]++;
            now+=i;
        }
    }
    while(1){
        yakunumlist.resize(0);
        ll n;
        cin >> n;
        ll nn=n;
        if(n==0) break;

        Vl yaku=Vl();
        Vl yakuprime;
        Vl yakunum;
        for(ll p:prime){
            if(n%p!=0) continue;
            yakuprime.PB(p);
            ll cnt=0;
            while(nn%p==0){
                cnt++;
                nn/=p;
            }
            yakunum.PB(cnt);
        }
        if(nn!=1){
            yakuprime.PB(nn);
            yakunum.PB(1);
        }
        //
        //for(auto xx:yakuprime) cout << xx << " ";
        //cout << endl;
        //for(auto xx:yakunum) cout << xx << " ";
        //cout << endl;
        dfs(Vl(),yakunum);
        for(auto vv:yakunumlist){
            //
            //for(auto xx:vv) cout << xx << " ";
            //cout << endl;
            //
            ll now=1;
            rep(i,vv.size()){
                now*=modpow(yakuprime[i],vv[i],inf);
            }
            //cout << now << endl;
            yaku.PB(now);
        }

        sort(all(yaku));
        //rep(i,yaku.size()) cout << yaku[i] << " ";
        ll ans=inf;
        rep(i,yaku.size()){
            ll x=yaku[i];
            if(x*x*x>n) break;
            ll nokori=n/x;
            Vl yaku2;
            for(auto div:yaku){
                if(nokori%div==0) yaku2.PB(div);
            }
            ll y=yaku2[upper_bound(all(yaku2),sqrt(nokori))-yaku2.begin()-1];
            ll z=nokori/y;
            chmin(ans,x+y+z); 
            
        }
        cout << ans << endl;
    }
}