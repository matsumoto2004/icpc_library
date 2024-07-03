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
    while(1){
        ll n;
        cin >> n;
        if(n==0) break;
        string s;
        cin >> s;
        
        Vl bit(150,0);
        string ss="1"+s;
        rep(i,53) bit[i]+=ss[i]-'0';
        reverse(all(ss));
        rep(i,63){
            if((n>>i)&1){
                rep(j,53){
                    if(j>=i)bit[i+j]+=ss[j]-'0';
                }
            }
        }
        rep(i,140){
            bit[i+1]+=bit[i]/2;
            bit[i]%=2;
        }
        //rep(i,140) cout << bit[i] << " ";
        //cout << endl;
        ll start=150;
        while(bit[start]==0) start--;
        start--;
        string ans;
        ll sisu=start-51;
        rep(i,52){
            ans+=char(bit[start]+'0');
            start--;
        }
        string ans2;
        rep(i,12){
            if((sisu>>i)&1)ans2+='1';
            else ans2+='0';
        }
        reverse(all(ans2));
        string fans=ans2+ans;
        cout << ans2+ans << endl;
        //cout << sisu << endl;



    }
}