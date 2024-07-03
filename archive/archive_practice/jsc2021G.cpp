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


template<int mod>
class modint {
    ll x;
public:
    constexpr modint(ll x = 0) : x((x % mod + mod) % mod) {}
    
    static constexpr int get_mod() { return mod; }
    
    constexpr int val() const { return x; }
    
    constexpr modint operator-() const { return modint(-x); }
    
    constexpr modint &operator+=(const modint &a) {
        if ((x += a.val()) >= mod) x -= mod;
        return *this;
    }
    
    constexpr modint &operator++() { return *this += 1; }
    
    constexpr modint &operator-=(const modint &a) {
        if ((x += mod - a.val()) >= mod) x -= mod;
        return *this;
    }
    
    constexpr modint &operator--() { return *this -= 1; }
    
    constexpr modint
    &
    
    operator*=(const modint &a) {
        (x *= a.val()) %= mod;
        return *this;
    }
    
    constexpr modint
    
    operator+(const modint &a) const {
        modint res(*this);
        return res += a;
    }
    
    constexpr modint
    
    operator-(const modint &a) const {
        modint res(*this);
        return res -= a;
    }
    
    constexpr modint
    
    operator*(const modint &a) const {
        modint res(*this);
        return res *= a;
    }
    
    constexpr modint
    pow(ll
    t) const {
        modint res = 1, a(*this);
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    
    template<int m>
    friend istream &operator>>(istream &, modint<m> &);
    
    // for prime mod
    constexpr modint
    
    inv() const { return pow(mod - 2); }
    
    constexpr modint
    &
    
    operator/=(const modint &a) { return *this *= a.inv(); }
    
    constexpr modint
    
    operator/(const modint &a) const {
        modint res(*this);
        return res /= a;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

template<int mod>
istream &operator>>(istream &is, modint<mod> &a) { return is >> a.x; }

template<int mod>
constexpr ostream
&
operator<<(ostream
&os,
const modint<mod> &a
) {
return os << a.

val();

}

template<int mod>
constexpr bool operator==(const modint<mod> &a, const modint<mod> &b) { return a.val() == b.val(); }

template<int mod>
constexpr bool operator!=(const modint<mod> &a, const modint<mod> &b) { return a.val() != b.val(); }

template<int mod>
constexpr modint<mod>
&
operator++(modint<mod>
&a) {
return a += 1; }

template<int mod>
constexpr modint<mod>
&
operator--(modint<mod>
&a) {
return a -= 1; }

using mint = modint1000000007;

using vm = vector<mint>;
using vvm = vector<vm>;

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

template<typename T>
class matrix : public vector<vector < T>>

{
public:
using vector<vector < T>>::vector;

constexpr int get_h() const { return this->size(); }

constexpr int get_w() const { return (get_h() ? (*this)[0].size() : 0); }

constexpr matrix
&

operator+=(const matrix &a) {
    rep(i, get_h())
    rep(j, get_w())(*this)[i][j] += a[i][j];
    return *this;
}

constexpr matrix
&

operator*=(const int &k) {
    rep(i, get_h())
    rep(j, get_w())(*this)[i][j] *= k;
    return *this;
}

constexpr matrix
&

operator-=(const matrix &a) {
    *this += a * (-1);
    return *this;
}

constexpr matrix

operator+(const matrix &a) const { return res(*this) += a; }

constexpr matrix

operator*(const int &k) const { return res(*this) *= k; }

constexpr matrix

operator-(const matrix &a) const { return res(*this) -= a; }

constexpr matrix

operator*(const matrix &a) const {
    int h = get_h(), w = get_w(), ah = a.get_h(), aw = a.get_w();
    assert(w == ah);
    matrix res(h, vector<T>(aw));
    rep(i, h)
    rep(j, w)
    rep(k, aw)
    res[i][k] += (*this)[i][j] * a[j][k];
    return res;
}

constexpr matrix
&

operator*=(const matrix &a) { return *this = *this * a; }

constexpr matrix
pow(ll
t) const {
int h = get_h(), w = get_w();
assert(h
== w);
matrix res(h, vector<T>(w)), a(*this);
rep(i, get_h()
) res[i][i] = 1;
while (t > 0) {
if (t & 1) res *=
a;
t >>= 1;
a *=
a;
}
return
res;
}
};

const double eps = 1e-9;

template<class T>
T determinant(matrix <T> a) {
    assert(a.get_h() == a.get_w());
    int n = a.get_h();
    T res = 1;
    rep(col, n)
    {
        int pivot = -1;
        rep(row, col, n)
        {
            if (a[row][col] != T(0)) pivot = row;
        }
        if (pivot == -1) return 0;
        if (pivot != col) {
            res *= -1;
            swap(a[pivot], a[col]);
        }
        res *= a[col][col];
        rep(row, n)
        {
            if (row == col) continue;
            if (a[row][col] == T(0)) continue;
            T fac = a[row][col] / a[col][col];
            rep(col2, n)
            a[row][col2] -= a[col][col2] * fac;
        }
    }
    return res;
}

template<>
double determinant(matrix<double> a) {
    assert(a.get_h() == a.get_w());
    int n = a.get_h();
    double res = 1;
    rep(col, n)
    {
        int pivot = -1;
        double mx = eps;
        rep(row, col, n)
        {
            if (abs(a[row][col]) > mx) {
                mx = abs(a[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1) return 0;
        if (pivot != col) {
            res *= -1;
            swap(a[pivot], a[col]);
        }
        res *= a[col][col];
        rep(row, n)
        {
            if (row == col) continue;
            if (abs(a[row][col]) <= eps) continue;
            double fac = a[row][col] / a[col][col];
            rep(col2, n)
            a[row][col2] -= a[col][col2] * fac;
        }
    }
    return res;
}

using mat = matrix<mint>;



int main() {
    ll n;
    cin >> n;
    vvl v(n,vl(n));
    rep(i,n)rep(j,n) cin >> v[i][j];

    dsu uf(n);

    rep(i,n)rep(j,i+1,n){
        if(v[i][j]==1){
            if(uf.same(i,j)){
                fin(0);
            }
            uf.merge(i,j);
        }
    }

    map<ll,ll> mp;
    ll id=0;
    rep(i,n){
        if(uf.is_leader(i)){
            mp[i]=id;
            id++;
        }
    }

    mat mt(id,vm(id));

    rep(i,n)rep(j,n){
        if(v[i][j]==-1&&(!uf.same(i,j))){
            mt[mp[uf.leader(i)]][mp[uf.leader(j)]]-=1;
        }
    }
    rep(i,id)rep(j,id){
        if(i!=j) mt[i][i]-=mt[i][j];
    }

    debug(mt);

    mat mt2(id-1,vm(id-1));

    rep(i,id-1)rep(j,id-1) mt2[i][j]=mt[i][j];

    cout << determinant(mt2) << endl;

}