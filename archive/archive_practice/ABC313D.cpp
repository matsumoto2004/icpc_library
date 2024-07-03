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

void query(Vl v){
    cout << "?" << " ";
    for(auto p:v) cout << p+1 << " ";
    cout << endl;
}

int main(){
    ll n,k;
    cin >> n >> k;
    Vl v(n);
    Vl vq(k);
    rep(i,k) vq[i]=i;
    //1回目
    ll firstans=0;
    query(vq);
    cin >> firstans;
    v[k-1]=0;
    //2回目　(n-k)
    ll nowans=firstans;
    rep(i,n-k){
        vq[k-1]++;
        query(vq);
        ll x;cin >> x;
        if(x!=nowans) v[k+i]=1-v[k+i-1];
        else v[k+i]=v[k+i-1];
        nowans=x;
    }
    
    //それ以降
    repd(i,k-1){
        vq[i]++;
        query(vq);
        ll x;cin >> x;
        if(x!=nowans) v[i]=1-v[i+1];
        else v[i]=v[i+1];
        nowans=x;
    }
    //reversecheck
    ll sum=0;
    rep(i,k) sum+=v[i];
    sum%=2;
    if(sum==firstans){
        cout << "! " << endl;
        rep(i,n) cout << v[i] << " ";
        cout << endl;
    }
    else{
        cout << "! " << endl;
        rep(i,n) cout << 1-v[i] << " ";
        cout << endl;
    }
}