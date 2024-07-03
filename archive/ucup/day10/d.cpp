#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
using vl=vector<long long>;
using vvl=vector<vl>;
using pl=pair<ll,ll>;
#define pb push_back

class dsu{
    int n;
    vector<int> par,rank;
public:
    dsu(int n):n(n),par(n,-1),rank(n,0){}

    int leader(int x){
        if(par[x]<0) return x;
        else return par[x]=leader(par[x]);
    }

    bool is_leader(int x){return leader(x)==x;}
    bool same(int x,int y){return leader(x)==leader(y);};

    bool merge(int x,int y){
        x=leader(x),y=leader(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x,y);
        if(rank[x]==rank[y]) rank[x]++;
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int size(int x) {return -par[leader(x)];};

    vector<int> leaders(){
        vector<int> res;
        rep(i,n) if(leader(i)==i) res.push_back(i);
    }

    bool connected(){
        return leaders().size()==1;
    }
};

const int SZ=int(1e6)+1;

vector<int> omega(SZ,0);

void init_omega(){
    for(int i=2;i<SZ;i++)if(omega[i]==0){
        for(int j=i;j<SZ;j+=i){
            omega[j]++;
        }
    }
    return;
}

vector<int> prime;

void init_prime(){
    vl era(SZ+5,0);
    for(ll p=2;p<SZ;p++){
        if(era[p]) continue;
        prime.pb(p);
        ll now=p;
        while(now<SZ){
            era[now]++;
            now+=p;
        }
        
    }
    prime.pb(1e9);

}

void solve(){
    
    ll a,b;
    cin >> a >> b;
    if(a==1){
        ll ans=0;
        for(ll i=2;i<=b;i++){
            ans+=omega[i];
        }
        cout << ans << endl;
        return;
    }
    if(b-a<=75){
        ll ans=0;
        dsu uf(b-a+10);
        priority_queue<tuple<ll,ll,ll>> pq;
        for(int i=a;i<=b;i++)for(int j=i+1;j<=b;j++){
            pq.push({-omega[i]-omega[j]+omega[gcd(i,j)],i,j});
        }
        while(!pq.empty()){
            auto[x,y,z]=pq.top();
            pq.pop();
            //cout << x << y << z << endl;
            if(!uf.same(y-a,z-a)){
                uf.merge(y-a,z-a);
                ans+=-x;
            }
        }
        cout << ans << endl;
    }
    else{
        ll ans=0;
        vl era(b+5);
        vl checked(b+5);
        for(ll i=a;i<=b;i++){
            ll now=i;

            ll whe=0;
            while(1){
                ll p=prime[whe];
                //cout << p << endl;
                if(p*p>now) break;
                while(now%(p*p)==0) now/=p;
                whe++;
            }
            era[now]++;

            ans+=omega[i];
        }

        for(ll p=2;p<=b;p++){
            if(checked[p]) continue;
            if(era[p]==0) continue;
            ans++;
            ll now=p;
            while(now<=b){
                checked[now]++;
                now+=p;
            }
        }
        cout << ans-2 << endl;
    }

}

int main(){
    init_omega();
    init_prime();
    ll t;
    cin >> t;
    rep(i,t) solve();
}