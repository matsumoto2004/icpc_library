#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素  //遅延セグ木使うときは注意
#define S second //pairの二つ目の要素  //遅延セグ木使うときは注意
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pl = pair<ll, ll>;
using Vs = vector<string>;
const ll mod = 998244353;
const ll inf = 4000000000000000000;//10の18乗*4
#define yn {puts("Yes");}else{puts("No");}
#define dame { puts("-1"); return 0;}

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);//xのサイズのほうが大きくなるように(if文は逆ではない)
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};
 
 
// int main() {
//     int N, M;
//     cin >> N >> M;
 
//     //友達集合を作る
//     UnionFind UF(N);
//     for (int i = 0; i < M; i++)
//     {
//         int A, B;
//         cin >> A >> B;
//         A -= 1; B -= 1;
//         UF.unite(A, B);
//     }
 
//     //最大の友達集合を求める
//     int ans = 0;
//     for (int i = 0; i < N; i++)
//     {
//         ans = max(ans, UF.size(i));
//     }
 
//     cout << ans << endl;
// }

int main(){
    ll n;
    cin >> n;
    Vl vx(n),vy(n);
    rep(i,n) cin >> vx[i] >> vy[i];
    long double ok=0,ng=100.01;
    rep(i,1005){
        long double mid=(ng+ok)/2;
        UnionFind uf(n+2);
        rep(i,n){
            long double x=vx[i],y=vy[i];
            if(abs(y-100)<mid*2) uf.unite(i,n);
            if(abs(y+100)<mid*2) uf.unite(i,n+1);
        }
        rep(i,n)rep(j,n){
            long double x1=vx[i],y1=vy[i];
            long double x2=vx[j],y2=vy[j];
            long double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            if(dist<mid*2) uf.unite(i,j);
        }
        if(uf.root(n)==uf.root(n+1)) ng=mid;
        else ok=mid;
    }
    cout << fixed << setprecision(12);
    cout << ok << endl;

}