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
struct i128 {
    // inner value
    __int128 val;
    
    // constructor
    constexpr i128() : val(0) {}
    constexpr i128(long long v) : val(v) {}
    i128(const string &s) : val(0) {
        parse(s);
    }
    void parse(const string &s) {
        val = 0;
        for (auto c : s) {
            if (isdigit(c)) val = val * 10 + (c - '0');
        }
        if (s[0] == '-') val *= -1;
    }
    constexpr __int128 get() const {
        return val;
    }
    constexpr i128 abs() {
        if (val < 0) return -val;
        else return val;
    }
    
    // comparison operators
    constexpr bool operator == (const i128 &r) const {
        return this->val == r.val;
    }
    constexpr bool operator != (const i128 &r) const {
        return this->val != r.val;
    }
    constexpr bool operator < (const i128 &r) const {
        return this->val < r.val;
    }
    constexpr bool operator > (const i128 &r) const {
        return this->val > r.val;
    }
    constexpr bool operator <= (const i128 &r) const {
        return this->val <= r.val;
    }
    constexpr bool operator >= (const i128 &r) const {
        return this->val >= r.val;
    }
    
    // arithmetic operators
    constexpr i128& operator += (const i128 &r) {
        val += r.val;
        return *this;
    }
    constexpr i128& operator -= (const i128 &r) {
        val -= r.val;
        return *this;
    }
    constexpr i128& operator *= (const i128 &r) {
        val *= r.val;
        return *this;
    }
    constexpr i128& operator /= (const i128 &r) {
        val /= r.val;
        return *this;
    }
    constexpr i128& operator %= (const i128 &r) {
        val %= r.val;
        return *this;
    }
    constexpr i128 operator + () const {
        return i128(*this);
    }
    constexpr i128 operator - () const {
        return i128(0) - i128(*this);
    }
    constexpr i128 operator + (const i128 &r) const {
        return i128(*this) += r;
    }
    constexpr i128 operator - (const i128 &r) const {
        return i128(*this) -= r;
    }
    constexpr i128 operator * (const i128 &r) const {
        return i128(*this) *= r;
    }
    constexpr i128 operator / (const i128 &r) const {
        return i128(*this) /= r;
    }
    constexpr i128 operator % (const i128 &r) const {
        return i128(*this) %= r;
    }
    
    // other operators
    constexpr i128& operator ++ () {
        ++val;
        return *this;
    }
    constexpr i128& operator -- () {
        --val;
        return *this;
    }
    constexpr i128 operator ++ (int) {
        i128 res = *this;
        ++*this;
        return res;
    }
    constexpr i128 operator -- (int) {
        i128 res = *this;
        --*this;
        return res;
    }
    friend istream& operator >> (istream &is, i128 &x) {
        string s;
        is >> s;
        x.parse(s);
        return is;
    }
    friend ostream& operator << (ostream &os, const i128 &x) {
        auto tmp = x.val < 0 ? -x.val : x.val;
        char buffer[128];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (x.val < 0) {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
        return os;
    }
};


using l3=i128;



int main() {
    int n,b;
    l3 k;
    cin >> n >> b >> k;

    vector<bool> used1(n,1);//使ってたら0
    vector<bool> used2(n,1);//使ってたら0

    vector<int> ans(n);

    int abssum=0;
    l3 rank=0;//0-indexed

    vector<vector<vector<l3>>> dp(n+5,vector<vector<l3>>(n+5,vector<l3>((n*n)+100,0)));

    rep(pi,n){
        l3 now=0;
        rep(can,n){
            if(!used2[can]) continue;


            int res=b-abssum-abs(can-pi);

            if(res<0) continue;

            //使うやつを仮定
            used1[pi]=0;
            used2[can]=0;

            

            rep(i,n+1)rep(j,n)rep(k,(n*n)+1) dp[i][j][k]=0;

            dp[0][0][0]=1;
            vector<int> u1sum(n+1);
            vector<int> u2sum(n+1);
            rep(i,n) u1sum[i+1]=u1sum[i]+used1[i];
            rep(i,n) u2sum[i+1]=u2sum[i]+used2[i];

            rep(i,n)rep(j,n)rep(k,(n*n)+1){
                int j2=j;//下から出てる線の数
                int j1=j-u2sum[i]+u1sum[i];//上から出てる線の数
                
                //0,0
                if(used1[i]&&used2[i]){
                    //どっちも伸ばす
                    dp[i+1][j+1][k+j1+j2+2]+=dp[i][j][k];
                    //どっちもつなげる
                    if(j1!=0&&j2!=0) dp[i+1][j-1][k+j1+j2-2]+=dp[i][j][k]*j1*j2;
                    //片方伸ばす1
                    if(j1!=0) dp[i+1][j][k+j1+j2]+=dp[i][j][k]*j1;
                    //片方伸ばす2
                    if(j2!=0) dp[i+1][j][k+j1+j2]+=dp[i][j][k]*j2;
                    //それ同士をつなげる
                    dp[i+1][j][k+j1+j2]+=dp[i][j][k];
                }
                if(!used1[i]&&used2[i]){
                    //現存とつなぐ
                    if(j1!=0) dp[i+1][j][k+j1+j2-1]+=dp[i][j][k]*j1;
                    //上に伸ばす
                    dp[i+1][j+1][k+j1+j2+1]+=dp[i][j][k];
                }
                if(used1[i]&&!used2[i]){
                    //現存とつなぐ
                    if(j2!=0) dp[i+1][j-1][k+j1+j2-1]+=dp[i][j][k]*j2;
                    //上に伸ばす
                    dp[i+1][j][k+j1+j2+1]+=dp[i][j][k];
                }
                if(!used1[i]&&!used2[i]){
                    dp[i+1][j][k+j1+j2]+=dp[i][j][k];
                }
                
            }

            l3 pls=dp[n][0][res];


            if(rank+now+pls>=k){
                ans[pi]=can;
                used2[can]=0;
                abssum+=abs(pi-can);
                rank+=now;
                break;
            }
            else{
                now+=pls;
                //仮定を戻す
                used1[pi]=1;
                used2[can]=1;
            }
        }

        
    }

    rep(i,n) cout << ans[i]+1 << " ";
    cout << endl;
}