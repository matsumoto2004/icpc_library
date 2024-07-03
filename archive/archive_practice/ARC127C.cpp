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

ll one=0;

void minus1(string &s){
    ll whe=0;
    s+='#';
    while(s[whe]=='0'){
        whe++;
    }
    s[whe]='0';
    one--;
    rep(i,whe){
        s[i]='1';
        one++;
    }
    s.pop_back();
    return;
}



int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());//i番目が2^iの位   
    while(s.size()<n) s+='0';
    rep(i,n) one+=s[i]-'0';
    string ans="1";
    minus1(s);
    rep(i,n-1){
        if(one==0||s.size()==0)break;
        if(s.back()=='0'){
            ans+='0';
            s.pop_back();
            minus1(s);
        }
        else{
            ans+='1';
            s.pop_back();
            one--;
        }
    }
    cout << ans << endl;
}
