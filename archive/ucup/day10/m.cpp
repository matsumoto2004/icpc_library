#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

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

int main(){
    ll n;
    cin >> n;
    vector<oper> v(n);
    rep(i,n){
        string s;
        cin >> s;
        if(s=="Rectangle"){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            char e;
            cin >> e;
            v[i].init1(a,b,c,d,e);
        }
        if(s=="Circle"){
            ll a,b,c;
            cin >> a >> b >> c;
            char e;
            cin >> e;
            v[i].init2(a,b,c,e);
        }
        if(s=="Render"){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            v[i].init3();
            
            for(ll jj=d;jj>=b;jj--){
                for(ll ii=a;ii<=c;ii++){
                    for(ll j=i-1;j>=0;j--){
                        ll type=v[j].type;
                        if(type==3){

                        }
                        if(type==1){
                            ll aa=v[j].a,bb=v[j].b,cc=v[j].c,dd=v[j].d;
                            char ee=v[j].e;
                            if(ii>=aa&&ii<=cc&&jj>=bb&&jj<=dd){
                                cout << ee;
                                break;
                            }
                        }
                        if(type==2){
                            ll aa=v[j].a,bb=v[j].b,cc=v[j].c;
                            char ee=v[j].e;
                            if((aa-ii)*(aa-ii)+(bb-jj)*(bb-jj)<=cc*cc){
                                cout << ee;
                                break;
                            }
                        }
                        if(j==0){
                            cout << '.';
                        }

                    }
                    if(i==0){
                        cout << '.';
                    }
                    
                }
                cout << endl;
            }
        }
    }
}