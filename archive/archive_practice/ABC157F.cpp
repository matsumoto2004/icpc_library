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

const double eps = 1e-9;
const double PI = acos(-1);

int sgn(double a) { return a < -eps ? -1 : (a > eps ? 1 : 0); }

double to_rad(double deg) { return deg * PI / 180; }

double to_deg(double rad) { return rad * 180 / PI; }

struct point {
    double x, y;
    
    point(double x = 0, double y = 0) : x(x), y(y) {}
    
    point operator+(const point &p) const { return {x + p.x, y + p.y}; }
    
    point operator-(const point &p) const { return {x - p.x, y - p.y}; }
    
    point operator*(double a) const { return {x * a, y * a}; }
    
    point operator*(const point &p) const { return point(x * p.x - y * p.y, x * p.y + y * p.x); }
    
    point operator/(double a) const { return {x / a, y / a}; }
    
    point operator-() const { return *this * (-1); }
    
    bool operator==(const point &p) const { return !sgn(x - p.x) && !sgn(y - p.y); }
    
    bool operator!=(const point &p) const { return !(*this == p); }
    
    bool operator<(const point &p) const { return sgn(x - p.x) ? x < p.x : y < p.y; }
    
    bool operator>(const point &p) const { return sgn(x - p.x) ? x > p.x : y > p.y; }
    
    double norm() const { return x * x + y * y; }
    
    double abs() const { return sqrt(norm()); }
    
    point rot(double rad) const { return point(cos(rad) * x - sin(rad) * y, sin(rad) * x + cos(rad) * y); }
    
    point rot90() const { return point(-y, x); }
    
    double arg() const {
        double res = atan2(y, x);
        if (sgn(res) < 0) res += 2 * PI;
        return res;
    }
};

istream &operator>>(istream &is, point &p) { return is >> p.x >> p.y; }

ostream &operator<<(ostream &os, const point &p) { return os << '(' << p.x << "," << p.y << ')'; }

double dist(const point &a, const point &b) { return (a - b).abs(); }

double dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }

double cross(const point &a, const point &b) { return a.x * b.y - a.y * b.x; }

point mid(const point &a, const point &b) { return (a + b) / 2; }

int ccw(const point &a, const point &b, const point &c) {
    // 1 -> c is upper than line(a,b)
    // -1 -> c is lower than line(a,b)
    // 2 -> in order [a,b,c]
    // -2 -> in order [c,a,b]
    // 0 -> in order [a,c,b]
    point nb = b - a, nc = c - a;
    if (sgn(cross(nb, nc))) return sgn(cross(nb, nc));
    if (sgn(dot(nb, nc)) < 0) return -2;
    if (sgn(nc.abs() - nb.abs()) > 0) return 2;
    return 0;
}

struct line {
    point a, b;
    
    line(point a = point(), point b = point()) : a(a), b(b) {}
    
    bool online(const point &p) const { return abs(ccw(a, b, p)) != 1; }
};

ostream &operator<<(ostream &os, const line &l) { return os << '{' << l.a << ',' << l.b << '}'; }

struct segment {
    point a, b;
    
    segment(point a = point(), point b = point()) : a(a), b(b) {}
    
    bool online(const point &p) const { return !ccw(a, b, p); }
    
    line vertical_bisector() const { return line(mid(a, b), mid(a, b) + (b - a).rot90()); }
};

ostream &operator<<(ostream &os, const segment &l) { return os << '{' << l.a << ',' << l.b << '}'; }

bool vertical(const line &l, const line &m) { return !sgn(dot(l.a - l.b, m.a - m.b)); }

bool vertical(const segment &l, const segment &m) { return !sgn(dot(l.a - l.b, m.a - m.b)); }

bool parallel(const line &l, const line &m) { return !sgn(cross(l.a - l.b, m.a - m.b)); }

bool parallel(const segment &l, const segment &m) { return !sgn(cross(l.a - l.b, m.a - m.b)); }

bool operator==(const line &l, const line &m) { return parallel(l, m) && l.online(m.a); }

bool operator!=(const line &l, const line &m) { return !(l == m); }

bool operator==(const segment &l, const segment &m) { return l.a == m.a && l.b == m.b || l.a == m.b && l.b == m.a; }

bool operator!=(const segment &l, const segment &m) { return !(l == m); }

// intersect at one point
bool intersect(const line &l, const line &m) { return !parallel(l, m); }

bool intersect(const line &l, const segment &m) {
    return sgn(cross(l.b - l.a, m.a - l.a) * cross(l.b - l.a, m.b - l.a)) <= 0;
}

bool intersect(const segment &l, const segment &m) {
    return ccw(l.a, l.b, m.a) * ccw(l.a, l.b, m.b) <= 0 &&
           ccw(m.a, m.b, l.a) * ccw(m.a, m.b, l.b) <= 0;
}

point intersection(const line &l, const line &m) {
    assert(intersect(l, m));
    return l.a + (l.b - l.a) * cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, l.b - l.a);
}

point intersection(const line &l, const segment &m) {
    assert(intersect(l, m));
    return l.a + (l.b - l.a) * cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, l.b - l.a);
}

point intersection(const segment &l, const segment &m) {
    assert(intersect(l, m));
    return l.a + (l.b - l.a) * cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, l.b - l.a);
}

double dist(const line &l, const point &p) { return abs(cross(l.b - l.a, p - l.a)) / (l.b - l.a).abs(); }

double dist(const segment &l, const point &p) {
    if (sgn(dot(l.b - l.a, p - l.a)) < 0) return dist(p, l.a);
    if (sgn(dot(l.a - l.b, p - l.b)) < 0) return dist(p, l.b);
    return dist(line(l.a, l.b), p);
}

double dist(const line &l, const line &m) {
    if (parallel(l, m)) return dist(l, m.a);
    return 0;
}

double dist(const line &l, const segment &m) {
    if (intersect(l, m)) return 0;
    return min(dist(l, m.a), dist(l, m.b));
}

double dist(const segment &l, const segment &m) {
    if (intersect(l, m)) return 0;
    return min({dist(l, m.a), dist(l, m.b), dist(m, l.a), dist(m, l.b)});
}

point projection(const line &l, const point &p) {
    double d = dot(p - l.a, l.b - l.a) / (l.b - l.a).norm();
    return l.a + (l.b - l.a) * d;
}

point circumcenter(const point &a, const point &b, const point &c) {
    return intersection(segment(a, b).vertical_bisector(), segment(b, c).vertical_bisector());
}

struct circle {
    point o;
    double r;
    
    circle(point o = point(), double r = 0) : o(o), r(r) {}
    
    bool inside(const point &p) const { return sgn(r - dist(o, p)) >= 0; }
    
    double area() const { return r * r * PI; }
};

ostream &operator<<(ostream &os, const circle &c) { return os << '{' << c.o << ',' << c.r << '}'; }

bool intersect(const circle &c, const line &l) { return sgn(dist(l, c.o) - c.r) <= 0; }

bool intersect(const circle &c, const segment &l) {
    if (sgn(dist(l, c.o) - c.r) > 0) return false;
    return sgn(max((c.o - l.a).abs(), (c.o - l.b).abs()) - c.r) >= 0;
}

vector <point> intersection(const circle &c, const line &l) {
    point p = projection(l, c.o);
    if (!intersect(c, l)) return {};
    if (sgn(dist(l, c.o) - c.r) == 0) return {p};
    point e = (l.b - l.a) / (l.b - l.a).abs();
    double d = sqrt(c.r * c.r - (p - c.o).norm());
    return {p - e * d, p + e * d};
}

vector <point> intersection(const circle &c, const segment &l) {
    auto v = intersection(c, line(l.a, l.b));
    vector <point> ret;
    for (point p : v) if (l.online(p)) ret.pb(p);
    return ret;
}

vector <point> intersection(const circle &a, const circle &b) {
    double d = dist(a.o, b.o);
    if (!sgn(a.r + b.r - d)) return {a.o + (b.o - a.o) * a.r / d};
    if (!sgn(a.r - b.r - d)) return {a.o + (b.o - a.o) * a.r / d};
    if (!sgn(b.r - a.r - d)) return {b.o + (a.o - b.o) * b.r / d};
    if (sgn(abs(a.r - b.r) - d) > 0 || sgn(a.r + b.r - d) < 0) return {};
    double x = (a.r * a.r + d * d - b.r * b.r) / (2 * d);
    double y = sqrt(a.r * a.r - x * x);
    point p = (b.o - a.o).rot90() * y / d;
    point to_mid = a.o + (b.o - a.o) * x / d;
    return {to_mid - p, to_mid + p};
}

vector <circle> circle_with_two_points_and_radius(const point &a, const point &b, const double &r) {
    if (sgn(dist(a, b) - 2 * r) > 0) return {};
    circle A(a, r), B(b, r);
    auto v = intersection(A, B);
    vector <circle> ret;
    for (point p : v) ret.eb(p, r);
    return ret;
};

vector <point> tangent_point(const circle &c, const point &p) {
    int s = sgn(dist(c.o, p) - c.r);
    if (s < 0) return {};
    if (s == 0) return {p};
    double d = (p - c.o).norm() - c.r * c.r;
    return intersection(c, circle(p, sqrt(d)));
}

vector <line> tangent_line(const circle &c, const point &p) {
    vector <point> v = tangent_point(c, p);
    if (v.empty()) return {};
    if (v.size() == 1) return {line(p, p + (c.o - p).rot90())};
    vector <line> res;
    for (auto tp : v) res.eb(p, tp);
    return res;
}

vector <line> tangent_line(const circle &a, const circle &b) {
    if (sgn(a.r - b.r) < 0) return tangent_line(b, a);
    double ar = a.r, br = b.r, d = dist(a.o, b.o);
    if (sgn(d - (ar - br)) < 0) return {};
    else if (sgn(d - (ar - br)) == 0) {
        point p = (a.o * (-br) + b.o * ar) / (ar - br);
        return {line(p, p + (a.o - p).rot90())};
    } else {
        vector <line> res;
        {
            double theta = acos((ar - br) / d);
            {
                point p = a.o + ((b.o - a.o) / d * ar).rot(-theta);
                res.eb(p, p + (a.o - p).rot90());
            }
            {
                point p = a.o + ((b.o - a.o) / d * ar).rot(theta);
                res.eb(p, p + (a.o - p).rot90());
            }
        }
        if (sgn(d - (ar + br)) >= 0) {
            point p = (a.o * br + b.o * ar) / (ar + br);
            vector <line> lines = tangent_line(a, p);
            for (line l : lines) res.pb(l);
        }
        return res;
    }
}

vector <point> convex_hull(vector <point> v) {
    sort(all(v));
    int n = v.size(), k = 0;
    vector <point> res(2 * n);
    for (int i = 0; i < n; res[k++] = v[i++])
        while (k > 1 && ccw(res[k - 2], res[k - 1], v[i]) <= 0) k--;
    for (int i = n - 2, t = k; i >= 0; res[k++] = v[i--])
        while (k > t && ccw(res[k - 2], res[k - 1], v[i]) <= 0) k--;
    res.resize(k - 1);
    return res;
}





int main() {
    ll n,k;
    cin >> n >> k;
    vector<double> vx(n),vy(n),vc(n);
    rep(i,n) cin >> vx[i] >> vy[i] >> vc[i];
    
    double ok=1e9,ng=0;
    rep(i,1000){
        double mid=(ok+ng)/2;
        vector<point> vp;
        vector<circle> vcir(n);
        rep(i,n){
            vcir[i]={{vx[i],vy[i]},mid/vc[i]};
        }
        rep(i,n)rep(j,i+1,n){
            for(auto p:intersection(vcir[i],vcir[j])){
                vp.pb(p);
            }
        }
        rep(i,n) vp.pb({vx[i],vy[i]});
        bool isok=false;
        for(auto p:vp){
            ll cnt=0;
            rep(i,n){
                if(dist(p,point{vx[i],vy[i]})<=mid/vc[i]+eps){
                    cnt++;
                }
            }
            if(cnt>=k) isok=true;
        }
        if(isok) ok=mid;
        else ng=mid;
    }
    cout << ok << endl;
}