#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
using vl=vector<long long>;
using vvl=vector<vl>;
using pl=pair<ll,ll>;
#define pb push_back

struct oper{
    public:
    ll type;
    ll a,b,c,d;
    char e;
    oper(){}
    void init1(ll aa,ll bb,ll cc,ll dd,char ee){
        type=1;
        a=aa;b=bb;c=cc;d=dd;e=ee;
    }
    void init2(ll aa,ll bb,ll cc,char ee){
        type=2;
        a=aa;b=bb;c=cc;e=ee;
    }
    void init3(){
        type=3;
    }
};

//mypair1
struct mp1{
    ll req;
    ll a,b,c,id;
    mp1(ll req,ll a,ll b,ll c,ll id):req(req),a(a),b(b),c(c),id(id){}
};

bool operator<(const mp1 &p1,const mp1 &p2){
    return p1.req<p2.req;
}

void solve(){
    ll n;
    cin >> n;

    //////////変えろ！！！！
    ll ok=81,ng=79;//mid以下に抑えられるか

    vl va(n),vb(n),vc(n);
    rep(i,n) cin >> va[i] >> vb[i] >> vc[i];
    vl fans(n,0);

    ll asum=0,bsum=0;
    rep(i,n){
        asum+=va[i];
        bsum+=vb[i];
    }

    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        
        priority_queue<mp1> pq1;//まだ使っていない　使えない
        priority_queue<mp1> pq2;//まだ使っていない　使える

        bool isok=true;

        rep(i,n){
            if((va[i]+vb[i])*vc[i]>mid) isok=false;
        }

        if(isok==false){
            ng=mid;
            continue;
        }

        rep(i,n){
            ll req=mid-va[i]*vc[i];//vb[i]はどーせ含まれるので
            req/=vc[i];
            //req以下ならok
            pq1.push(mp1(req,va[i],vb[i],vc[i],i));//reqを大きい順に取り出したい
        }
        ll nowsum=bsum;
        vl ans;
        rep(i,n){
            while(!pq1.empty()){
                mp1 p=pq1.top();
                if(nowsum>p.req){
                    break;
                }
                pq1.pop();
                ll a=p.a,b=p.b,c=p.c,id=p.id;
                pq2.push(mp1(b-a,a,b,c,id));
                //cout << i << " " << id << endl;
            }
            if(pq2.empty()){
                isok=false;
                break;
            }
            else{
                mp1 p=pq2.top();
                pq2.pop();
                ll a=p.a,b=p.b,c=p.c;
                if((nowsum+a)*c>mid){
                    isok=false;
                    break;
                }
                ans.pb(p.id);
                nowsum+=a-b;
                cout << p.id << endl;
            }
            
        }

        if(isok){
            ok=mid;
            swap(ans,fans);
        }        
        else ng=mid;
    }

    cout << ok << endl;

    rep(i,n){
        cout << fans[i]+1;
        if(i!=n-1) cout << " ";
        else cout << endl;
    }

}

int main(){
    ll t;
    cin >> t;
    rep(i,t) solve();      
}