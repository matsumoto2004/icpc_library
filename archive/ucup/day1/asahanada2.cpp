#include<bits/stdc++.h>
#include<cassert>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i< ll(n);i++)

using ull=unsigned long long;
const ull MOD=(1LL<<61)-1;
const ull MASK31=(1LL<<31)-1;
const ull MASK30=(1LL<<30)-1;
const ull MASK61=MOD;

ull calcmod(const ull x){
    ull xu=x>>61;
    ull xd=(x&MASK61);
    xu+=xd;
    if(xu>=MOD)xu-=MOD;
    return xu;
}

ull prod_61(const ull a,const ull b){
    ull au=a>>31;
    ull ad=a&MASK31;
    ull bu=b>>31;
    ull bd=b&MASK31;

    ull mid=ad*bu+au*bd;
    ull mu=mid>>30;
    ull md=mid&MASK30;
    return au*bu*2 + mu + (md<<31) + ad*bd;
}

ull exp_61(ull a,ull b){
    if(b==0)return 1;
    if(b==1)return a;
    if(b&1){
        return calcmod(prod_61(exp_61(a,b-1),a));
    }
    ull t=exp_61(a,b/2);
    return calcmod(prod_61(t,t));
}
struct rolling_hash{
    string s;
    vector<ull> hashes;
    ull base;
    vector<ull> base_pow;
    rolling_hash(){}
    rolling_hash(const string _, ull now_base=0):s(_),hashes(_.size()+1,0),base(now_base), base_pow(_.size()+1,1){
        if(!base)init();
        calchash();
        for(int i=0;i<int(s.size());i++){
            base_pow[i+1]=calcmod(prod_61(base_pow[i], base));
        }
    }
    void init(){
        random_device seed_gen;
        mt19937_64 rnd(seed_gen());
        uniform_int_distribution<ull> for_base(1UL, MOD-2);
        while(true){
            ull _r=for_base(rnd);
            if(gcd(_r, MOD-1)!=1)continue;
            base=exp_61(3UL, _r);
            if(base<=30)continue;
            break;
        }
        return;
    }
    void calchash(){
        for(int i=0;i<(int)s.size();i++){
            hashes[i+1]=calcmod(prod_61(hashes[i],base) + (s[i]-'a'+1));
        }
        return;
    }
    ull hash(int i,int j){
        ull res=MOD+hashes[j]-calcmod(prod_61(hashes[i], base_pow[j-i]));
        if(res>=MOD)res-=MOD;
        return res;
    }
};

struct vertex{
    bool is_s;
    ull val_string;
    vertex(bool a, ull b):is_s(a), val_string(b){}
    bool operator<(const vertex &v)const{
        if(val_string!=v.val_string)return val_string<v.val_string;
        return is_s < v.is_s;
    }
};
struct edge{
    ull to;
    int idx;
    edge(ull v, int i):to(v), idx(i){}
};
ull encode(bool is_s, ull val_string){
    return val_string * 2 + is_s;
}
bool decode(ull v){
    return v&1;
}

void solve(int n,int m,vector<string> a,vector<string> b){
    vector<rolling_hash> a_hash(n),b_hash(n);
    ull now_base=0;
    rep(i,n){
        a_hash[i]=rolling_hash(a[i], now_base);
        now_base=a_hash[i].base;
        b_hash[i]=rolling_hash(b[i], now_base);
    }
    rep(s,m){
        int t=m-s;
        //aをs文字とt文字に分割
        //bをt文字とs文字に分割
        unordered_map<ull, queue<edge>> g;
        unordered_map<ull, int> in_cnt;
        rep(i,n){
            g[encode(true, a_hash[i].hash(0,s))].push(edge(encode(false, a_hash[i].hash(s,m)), i));
            in_cnt[encode(false, a_hash[i].hash(s,m))]+=1;
            g[encode(false, b_hash[i].hash(0,t))].push(edge(encode(true, b_hash[i].hash(t,m)), i));
            in_cnt[encode(true, b_hash[i].hash(t,m))]+=1;
        }

        //出次数と入次数の一致チェック
        unordered_map<ull, int> cnt;
        for(auto&& [v, nxt]:g){
            cnt[v]+=nxt.size();
            queue<edge> vvv;
            while(!nxt.empty()){
                auto [w,i]=nxt.front();
                nxt.pop();
                cnt[w]-=1;
                vvv.push({w,i});
            }
            nxt=vvv;
        }
        bool ok=true;
        for(auto [v,i]:cnt){
            if(i!=0)ok=false;
        }
        if(!ok)continue;

        vector<int> ans_a, ans_b;
        unordered_map<ull, int> cnt_dfs;

        auto dfs=[&](ull v, auto &dfs)->void{
            if(cnt_dfs[v]==in_cnt[v])return;
            cnt_dfs[v]+=1;
            while(!g[v].empty()){
                auto [w,i]=g[v].front();
                g[v].pop();
                dfs(w,dfs);
                if(decode(v))ans_a.push_back(i);
                else ans_b.push_back(i);
            }
        };
        dfs(g.begin()->first,dfs);
        if((int)a.size()!=n){
            continue;
        }
        assert(a.size() == b.size());
        for(int i=n-1;i>=0;i--)cout << ans_a[i]+1 << " \n"[i==0];
        for(int i=n-1;i>=0;i--)cout << ans_b[i]+1 << " \n"[i==0];
        return;
    }

    cout << -1 << endl;
    return;
}

int main(){
    ll t;
    cin >> t;
    rep(i,t){
        int n,m;
        cin >> n >> m;
        vector<string> a(n),b(n);
        rep(i,n)cin >> a[i];
        rep(i,n)cin >> b[i];
        solve(n,m,a,b);
    }
}
