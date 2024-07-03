#include<bits/stdc++.h>
#include<cassert>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/tag_and_trait.hpp>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(i, n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i, s, n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i, s, n, d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i, n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i, n, t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i, n, t, d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SUM(a) accumulate(all(a),0LL)
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SORT(a) sort(all(a));
#define REV(a) reverse(all(a));
#define SZ(a) int(a.size())
#define popcount(x) __builtin_popcountll(x)
#define pf push_front
#define pb push_back
#define ef emplace_front
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0);
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vp = vector<P>;
using vvp = vector<vp>;

//template<class T>
//using PQ = priority_queue <pair<T, int>, vector<pair < T, int>>, greater <pair<T, int>>>;

template<class T>
using PQ = priority_queue <T, vector<T>, greater <T>>;

template<class S, class T>
istream &operator>>(istream &is, pair <S, T> &p) { return is >> p.first >> p.second; }

template<class S, class T>
ostream &operator<<(ostream &os, const pair <S, T> &p) { return os << '{' << p.first << ", " << p.second << '}'; }

template<class S, class T, class U>
istream &operator>>(istream &is, tuple <S, T, U> &t) { return is >> get<0>(t) >> get<1>(t) >> get<2>(t); }

template<class S, class T, class U>
ostream &operator<<(ostream &os, const tuple <S, T, U> &t) {
    return os << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '}';
}

template<class T>
istream &operator>>(istream &is, vector <T> &v) {
    for (T &t: v) { is >> t; }
    return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const deque <T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const set <T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T>
ostream &operator<<(ostream &os, const multiset <T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T>
void vecout(const vector <T> &v, char div = '\n') {
    rep(i, v.size()) cout << v[i] << (i == int(v.size() - 1) ? '\n' : div);
}

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void scan() {}

template<class Head, class... Tail>
void scan(Head &head, Tail &... tail) {
    cin >> head;
    scan(tail...);
}

template<class T>
void print(const T &t) { cout << t << '\n'; }

template<class Head, class... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

template<class... T>
void fin(const T &... a) {
    print(a...);
    exit(0);
}

template<class T>
vector <T> &operator+=(vector <T> &v, T x) {
    for (T &t: v) t += x;
    return v;
}

template<class T>
vector <T> &operator-=(vector <T> &v, T x) {
    for (T &t: v) t -= x;
    return v;
}

template<class T>
vector <T> &operator*=(vector <T> &v, T x) {
    for (T &t: v) t *= x;
    return v;
}

template<class T>
vector <T> &operator/=(vector <T> &v, T x) {
    for (T &t: v) t /= x;
    return v;
}

struct Init_io {
    Init_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << boolalpha << fixed << setprecision(15);
        cerr << boolalpha << fixed << setprecision(15);
    }
} init_io;

const string yes[] = {"no", "yes"};
const string Yes[] = {"No", "Yes"};
const string YES[] = {"NO", "YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;

void rearrange(const vi &) {}

template<class T, class... Tail>
void rearrange(const vi &ord, vector <T> &head, Tail &...tail) {
    assert(ord.size() == head.size());
    vector <T> ori = head;
    rep(i, ord.size()) head[i] = ori[ord[i]];
    rearrange(ord, tail...);
}

template<class T, class... Tail>
void sort_by(vector <T> &head, Tail &... tail) {
    vi ord(head.size());
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return head[i] < head[j]; });
    rearrange(ord, head, tail...);
}

template<class T, class S>
vector <T> cumsum(const vector <S> &v, bool shift_one = true) {
    int n = v.size();
    vector <T> res;
    if (shift_one) {
        res.resize(n + 1);
        rep(i, n) res[i + 1] = res[i] + v[i];
    } else {
        res.resize(n);
        if (n) {
            res[0] = v[0];
            rep(i, 1, n) res[i] = res[i - 1] + v[i];
        }
    }
    return res;
}

vvi graph(int n, int m, bool directed = false, int origin = 1) {
    vvi G(n);
    rep(_, m) {
        INT(u, v);
        u -= origin, v -= origin;
        G[u].pb(v);
        if (!directed) G[v].pb(u);
    }
    return G;
}

template<class T>
vector <vector<pair < int, T>>>

weighted_graph(int n, int m, bool directed = false, int origin = 1) {
    vector < vector < pair < int, T>>> G(n);
    rep(_, m) {
        int u, v;
        T w;
        scan(u, v, w);
        u -= origin, v -= origin;
        G[u].eb(v, w);
        if (!directed) G[v].eb(u, w);
    }
    return G;
}

class lowlink {
    vvi G;
    vi ord, low;
    
    int dfs(int u, int p, int k) {
        ord[u] = low[u] = k++;
        bool flag = false;
        int cnt = 0;
        for (int v: G[u]) {
            if (ord[v] < 0) {
                cnt++;
                k = dfs(v, u, k);
                chmin(low[u], low[v]);
                flag |= p >= 0 and ord[u] <= low[v];
                if (ord[u] < low[v]) bridge.eb(u, v);
            } else if (v != p) {
                chmin(low[u], ord[v]);
            }
        }
        flag |= p < 0 and cnt > 1;
        if (flag) articulation.pb(u);
        return k;
    }
    
    void init() {
        ord.assign(G.size(), -1);
        low.assign(G.size(), -1);
        int k = 0;
        rep(i, G.size()) {
            if (ord[i] < 0) k = dfs(i, -1, k);
        }
    }

public:
    vi articulation;
    vp bridge;
    
    lowlink(const vvi &G) : G(G) { init(); }
};

class dsu {
    int n;
    vector<int> par, rank;
public:
    dsu(int n) : n(n), par(n, -1), rank(n, 0) {}
    
    int leader(int x) {
        if (par[x] < 0) return x;
        else return par[x] = leader(par[x]);
    }
    
    bool is_leader(int x) { return leader(x) == x; }
    
    bool same(int x, int y) { return leader(x) == leader(y); };
    
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) { return -par[leader(x)]; };
    
    vi leaders() {
        vi res;
        rep(i, n) if (leader(i) == i) res.pb(i);
        return res;
    }
    
    bool connected() {
        return leaders().size() == 1;
    }
};


int main() {
    while(1){
        ll n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
    
        auto id=[&](ll i,ll j) -> ll {
            return n*i+j;
        };

        vvi g(2*n);
        vector<LP> ed;
        rep(i,m){
            ll x,y;
            cin >> x >> y;
            x--;y--;
            ll xx=id(0,x),yy=id(1,y);
            g[xx].pb(yy);
            g[yy].pb(xx); 
            ed.pb({xx,yy});
        }

        lowlink lk(g);
        map<LP,ll> isbri;
        for(auto p:lk.bridge){
            isbri[p]=1;
            isbri[{p.second,p.first}]=1;
        }

        dsu uf(2*n);
        dsu uf2(2*n);

        vector<LP> bri;
        for(auto [x,y]:ed){
            if(isbri[{x,y}]==0) uf.merge(x,y);
            else{
                bri.pb({x,y});
                uf2.merge(x,y);
            }
        }
        map<ll,ll> id;
        ll nowid=1;
        rep(i,2*n){
            if(uf.size(i)==2){
                id[uf.leader(i)]=-1;
            }
            if(id[uf.leader(i)]==0){
                id[uf.leader(i)]=nowid;
                nowid++;
            } 
        }

        //ひとつもない場合
        if(nowid==1){
            cout << 0 << endl;
            continue;
        }

        vvl to(nowid-1);
        for(auto [x,y]:bri){
            if(id[x]>0){
                to[id[x]-1].pb(id[y]-1);
                to[id[y]-1].pb(id[x]-1);
            }
        }

        vl sz(nowid,0);

        auto dfs1=[&](auto dfs1,ll v,ll p=-1) -> void {
            sz[v]++;
            for(auto u:to[v]){
                if(u==p) continue;
                sz[v]+=sz[u];
            }
        };

        rep(i,n){
            if(sz[v]==0) dfs1(dfs1,i);
        }

        vvl dp(nowid);

        auto dfs2=[&](auto dfs2,ll v,ll p=-1) -> void {
            dp[v].pb(0);
            for(auto u:to[v]){
                vl ndp(dp[v].size()+sz[u]+1);
                rep(i,dp[v].size())rep(j,sz[u]){   
                }
            }

        };

        rep(i,n){
            if(dp[i].size()==0) dfs2(dfs2,i);
        }
    }
}