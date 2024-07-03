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

// sum floor((a * i + b) / m), i = 0 to n-1
ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }
    
    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

class dynamic_modint {
public:
    ll x;
    static int mod;
    static void set_mod(int _mod) { mod = _mod; }
    
    dynamic_modint(ll x = 0) : x((x % mod + mod) % mod) { assert(mod > 0); }
    
    static int get_mod() { return mod; }
    
    constexpr int val() const { return x; }
    
    dynamic_modint operator-() const { return dynamic_modint(-x); }
    
    dynamic_modint &operator+=(const dynamic_modint &a) {
        if ((x += a.val()) >= mod) x -= mod;
        return *this;
    }
    
    dynamic_modint &operator++() { return *this += 1; }
    
    dynamic_modint &operator-=(const dynamic_modint &a) {
        if ((x += mod - a.val()) >= mod) x -= mod;
        return *this;
    }
    
    dynamic_modint &operator--() { return *this -= 1; }
    
    dynamic_modint &operator*=(const dynamic_modint &a) {
        (x *= a.val()) %= mod;
        return *this;
    }
    
    dynamic_modint operator+(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res += a;
    }
    
    dynamic_modint operator-(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res -= a;
    }
    
    dynamic_modint operator*(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res *= a;
    }
    
    dynamic_modint pow(ll t) const {
        dynamic_modint res = 1, a(*this);
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    
    friend istream &operator>>(istream &is, dynamic_modint &a);
    
    // for prime mod
    dynamic_modint inv() const { return pow(mod - 2); }
    
    dynamic_modint &operator/=(const dynamic_modint &a) { return *this *= a.inv(); }
    
    dynamic_modint operator/(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res /= a;
    }
};

int dynamic_modint::mod = 1;//ここいじるといいかも

ostream &operator<<(ostream &os, const dynamic_modint &a) { return os << a.val(); }

bool operator==(const dynamic_modint &a, const dynamic_modint &b) { return a.val() == b.val(); }

bool operator!=(const dynamic_modint &a, const dynamic_modint &b) { return a.val() != b.val(); }

dynamic_modint &operator++(dynamic_modint &a) { return a += 1; }

dynamic_modint &operator--(dynamic_modint &a) { return a -= 1; }

using mint = dynamic_modint;

using vm = vector<mint>;
using vvm = vector<vm>;

template<typename T>
class prime {
    T n;
public:
    prime(T n) : n(n) {}
    
    map<T, int> factor_list() {//int -> T ちょっと書き換えた
        if (n == 1) return {};
        T nn = n;
        map<T, int> ret;
        for (int i = 2; (ll) i * i <= n; i++) {
            if (nn % i != 0) continue;
            int cnt = 0;
            while (nn % i == 0) {
                cnt++;
                nn /= i;
            }
            ret[i] = cnt;
        }
        if (nn != 1) ret[nn]++;
        return ret;
    }
    vi unique_factor() {
        map<int, int> m = factor_list();
        vi ret;
        for (P p : m) ret.pb(p.first);
        return ret;
    };
    
    bool is_prime() {
        auto v = factor_list();
        return v.size() == 1 && (*v.begin()).second == 1;//v[0].second==1ではないと思う
    }
    
    int count_divisor() {
        int ret = 1;
        map<int, int> fl = factor_list(n);
        for (auto p : fl) ret *= p.second + 1;
        return ret;
    }; 
    
    vector <T> enum_divisors() {
        vector <T> res;
        for (T i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                res.pb(i);
                if (n / i != i) res.pb(n / i);
            }
        }
        sort(all(res));
        return res;
    }
};

int euler_totient(int n) {
    prime<int> pr(n);
    auto fac = pr.unique_factor();
    int phi = n;
    for (int p : fac) {
        phi /= p;
        phi *= p - 1;
    }
    return phi;
}

void solve(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll mxi=(d-1)/(c-b);
    ll ue=floor_sum(mxi+1,d,c,a),sita=floor_sum(mxi+1,d,b,a);
    ll ans=ue-sita;
    ans=mxi-ans;

    //A+B*iがDの倍数になるものを引くべし
    rep(i,1){
        ll g=gcd(b,d);
        if(a%g!=0){
            break;
        }
        a/=g,b/=g,d/=g;
        dynamic_modint::set_mod(d);
        mint mst=mint(-a)*mint(b).pow(euler_totient(d)-1);
        ll st=mst.x;
        if(st==0){
            ans-=mxi/d;
            break;
        }
        if(mxi<st) break;
        ans-=(1+(mxi-st)/d);
        debug(a,b,d,st);
    }

    cout << ans << endl;
    debug(mxi,ue,sita);
}

int main() {
    ll t;
    cin >> t;
    rep(i,t) solve();
}