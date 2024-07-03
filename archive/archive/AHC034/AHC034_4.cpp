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

class TimeKeeper {
 private:
  std::chrono::high_resolution_clock::time_point start_time_;
  std::chrono::high_resolution_clock::time_point before_time_;
  int64_t time_threshold_;
  int64_t turn_threshold_;

 public:
  TimeKeeper(const int64_t &time_threshold)
      : start_time_(std::chrono::high_resolution_clock::now()),
        time_threshold_(time_threshold){
    before_time_ = start_time_;
  }

  // 各ターンに割り振られた制限時間を超過したか判定する。
  bool update() {
    auto now = std::chrono::high_resolution_clock::now();
    auto passed_time_=std::chrono::duration_cast<std::chrono::milliseconds>(now-start_time_);
    auto time_diff=std::chrono::duration_cast<std::chrono::milliseconds>(now-before_time_);
    auto expected_time_= passed_time_+time_diff;
    before_time_=now;
    return  expected_time_.count() <= time_threshold_;
  }

};

std::random_device rd;
std::mt19937 gen(rd());
int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int main() {
    TimeKeeper tk(1990);
    ll n;
    cin >> n;
    vvl v(n,vl(n));
    rep(i,n)rep(j,n) cin >> v[i][j];
    ll base=0;
    ll diff_orig=0;
    vl sum1_orig(n),sum2_orig(n);
    rep(i,n)rep(j,n) base+=abs(v[i][j]);
    rep(i,n)rep(j,n){
        if(v[i][j]!=0) diff_orig+=100*abs(v[i][j])+10000;
    }
    rep(i,n)rep(j,n){
        sum1_orig[i]+=v[i][j];
        sum2_orig[j]+=v[i][j];
    }

    vvl board=v;
    vvl seen_time(n,vl(n));
    int x=0,y=0;
    ll cost=0;
    ll diff=0;
    vl sum1=sum1_orig,sum2=sum2_orig;
    int turn=0,turn_threshold=100000;
    ll have=0;
    vl ans_type;
    vl ans_num;
    int prev_move=-1;

    auto get=[&](ll d)  -> void {
        if(turn>turn_threshold) return;

        diff-=abs(board[x][y])*100;
        board[x][y]-=d;
        have+=d;
        cost+=d;
        diff+=abs(board[x][y])*100;
        if(board[x][y]==0) diff-=10000;
        
        sum1[x]-=d;
        sum2[y]-=d;

        ans_type.pb(0);
        ans_num.pb(d);

        turn++;
        return;
    };

    auto set=[&](ll d)  -> void {
        if(turn>turn_threshold) return;
        if(have==0) return;
        if(have<d) d=have;

        diff-=abs(board[x][y])*100;
        board[x][y]+=d;
        have-=d;
        cost+=d;

        diff+=abs(board[x][y])*100;
        if(board[x][y]==0) diff-=10000;

        sum1[x]+=d;
        sum2[y]+=d;

        ans_type.pb(1);
        ans_num.pb(d);

        turn++;
        return;
    };

    auto set_or_get=[&]() -> void {
        seen_time[x][y]++;
        if(board[x][y]==0) return;
        else if(board[x][y]>0) get(board[x][y]);
        else set(-board[x][y]);
        return;
    };

    vl dx={1,0,-1,0},dy={0,1,0,-1};
    vector<char> vc={'D','R','U','L'};
    auto canmove=[&](int d) -> ll {
        ll tox=x+dx[d];
        ll toy=y+dy[d];
        if(tox<0||tox>=n||toy<0||toy>=n) return -inf;
        else return board[tox][toy];
    };
    auto move=[&](int d) -> void {
        if(turn>turn_threshold) return;
        if(canmove(d)==-inf) return;
        x+=dx[d];
        y+=dy[d];
        cost+=100+have;

        ans_type.pb(2);
        ans_num.pb(d);

        prev_move=d;
        turn++;
        return;
    };

    ll max_score=0;
    vl final_ans_type;
    vl final_ans_num;

    auto calc_score=[&]() -> ll {
        ll score=1e9;
        score*=base;
        score/=(diff+cost);
        return score;
    };

    auto update=[&]() -> void {
        ll score=calc_score();
        if(score>max_score){
            max_score=score;
            final_ans_type=ans_type;
            final_ans_num=ans_num;
        }
    };

    auto reset=[&]() -> void {
        board=v;
        seen_time=vvl(n,vl(n,0));
        x=0,y=0;
        cost=0;
        diff=diff_orig;
        turn=0,turn_threshold=100000;
        have=0;
        ans_type={};
        ans_num={};
        prev_move=-1;
        sum1=sum1_orig;
        sum2=sum2_orig;
    };

    auto move_to=[&](ll i,ll j) -> void {
        while(x!=i){
            if(x>i) move(2);
            else move(0);
        }
        while(j!=y){
            if(y>j) move(3);
            else move(1);
        }
    };

    //debug("ok");

    while(tk.update()){
        int x1=0,y1=0,x2=n,y2=n;
        bool left=true,up=true;
        //操作を生成していく
        //基本的に2択を進める

        ll border=200;
        while(x2-x1>=2||y2-y1>=2){
            ll mid=border*2;
            mid+=abs(sum1[x]+have-border);
            mid-=abs(sum1[y]+have-border);

            if((y2-y1!=0&&random(0,border*4-1)>=mid)||(x2-x1==0)){
                if(left){
                    while(y<y2-1){
                        set_or_get();
                        move(1);
                    }
                    set_or_get();
                    if(up){
                        move(0);
                        x1++;
                    }
                    else{
                        move(2);
                        x2--;
                    }
                    left=false;
                }
                else{
                    while(y>y1){
                        set_or_get();
                        move(3);
                    }
                    set_or_get();
                    if(up){
                        move(0);
                        x1++;
                    }
                    else{
                        move(2);
                        x2--;
                    }
                    left=true;
                }
            }
            else{
                if(up){
                    while(x<x2-1){
                        set_or_get();
                        move(0);
                    }
                    set_or_get();
                    if(left){
                        move(1);
                        y1++;
                    }
                    else{
                        move(3);
                        y2--;
                    }
                    up=false;
                }
                else{
                    while(x>x1){
                        set_or_get();
                        move(2);
                    }
                    set_or_get();
                    if(left){
                        move(1);
                        y1++;
                    }
                    else{
                        move(3);
                        y2--;
                    }
                    up=true;
                }
            }
        }

        //最後に取り零しを拾う

        vector<LP> remains;
        rep(i,n)rep(j,n){
            if(board[i][j]!=0){
                remains.pb({i,j});
            }
        }

        for(auto [x,y]:remains){
            move_to(x,y);
            set_or_get();
        }
        
        update();
        reset();
    }

    while(1){
        if(final_ans_type.back()==2){
            final_ans_num.ppb();
            final_ans_type.ppb();
        }
        else{
            break;
        }
    }
    rep(i,final_ans_type.size()){
        ll type=final_ans_type[i];
        if(type==0){
            cout << '+' << final_ans_num[i] << endl;
        }
        if(type==1){
            cout << '-' << final_ans_num[i] << endl;
        }
        if(type==2){
            cout << vc[final_ans_num[i]] << endl;
        }
    }

}