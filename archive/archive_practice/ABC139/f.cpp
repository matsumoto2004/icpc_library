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
#include<cassert>

std::vector<std::pair<long long,long long>> arg_sort(std::vector<std::pair<long long,long long>> A,std::pair<long long,long long> d = {1,0}){
    // Copyright (c) 2023 0214sh7
    // https://github.com/0214sh7/library/
    long long N = A.size();
    assert(d.first != 0 || d.second != 0);
    long long g = std::gcd(d.first,d.second);
    d.first/=g;d.second/=g;
    A.push_back(d);
    std::sort(A.begin(),A.end(),[&](std::pair<long long,long long> x, std::pair<long long,long long> y){
        assert(x.first != 0 || x.second != 0);
        assert(y.first != 0 || y.second != 0);
        
        long long a,b;
        if(x.first>0 && x.second==0){
            a=0;
        }else if(x.first>0 && x.second>0){
            a=1;
        }else if(x.first==0 && x.second>0){
            a=2;
        }else if(x.first<0 && x.second>0){
            a=3;
        }else if(x.first<0 && x.second==0){
            a=4;
        }else if(x.first<0 && x.second<0){
            a=5;
        }else if(x.first==0 && x.second<0){
            a=6;
        }else{
            a=7;
        }
        
        if(y.first>0 && y.second==0){
            b=0;
        }else if(y.first>0 && y.second>0){
            b=1;
        }else if(y.first==0 && y.second>0){
            b=2;
        }else if(y.first<0 && y.second>0){
            b=3;
        }else if(y.first<0 && y.second==0){
            b=4;
        }else if(y.first<0 && y.second<0){
            b=5;
        }else if(y.first==0 && y.second<0){
            b=6;
        }else{
            b=7;
        }
        
        if(a!=b){
            return (a<b);
        }
        
        if(a%2==0){
            return (std::abs(x.first+x.second) < std::abs(y.first+y.second));
        }
        
        if(y.first*x.second != x.first*y.second){
           return (y.first*x.second < x.first*y.second);
        }
        
        return abs(x.first) < abs(y.first);
    });
    
    std::vector<std::pair<long long,long long>> B(N);
    for(int i=0;i<N+1;i++){
        if(A[i]==d){
            for(int j=i+1;j<N+1;j++){
                B[j-i-1]=A[j];
            }
            for(int j=0;j<i;j++){
                B[N-i+j]=A[j];
            }
            break;
        }
    }
    
    return B;
}





long double dist(ll x,ll y){
    long double ret=sqrt(x*x+y*y);
    return ret;
}

//解説AC
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    rep(i,n) cin >> v[i].first >> v[i].second;
    vector<pair<ll,ll>> newv;
    ll newn=0;
    rep(i,n){
        if(v[i].first==0&&v[i].second==0){

        }
        else{
            newn++;
            newv.push_back(v[i]);
        }
    }
    swap(v,newv);
    swap(n,newn);
    vector<pair<ll,ll>> v2=arg_sort(v);
    long double ans=0;
    rep(i,n){
        ll x=0,y=0;
        for(int j=i;j!=i+n;j++){
            x+=v2[j%n].first;
            y+=v2[j%n].second;
            chmax(ans,dist(x,y));
        }
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;       
}