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

//行列の乗算
VVl matrix_multiply(VVl X, VVl Y) {
	VVl Z(X.size(), Vl(Y[0].size()));
	rep(i, X.size()) {
		rep(k, Y.size()) {
			rep(j, Y[0].size()) {
				Z[i][j] = (Z[i][j] + X[i][k] * Y[k][j]) ;
			}
		}
	}
	return Z;
}

//A^nの計算
VVl matrix_pow(VVl A, ll n) {
	VVl B(A.size(), Vl(A[0].size()));
	//単位行列でBを初期化
	rep(i, B.size()) {
		B[i][i] = 1;
	}

	while (n>0) {
		if (n & 1) { B = matrix_multiply(B, A); }
		A = matrix_multiply(A, A);
		n = n >> 1;
	}
	return B;
}

void show(VVl vv){
    for(auto v:vv){
        for(auto x:v){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    ll n;
    cin >> n;
    Vl vx(n),vy(n);
    rep(i,n) cin >> vx[i] >> vy[i];

    vector<VVl> memo;   

    VVl now={{1,0,0},{0,1,0},{0,0,1}};

    memo.push_back(now);

    ll m;
    cin >> m;
    rep(i,m){
        ll query;
        cin >> query;
        VVl kake;
        if(query==2){
            kake={{0,-1,0},{1,0,0},{0,0,1}};
        }
        if(query==1){
            kake={{0,1,0},{-1,0,0},{0,0,1}};
        }
        if(query==3){
            ll p;
            cin >> p;
            kake={{-1,0,2*p},{0,1,0},{0,0,1}};

        }
        if(query==4){
            ll p;
            cin >> p;
            kake={{1,0,0},{0,-1,2*p},{0,0,1}};

        }
        now=matrix_multiply(kake,now);
        memo.push_back(now);
        //show(now);
    }

    ll q;
    cin >> q;
    rep(query,q){
        ll a,b;
        cin >> a >> b;
        b--;
        VVl mat=matrix_multiply(memo[a],VVl{{vx[b]},{vy[b]},{1}});
        cout << mat[0][0] << " " << mat[1][0] << endl;

    }
}