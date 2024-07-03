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
template<class T>
using PQ = priority_queue <pair<T, int>, vector<pair < T, int>>, greater <pair<T, int>>>;

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

struct Edge{
    ll to;
    ll color;
    ll cost;
    Edge(ll to,ll color,ll cost):to(to),color(color),cost(cost){}
};

template<class M>
class segtree {
    using S = typename M::S;
    
    int _n, sz;
    vector <S> d;

public:
    constexpr segtree() : segtree(0) {}
    
    constexpr segtree(int n) : segtree(vector<S>(n, M::e)) {}
    
    constexpr segtree(const vector <S> &init) : _n(int(init.size())) {
        sz = 1;
        while (sz < _n) sz *= 2;
        d.assign(sz * 2, M::e);
        rep(i, _n)
        d[sz + i] = init[i];
        rrep(i, sz, 1)
        d[i] = M::op(d[2 * i], d[2 * i + 1]);
    }
    
    void set(int p, S x) {
        assert(0 <= p and p < _n);
        p += sz;
        d[p] = x;
        while (p > 1) {
            p >>= 1;
            d[p] = M::op(d[2 * p], d[2 * p + 1]);
        }
    }
    
    template<class F>
    void apply(int p, const F &f) {
        assert(0 <= p and p < _n);
        p += sz;
        d[p] = f(d[p]);
        while (p > 1) {
            p >>= 1;
            d[p] = M::op(d[2 * p], d[2 * p + 1]);
        }
    }
    
    S get(int p) {
        assert(0 <= p and p < _n);
        return d[sz + p];
    }
    
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= _n);
        l += sz, r += sz;
        S prod_l = M::e;
        S prod_r = M::e;
        while (l < r) {
            if (l & 1) prod_l = M::op(prod_l, d[l++]);
            if (r & 1) prod_r = M::op(d[--r], prod_r);
            l >>= 1, r >>= 1;
        }
        return M::op(prod_l, prod_r);
    }
    
    S all_prod() {
        return d[1];
    }
    
    template<class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(M::e));
        if (l == _n) return _n;
        l += sz;
        S now = M::e;
        do {
            while (~l & 1) l >>= 1;
            if (!f(M::op(now, d[l]))) {
                while (l < sz) {
                    l *= 2;
                    if (f(M::op(now, d[l]))) {
                        now = M::op(now, d[l]);
                        ++l;
                    }
                }
                return l - sz;
            }
            now = M::op(now, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    
    template<class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(M::e));
        if (r == 0) return 0;
        r += sz;
        S now = M::e;
        do {
            --r;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(M::op(d[r], now))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (f(M::op(d[r], now))) {
                        now = M::op(d[r], now);
                        --r;
                    }
                }
                return r + 1 - sz;
            }
            now = M::op(d[r], now);
        } while ((r & -r) != r);
        return 0;
    }
};

class M {
public:
    using S = ll;
    
    static constexpr S
    e = 0;
    
    static constexpr S
    
    op(const S &l, const S &r) {
        return l+r;
    }
};

class LCA {
    int n;
    vvi G;
    vi dep;
    vvi par;
    
    void dfs(int u, int p, int d) {
        par[0][u] = p;
        dep[u] = d;
        for (int v: G[u]) if (v != p) dfs(v, u, d + 1);
    }
    
    void init() {
        n = G.size();
        dep.assign(n, -1);
        par.resize(30);
        rep(i, 30)
        par[i].resize(n);
        rep(i, n)
        if (dep[i] == -1) dfs(i, -1, 0);
        rep(k, 29)
        rep(i, n)
        {
            if (par[k][i] < 0) par[k + 1][i] = -1;
            else par[k + 1][i] = par[k][par[k][i]];
        }
    }
 
public:
    LCA(const vvi &G) : G(G) { init(); }
    
    int operator()(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        rep(k, 30)
        if ((dep[v] - dep[u]) >> k & 1) v = par[k][v];
        if (u == v) return u;
        rrep(k, 30)
        {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        assert(par[0][u] == par[0][v]);
        return par[0][u];
    }
    
    int dist(int u, int v) {
        int w = this->operator()(u, v);
        return dep[u] + dep[v] - dep[w] * 2;
    }
    
    // path from u to v (including u, v)
    vi path(int u, int v) {
        int l = this->operator()(u, v);
        vi ul, vl;
        while (l != u) {
            ul.pb(u);
            u = par[0][u];
        }
        while (l != v) {
            vl.pb(v);
            v = par[0][v];
        }
        ul.pb(l);
        ul.insert(ul.end(), rall(vl));
        return ul;
    }
};

int main() {       
    ll n,q;
    cin >> n >> q;
    vector<vector<Edge>> g(n);
    vvi gg(n);
    rep(i,n-1){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;
        g[a].pb({b,c,d});
        g[b].pb({a,c,d});
        gg[a].pb(b);
        gg[b].pb(a);
    }
    LCA lca(gg);
    vl et;//距離を管理
    vl in(n),out(n);
    vector<vector<ll>> cet(n);//色を管理
    vvl cnt(n),sum(n);
    auto dfs=[&](auto dfs,ll v,ll p=-1)-> void {
        for(auto [u,col,cos]:g[v]){
            if(u==p) continue;
            in[u]=et.size();
            cet[col].pb(et.size());
            et.pb(cos);
            cnt[col].pb(1);
            sum[col].pb(cos);

            dfs(dfs,u,v);

            out[u]=et.size();
            cet[col].pb(et.size());
            et.pb(-cos);
            cnt[col].pb(-1);
            sum[col].pb(-cos);
        }
    };

    in[0]=et.size();
    et.pb(0);
    dfs(dfs,0);
    out[0]=et.size();
    et.pb(0);

    //print("notok");

    segtree<M> sdis(et);
    vector<segtree<M>> scnt(n),ssum(n);
    rep(i,n){
        scnt[i]=segtree<M>(cnt[i]);
        ssum[i]=segtree<M>(sum[i]);
    }
    //print("notok");
    rep(qi,q){
        ll x,y,u,v;
        cin >> x >> y >> u >> v;
        x--;u--;v--;
        if(in[u]>in[v]) swap(u,v);
        ll a=out[u],b=out[v];
        ll c=out[lca(u,v)];
        ll ans=sdis.prod(0,a)+sdis.prod(0,b)-2*sdis.prod(0,c);
        ll whea=lower_bound(all(cet[x]),a)-cet[x].begin();
        ll wheb=lower_bound(all(cet[x]),b)-cet[x].begin();
        ll whec=lower_bound(all(cet[x]),c)-cet[x].begin();
        ll pls=scnt[x].prod(0,whea)+scnt[x].prod(0,wheb)-2*scnt[x].prod(0,whec);
        pls*=y;
        ll mns=ssum[x].prod(0,whea)+ssum[x].prod(0,wheb)-2*ssum[x].prod(0,whec);
        //print(ans,pls,mns);
        cout << ans+pls-mns << endl;
    }
}