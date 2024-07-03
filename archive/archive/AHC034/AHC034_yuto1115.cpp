#include <bits/stdc++.h>
#include <cassert>
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
#define ppc(x) popcount((unsigned long long) x)
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
using vlp = vector<LP>;
using vvlp = vector<vlp>;
template<class T>
using PQ = priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>;

template<class S, class T>
istream &operator>>(istream &is, pair<S, T> &p) { return is >> p.first >> p.second; }

template<class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << '{' << p.first << ", " << p.second << '}'; }

template<class S, class T, class U>
istream &operator>>(istream &is, tuple<S, T, U> &t) { return is >> get<0>(t) >> get<1>(t) >> get<2>(t); }

template<class S, class T, class U>
ostream &operator<<(ostream &os, const tuple<S, T, U> &t) {
    return os << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '}';
}

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t: v) { is >> t; }
    return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const deque<T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T>
ostream &operator<<(ostream &os, const multiset<T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &mp) {
    os << '{';
    auto it = mp.begin();
    while (it != mp.end()) {
        os << (it == mp.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T>
void vecout(const vector<T> &v, char div = '\n') {
    rep(i, v.size()) cout << v[i] << (i == int(v.size() - 1) ? '\n' : div);
}

template<class T>
bool constexpr chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool constexpr chmax(T &a, T b) {
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
vector<T> &operator+=(vector<T> &v, T x) {
    for (T &t: v) t += x;
    return v;
}

template<class T>
vector<T> &operator-=(vector<T> &v, T x) {
    for (T &t: v) t -= x;
    return v;
}

template<class T>
vector<T> &operator*=(vector<T> &v, T x) {
    for (T &t: v) t *= x;
    return v;
}

template<class T>
vector<T> &operator/=(vector<T> &v, T x) {
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
void rearrange(const vi &ord, vector<T> &head, Tail &...tail) {
    assert(ord.size() == head.size());
    vector<T> ori = head;
    rep(i, ord.size()) head[i] = ori[ord[i]];
    rearrange(ord, tail...);
}

template<class T, class... Tail>
void sort_by(vector<T> &head, Tail &... tail) {
    vi ord(head.size());
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return head[i] < head[j]; });
    rearrange(ord, head, tail...);
}

bool in_rect(int i, int j, int h, int w) {
    return 0 <= i and i < h and 0 <= j and j < w;
}

template<class T, class S>
vector<T> cumsum(const vector<S> &v, bool shift_one = true) {
    int n = v.size();
    vector<T> res;
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
vector<vector<pair<int, T>>> weighted_graph(int n, int m, bool directed = false, int origin = 1) {
    vector<vector<pair<int, T>>> G(n);
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

auto start = chrono::system_clock::now();

double get_time() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() / 1000.;
}

const int n = 20;
int base = 0;

constexpr int dist(int i, int j) {
    return abs(i % n - j % n) + abs(i / n - j / n);
}

struct S {
    array<int, n * n> h;
    array<int, n> r_cnt, c_cnt;
    int l, r, u, d;
    int pos;
    int cost;
    int rem, dump, done;
    shared_ptr<S> pre;

    void shrink() {
        while (l < r and !c_cnt[l]) ++l;
        while (l < r and !c_cnt[r - 1]) --r;
        while (u < d and !r_cnt[u]) ++u;
        while (u < d and !r_cnt[d - 1]) --d;
    }

    double score() {
        double res = cost + rem * 60 + dump * 40;
        res += (r - l + d - u) * 200;
        return res;
    }

    int cnt_zero() {
        int cnt = 0;
        rep(i, n * n) cnt += (h[i] == 0);
        return cnt;
    }

    void dbg() {
        debug(pos / n, pos % n, l, r, u, d, cost, rem, dump, done, score());
        debug(vi(all(r_cnt)));
        debug(vi(all(c_cnt)));
    }

    bool finished() {
        return !rem and !dump;
    }
};

vector<shared_ptr<S>> next_states(const shared_ptr<S> &s) {
//    cout << "next_states" << endl;
//    s->dbg();
//    vi po, ne;
//    rep(i, n * n) {
//        if (s->h[i] > 0) po.pb(i);
//        if (s->h[i] < 0) ne.pb(i);
//    }
//    int sz = 10;
//    if (po.size() > sz) {
//        nth_element(po.begin(),
//                    po.begin() + sz,
//                    po.end(),
//                    [&](int a, int b) { return dist(a, s->pos) < dist(b, s->pos); });
//    }
//    if (ne.size() > sz) {
//        nth_element(ne.begin(),
//                    ne.begin() + sz,
//                    ne.end(),
//                    [&](int a, int b) { return dist(a, s->pos) < dist(b, s->pos); });
//    }
//    vi v = po;
//    v.insert(v.end(), all(ne));
    vector<shared_ptr<S>> res;
    res.reserve(n * n);
    int pi = s->pos / n;
    int pj = s->pos % n;
    int po = 0, ng = 0;
    rep(x, max(pi - 5, 0), min(pi + 6, n)) {
        rep(y, max(pj - 5, 0), min(pj + 6, n)) {
            int i = x * n + y;
            if (!s->h[i]) continue;
            shared_ptr<S> now(new S(*s));
            now->pos = i;
            now->pre = s;
            now->cost += (100 + now->dump) * dist(s->pos, i);
            if (s->h[i] > 0) {
                ++po;
                now->rem -= now->h[i];
                now->dump += now->h[i];
                now->h[i] = 0;
                --now->r_cnt[x];
                --now->c_cnt[y];
                now->shrink();
                res.emplace_back(now);
            } else if (-now->h[i] <= now->dump) {
                ++ng;
                int am = min(now->dump, -now->h[i]);
                now->dump -= am;
                now->done += am;
                now->h[i] += am;
                --now->r_cnt[x];
                --now->c_cnt[y];
                now->shrink();
                res.emplace_back(now);
            }
        }
    }
    if (min(po, ng) >= 3) return res;
    rep(x, s->u, s->d) rep(y, s->l, s->r) {
            int i = x * n + y;
            if (!s->h[i]) continue;
            shared_ptr<S> now(new S(*s));
            now->pos = i;
            now->pre = s;
            now->cost += (100 + now->dump) * dist(s->pos, i);
            if (s->h[i] > 0) {
                now->rem -= now->h[i];
                now->dump += now->h[i];
                now->h[i] = 0;
                --now->r_cnt[x];
                --now->c_cnt[y];
                now->shrink();
                res.emplace_back(now);
            } else if (-now->h[i] <= now->dump) {
                int am = min(now->dump, -now->h[i]);
                now->dump -= am;
                now->done += am;
                now->h[i] += am;
                --now->r_cnt[x];
                --now->c_cnt[y];
                now->shrink();
                res.emplace_back(now);
            }
        }
    return res;
}

vector<string> mv(int from, int to) {
    int si = from / n, sj = from % n;
    int ti = to / n, tj = to % n;
    vector<string> res;
    while (si < ti) res.pb("D"), ++si;
    while (si > ti) res.pb("U"), --si;
    while (sj < tj) res.pb("R"), ++sj;
    while (sj > tj) res.pb("L"), --sj;
    return res;
}

int main() {
    INT(_);
    array<int, n * n> h;
    array<int, n> r_cnt, c_cnt;
    rep(i, n) r_cnt[i] = c_cnt[i] = 0;
    rep(i, n * n) {
        scan(h[i]);
        base += abs(h[i]);
        if (h[i]) ++r_cnt[i / n], ++c_cnt[i % n];
    }
    debug(base);
    shared_ptr<S> init;
    {
        int l = 0, r = n, u = 0, d = n;
        while (l < r and !c_cnt[l]) ++l;
        while (l < r and !c_cnt[r - 1]) --r;
        while (u < d and !r_cnt[u]) ++u;
        while (u < d and !r_cnt[d - 1]) --d;
        init = shared_ptr<S>(new S{h, r_cnt, c_cnt, l, r, u, d, 0, 0, base / 2, 0, 0});
    }
    int max_turn = n * n * 2;
    int width = 120;
    vector<shared_ptr<S>> states[max_turn];
    states[0].pb(init);
    shared_ptr<S> best;
    int min_cost = 1e9;
    rep(i, max_turn - 1) {
        if (SZ(states[i]) > width) {
            nth_element(states[i].begin(),
                        states[i].begin() + width,
                        states[i].end(),
                        [](auto a, auto b) { return a->score() < b->score(); });
            states[i].resize(width);
        }
        debug(i, get_time());
        vector<vector<shared_ptr<S>>> v(n * n);
        rep(j, n * n) v[j].reserve(width);
        for (auto s: states[i]) {
            s->dbg();
            auto nx = next_states(s);
            for (auto ns: nx) {
                if (ns->finished()) {
                    if (chmin(min_cost, ns->cost)) best = ns;
                } else {
                    v[ns->pos].push_back(ns);
                }
            }
        }
        states[i + 1].reserve(n * n * 5);
        rep(j, n * n) {
            sort(all(v[j]), [](auto a, auto b) { return a->score() < b->score(); });
            rep(k, min(SZ(v[j]), 5)) states[i + 1].pb(v[j][k]);
        }
    }
    assert(best);
    best->dbg();
    vector<string> ans;
    while (best != init) {
        auto pre = best->pre;
        int d = best->h[best->pos] - pre->h[best->pos];
        if (d > 0) ans.pb("-" + to_string(d));
        else if (d < 0) ans.pb("+" + to_string(-d));
        auto v = mv(pre->pos, best->pos);
        ans.insert(ans.end(), rall(v));
        best = pre;
    }
    REV(ans);
    vecout(ans);
    cerr << (double) base / min_cost << endl;
    cerr << get_time() << endl;
}