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

void dfs(ll v,VVl &graph,Vl &seen){
	seen[v]=1;
	for(auto u:graph[v]){
		if(seen[u]) continue;
		dfs(u,graph,seen);
	}
	return;
}


int main(){
	ll n;
	cin >> n;
	Vl vx(n),vy(n),vp(n);
	rep(i,n) cin >> vx[i] >> vy[i] >> vp[i];
	ll ok=4e9+5,ng=0;
	while(ok-ng>1){
		ll mid=(ok+ng)/2;
		VVl graph(n);
		rep(i,n)rep(j,n){
			if(i==j) continue;
			if(vp[i]*mid>=abs(vx[i]-vx[j])+abs(vy[i]-vy[j])){
				graph[i].PB(j);
			}
		}
		ll flag=0;
		rep(i,n){
			Vl seen(n,0);
			dfs(i,graph,seen);
			sort(all(seen));
			if(seen[0]) flag=1;
		}
		if(flag) ok=mid;
		else ng=mid;
	}
	cout << ok << endl;

}