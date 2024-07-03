#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(),x.rend()
#define SUM(x) accumulate(all(x),0LL)
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
#define popcount(x) __builtin_popcountll(x)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define Fi first //pairの一つ目の要素  //遅延セグ木使うときは注意
#define Se second //pairの二つ目の要素  //遅延セグ木使うときは注意
#define PF push_front
#define PB push_back
#define EF emplace_front
#define EB emplace_back
#define PPF pop_front
#define PPB pop_back
//V,Pは大文字i,l,bは小文字
using ll = long long;
using ld = long double;
using Vl = vector<ll>;
using Vi = vector<int>;
using VVi = vector<Vi>;
using VVVi = vector<VVi>;
using VVl = vector<Vl>;
using VVVl = vector<VVl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pl = pair<ll, ll>;
using Vs = vector<string>;
template<class T>
using PQ = priority_queue<T>;
template<class T>
using PQ = priority_queue<T,vector<T>,greater<T>>;
const ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

template<class T>
void print(const T &t) { cout << t << '\n'; }

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

void solve() {

}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}
