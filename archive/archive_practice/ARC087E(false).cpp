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

bool comp(const string &a,const string &b){
    if(a.size()!=b.size()) return a.size() < b.size();
    return a < b;
}

using ull = unsigned long long;
const ull mod = (1ull << 61) - 1;
const ull mask30 = (1ull << 30) - 1;
const ull mask31 = (1ull << 31) - 1;
const ull mask61 = mod;

ull calc_mod(ull x) {
    ull xu = x >> 61;
    ull xd = x & mask61;
    ull res = xu + xd;
    if (res >= mod) res -= mod;
    return res;
}

// a*b mod 2^61-1
ull mul(ull a,ull b) {
    ull au = a>>31;
    ull ad = a&mask31;
    ull bu = b>>31;
    ull bd = b&mask31;
    ull mid = ad*bu+au*bd;
    ull midu = mid>>30;
    ull midd = mid&mask30;
    return au*bu*2+midu+(midd<<31)+ad*bd;
}

class rolling_hash {
    ull base1;
    ull base2;
    int n;
    string s;
    vector<ull> hash1,hash2,pow1,pow2;

    void init() {
        random_device rnd;
        mt19937_64 mt(rnd());
        uniform_int_distribution<ull> dist(2,mod-2);
        base1 = dist(mt);
        base2 = dist(mt);
//        base1 = calc_mod(mt());
//        base2 = calc_mod(mt());
//        while(base1 < 2 || base1 > mod-2) base1 = calc_mod(mt());
//        while(base2 < 2 || base2 > mod-2) base2 = calc_mod(mt());
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1, 1);
        pow2.assign(n+1,1);
        rep(i,n) {
            hash1[i+1] = calc_mod(mul(hash1[i],base1)+s[i]);
            hash2[i+1] = calc_mod(mul(hash2[i],base2)+s[i]);
            pow1[i+1] = calc_mod(mul(pow1[i], base1));
            pow2[i+1] = calc_mod(mul(pow2[i], base2));
        }
    }

public:
    rolling_hash(string s):s(s),n(s.size()) {
        init();
    }
    // return hash of [l,r) of S
    pair<ull,ull> get(int l,int r) {
        ll res1 = calc_mod(hash1[r]+mod*4-mul(hash1[l], pow1[r-l]));
        ll res2 = calc_mod(hash2[r]+mod*4-mul(hash2[l], pow2[r-l]));
        return make_pair(res1,res2);
    }
    // return hash of T
    pair<ull,ull> get(string t) {
        ull ht1 = 0,ht2 = 0;
        rep(i,t.size()) {
            ht1 = calc_mod(mul(ht1,base1)+t[i]);
            ht2 = calc_mod(mul(ht2,base2)+t[i]);
        }
        return make_pair(ht1,ht2);
    }
    int count(string t) {
        if(t.size() > n) return 0;
        pair<ull,ull> ht = get(t);
        int res = 0;
        rep(i,n-t.size()+1) {
            if(get(i,i+t.size()) == ht) res++;
        }
        return res;
    }
};

ll beki(ll x){
    ll ret=1;
    while(x%2==0){
        ret*=2;
        x/=2;
    }
    return ret;
}

int main() {
    ll n,l;
    cin >> n >> l;
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    for(auto &s:v){
        for(auto &c:s){
            if(c=='0') c='a';
            else c='b';
        }
    }
    vector<rolling_hash> rh(n,rolling_hash(""));
    rep(i,n) rh[i]=rolling_hash(v[i]);
    queue<ll> que;
    rep(i,n) que.push(i);
    ll now=1;//いま何文字分みるか
    ll cnt=0;
    ll xr=0;
    while(now<=l&&(!que.empty())){
        queue<ll> que2;
        set<pair<ull,ull>> st;
        while(!que.empty()){
            ll x=que.front();
            que.pop();
            st.insert(rh[x].get(0,now));
            if(v[x].size()>now) que2.push(x);
        }

        if(st.size()%2!=0){
            ll len=l-now+1;
            xr^=beki(len);
        }

        swap(que,que2);
        now++;
    }
    //rep(i,1,17) cout << beki(i) << endl;//
    if(xr==0) fin("Bob");
    else fin("Alice");

}