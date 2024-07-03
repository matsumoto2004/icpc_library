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

bool isok(string &s,int i,int j,int k){
    if(s[i]=='i'&&s[j]=='w'&&s[k]=='i') return true;
    else return false;
}

int main(){
    string s;
    cin >> s;
    ll n=s.size();
    VVl dp(n+5,Vl(n+5,0));
    for(int range=3;range<=n;range++)rep(i,n){
        int j=i+range-1;
        if(j>=n) continue;
        if(range==3){
            if(isok(s,i,i+1,i+2)) dp[i][j]=1;
            continue;
        }
        //3-0
        if(isok(s,i,i+1,i+2)){
            if(range%3==0&&dp[i+3][j]==range/3-1) chmax(dp[i][j],dp[i+3][j]+1);
        }
        //2-1
        if(isok(s,i,i+1,j)){
            if(range%3==0&&dp[i+2][j-1]==range/3-1) chmax(dp[i][j],dp[i+2][j-1]+1);
        }
        //1-2
        if(isok(s,i,j-1,j)){
            if(range%3==0&&dp[i+1][j-2]==range/3-1) chmax(dp[i][j],dp[i+1][j-2]+1);
        }
        //0-3
        if(isok(s,j-2,j-1,j)){
            if(range%3==0&&dp[i][j-3]==range/3-1) chmax(dp[i][j],dp[i][j-3]+1);
        }
        rrep(k,i,j) chmax(dp[i][j],dp[i][k]+dp[k+1][j]);
        //cout << i << j << " " << dp[i][j] << endl;
    }
    cout << dp[0][n-1] << endl;
}