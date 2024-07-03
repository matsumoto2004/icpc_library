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
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    v.push_back("DE");
    string ans;
    rep(i,n){
        string s=v[i];
        if(s=="AB"){
            if(a==0&&b==0){
                cout << "No" << endl;
                return 0;
            }
            else if(a==0){
               ans+='A';
               a++;
               b--; 
            }
            else if(b==0){
                ans+='B';
                a--;
                b++;
            }
            else if(i==n-1||v[i+1]==v[i]){
                ans+='A';
                a++;
                b--;
            }
            else{
                if(v[i+1]=="BC"){
                    ans+='B';
                    a--;
                    b++;
                }
                else{
                    ans+='A';
                    a++;
                    b--;
                }
            }
        }
        if(s=="AC"){
            if(a==0&&c==0){
                cout << "No" << endl;
                return 0;
            }
            else if(a==0){
               ans+='A';
               a++;
               c--; 
            }
            else if(c==0){
                ans+='C';
                a--;
                c++;
            }
            else if(i==n-1||v[i+1]==v[i]){
                ans+='A';
                a++;
                c--;
            }
            else{
                if(v[i+1]=="BC"){
                    ans+='C';
                    a--;
                    c++;
                }
                else{
                    ans+='A';
                    a++;
                    c--;
                }
            }
        }
        if(s=="BC"){
            if(b==0&&c==0){
                cout << "No" << endl;
                return 0;
            }
            else if(b==0){
               ans+='B';
               b++;
               c--; 
            }
            else if(c==0){
                ans+='C';
                b--;
                c++;
            }
            else if(i==n-1||v[i+1]==v[i]){
                ans+='C';
                c++;
                b--;
            }
            else{
                if(v[i+1]=="AB"){
                    ans+='B';
                    c--;
                    b++;
                }
                else{
                    ans+='C';
                    c++;
                    b--;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for(char c:ans) cout << c << endl;
}