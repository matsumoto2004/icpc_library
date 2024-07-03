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

struct Mo {
  int n;
  vector< pair< int, int > > lr;

  explicit Mo(int n) : n(n) {}

  void add(int l, int r) { /* [l, r) */
    lr.emplace_back(l, r);
  }

  template< typename AL, typename AR, typename EL, typename ER, typename O >
  void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
    int q = (int) lr.size();
    int bs = n / min< int >(n, sqrt(q));
    vector< int > ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if(ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for(auto idx : ord) {
      while(l > lr[idx].first) add_left(--l);
      while(r < lr[idx].second) add_right(r++);
      while(l < lr[idx].first) erase_left(l++);
      while(r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }

  template< typename A, typename E, typename O >
  void build(const A &add, const E &erase, const O &out) {
    build(add, add, erase, erase, out);
  }
};
/*
mo(n)で宣言
mo.add(x,y)でクエリを追加
auto add = [&](int i) {
  if(cnt[A[i]]++ == 0) ++sum;
};
auto erase = [&](int i) {
  if(--cnt[A[i]] == 0) --sum;
};
auto out = [&](int q) {
  ans[q] = sum;
};
のように関数を定義
mo.build(add, erase, out);
で実行
*/

Vl cnt(3e5,0);
Vl v;
Vl ans;
ll now=0;

void add(int i) {
  cnt[v[i]]++;
  now+=(cnt[v[i]]-1)*(cnt[v[i]]-2)/2;
};
void erase(int i) {
  now-=(cnt[v[i]]-1)*(cnt[v[i]]-2)/2;
  cnt[v[i]]--;
};
void out (int q) {
  ans[q] = now;
};



int main(){
  ll n,q;
  cin >> n >> q;
  v.resize(n);
  ans.resize(q);
  rep(i,n) cin >> v[i];
  rep(i,n) v[i]--;
  Mo mo(2e5+5);
  rep(i,q){
    ll l,r;
    cin >> l >> r;
    l--;r--;
    mo.add(l,r+1);
    
  }
  mo.build(add,erase,out);
  rep(i,q) cout << ans[i] << endl;

}