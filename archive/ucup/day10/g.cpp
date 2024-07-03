#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
using ll=long long;
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

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    if(n==1||m==1){
        cout << "YES" << endl;
        return 0;
    }
    if(m>=200005){
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<pl>> v(m);
    rep(i,k){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;y--;z--;
        v[z].push_back({x,y});
    }
    rep(i,m){
        v[i].pb({-2,-1});
        v[i].pb({n,n+1});
        sort(v[i].begin(),v[i].end());
    }
    vector<vector<pl>> v2(m);
    vector<vector<ll>> vid(m);

    ll nowid=0;
    rep(i,m){
        rep(j,v[i].size()-1){
            pl p={v[i][j].second+1,v[i][j+1].first-1};
            if(p.first>p.second) continue;
            //cout << p.first << p.second << endl;
            v2[i].push_back(p);
            vid[i].push_back(nowid);
            nowid++;
        }
    }

    dsu uf(nowid);

    //cout << nowid << endl;

    rep(i,m-1){
        //しゃくとり
        ll now1=0;
        ll now2=0;
        ll sz1=v2[i].size();
        ll sz2=v2[i+1].size();
        while(now1<sz1&&now2<sz2){
            ll x1=v2[i][now1].first;
            ll y1=v2[i][now1].second;
            ll x2=v2[i+1][now2].first;
            ll y2=v2[i+1][now2].second;
            ll id1=vid[i][now1];
            ll id2=vid[i+1][now2];
            //cout << x1 << y1 << " " << x2 << y2 << endl;
            if(y1<x2){
                now1++;
                continue;
            }
            if(y2<x1){
                now2++;
                continue;
            }
            //被ってる範囲があるらしい
            if(x1!=y2&&x2!=y1&&x1!=y1&&x2!=y2){
                cout << "NO" << endl;
                return 0;
            }
            else{
                //cout << i << " " << id1 << id2 << endl;
                if(uf.same(id1,id2)){
                    cout << "NO" << endl;
                    return 0;
                }
                uf.merge(id1,id2);
                if(x1==y2){
                    now2++;
                }
                else if(x2==y1){
                    now1++;
                }
                else if(x1==y1){
                    now1++;
                }
                else if(x2==y2){
                    now2++;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}