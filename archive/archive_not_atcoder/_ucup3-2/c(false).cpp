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

template<class Cap, class Cost>
class MCF {
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
        
        _edge(int to, int rev, Cap cap, Cost cost) : to(to), rev(rev), cap(cap), cost(cost) {}
    };
    
    int n;
    vp pos;
    vector <vector<_edge>> G;

public:
    explicit MCF(int n) : n(n), G(n) {}
    
    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        assert(from != to);
        pos.eb(from, G[from].size());
        G[from].eb(to, G[to].size(), cap, cost);
        G[to].eb(from, G[from].size() - 1, 0, -cost);
        return pos.size() - 1;
    }
    
    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
        
        edge(int from, int to, Cap cap, Cap flow, Cost cost) : from(from), to(to), cap(cap), flow(flow), cost(cost) {}
    };
    
    edge get_edge(int i) {
        assert(0 <= i && i < int(pos.size()));
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return edge(pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost);
    }
    
    vector <edge> edges() {
        int m = pos.size();
        vector <edge> res(m);
        rep(i, m)
        res[i] = get_edge(i);
        return res;
    }
    
    pair <Cap, Cost> flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    
    pair <Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    
    vector <pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, numeric_limits<Cap>::max());
    }
    
    // this must not be called more than once
    // O(F (E + V) log V)
    vector <pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s and s < n);
        assert(0 <= t and t < n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all _edge
        vector <Cost> dual(n, 0), dist(n);
        vi pv(n), pe(n);
        vb seen(n);
        auto dual_ref = [&]() -> bool {
            fill(all(dist), numeric_limits<Cost>::max());
            fill(all(pv), -1);
            fill(all(pe), -1);
            fill(all(seen), false);
            priority_queue < pair < Cost, int >, vector < pair < Cost, int >>, greater < pair < Cost, int>>> q;
            dist[s] = 0;
            q.emplace(0, s);
            while (not q.empty()) {
                int u = q.top().second;
                q.pop();
                if (seen[u]) continue;
                seen[u] = true;
                if (u == t) break;
                // dist[u] = shortest(s, u) + dual[s] - dual[u]
                // dist[u] >= 0 (all reduced cost are positive)
                // dist[u] <= (n-1)C
                rep(i, G[u].size())
                {
                    auto e = G[u][i];
                    if (seen[e.to] or !e.cap) continue;
                    // |-dual[e.to] + dual[u]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual[e.to] + dual[u];
                    if (chmin(dist[e.to], dist[u] + cost)) {
                        pv[e.to] = u;
                        pe[e.to] = i;
                        q.emplace(dist[e.to], e.to);
                    }
                }
            }
            if (!seen[t]) {
                return false;
            }
            
            rep(u, n)
            {
                if (!seen[u]) continue;
                // dual[u] = dual[u] - dist[t] + dist[u]
                //         = dual[u] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, u) + dual[s] - dual[u])
                //         = - shortest(s, t) + dual[t] + shortest(s, v)
                //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
                dual[u] -= dist[t] - dist[u];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        vector <pair<Cap, Cost>> res;
        res.eb(flow, cost);
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int u = t; u != s; u = pv[u]) {
                chmin(c, G[pv[u]][pe[u]].cap);
            }
            for (int u = t; u != s; u = pv[u]) {
                auto &e = G[pv[u]][pe[u]];
                e.cap -= c;
                G[u][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                res.pop_back();
            }
            res.eb(flow, cost);
            prev_cost_per_flow = d;
        }
        return res;
    }
    
};

ll n;

ll id(ll x,ll y){
    return x*n+y;
}

void solve(){

    cin >> n;
    vvl v(n,vl(n));
    rep(i,n)rep(j,n) cin >> v[i][j];
    MCF<ll,ll> mcf(n*n+15);
    ll s=n*n,g=n*n+1;
    vl is={g+1,g+2,g+3,g+4};
    rep(i,n/2+1)rep(j,n/2+1){
        mcf.add_edge(is[0],id(i,j),1,0);
    }
    rep(i,n/2+1)rep(j,n/2,n){
        mcf.add_edge(is[1],id(i,j),1,0);
    }

    rep(i,n/2,n)rep(j,n/2+1){
        mcf.add_edge(is[2],id(i,j),1,0);
    }
    rep(i,n/2,n)rep(j,n){
        mcf.add_edge(is[3],id(i,j),1,0);
    }

    rep(i,4) mcf.add_edge(s,is[i],1,0);
    rep(i,n)rep(j,n){
        mcf.add_edge(id(i,j),g,4,v[i][j]);
    }

    cout << mcf.slope(s,g,4) << endl;

}

int main() {
    ll t;
    cin >> t;
    rep(i,t) solve();   
}