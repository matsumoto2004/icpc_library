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

vector<ll> Z_algorithm(string S) {
	int c = 0, n = S.size();
	//接頭辞の長さを保存する配列を返す。
	//i = 1からやるとする。
	//Z[1]には赤下線が存在しないので、「溢れるor共通部分がない」のところにまずいく。
	//実装上、上のような挙動をしてもらうため、Z[0]=n;は[1, n - 1]まで計算が終わった後に入れる。
	//cは、赤下線の左端の位置。
	vector<ll> Z(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		//今着目してる部分が赤下線の左端から何個分離れているかをlに入れる。
		if (i + Z[l] < c + Z[c]) {
			//この条件を満たすのは、「青下線が赤下線に収まる」。
			//この時、すでに計算されてるなのでそれを流用する。
			Z[i] = Z[l];
		}
		else {
			//この条件を満たすのは、「赤下線から青下線が溢れる」or「赤下線と青下線の共通部分がない」。
			int j = max((ll)0, c + Z[c] - i);
			//c + Z[c] - i > 0の時、これは「溢れる」が該当する。
			//溢れてるのなら、収まる分は計算せずに、溢れた分(j番目から)だけ愚直に突き合わせればよい。
			//そもそも共通部分がないならば、全部突き合わせる。この時、式からj = 0;となるとわかる。

			//愚直に突き合せてる部分
			while (i + j < n && S[j] == S[i + j])j++;
			
			Z[i] = j;
			//今の見てるiで、赤下線に完全に含まれなくなったので、今のiを赤下線の左端として、次のiをまた計算する。
			c = i;
		}
	}

	//最後にこれを忘れずに
	Z[0] = n;
	return Z;
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    ll ans=0;
    rep(i,n){
        string ss=s.substr(i,n-i);
        Vl z=Z_algorithm(ss);
        rep(ii,z.size()){
            ll now=min((ll)ii,z[ii]);
            chmax(ans,now);
        }
    }
    cout << ans << endl;
}