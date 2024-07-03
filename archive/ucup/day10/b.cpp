#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
using ll=long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    bool is_int=true;
    ll v=0;
    rep(i,n){
        if(v%2==0){
            v/=2;
            v+=a[i];
        }
        else{
            v=(v-1)/2;
            is_int=false;
            v+=a[i];
        }
        if(v==0 && is_int){
            cout << 0;
        }
        else{
            cout << (v>0 ? '+':'-');
        }
    }
    cout << endl;
}