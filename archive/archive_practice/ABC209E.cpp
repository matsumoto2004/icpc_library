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

ll tonum(string s){
    ll ret=0;
    rep(i,3){
        ret*=52;
        if(isupper(s[i]))ret+=s[i]-'A';
        else ret+=26+s[i]-'a';
    }
    return ret;
}

ll kind=52*52*52;

int main(){
    ll n;
    cin >> n;
    vector<string> vs(n);
    rep(i,n) cin >> vs[i];
    Vl va(n),vb(n);
    rep(i,n){
        string s=vs[i];
        va[i]=tonum(s.substr(0,3));
        vb[i]=tonum(s.substr(s.size()-3,3));
    }
    VVl to(kind),from(kind);
    Vl degree(kind,0);
    Vl state(kind,0);
    Vl visited(kind,-1);
    rep(i,n){
        to[va[i]].PB(vb[i]);
        from[vb[i]].PB(va[i]);
        degree[va[i]]++;
    }
    queue<ll> que;
    rep(i,kind){
        if(degree[i]==0){
            que.push(i);
            visited[i]=1;
            //state[i]=-1;
        }
    }
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        ll ans=-1;
        ll roop=-1;
        for(ll next:to[now]){
            if(next==now) roop=0;
            else if(state[next]==-1) ans=1;
            else if(state[next]==0&&ans==-1) ans=0; 
        }
        if(roop==0&&ans==-1) ans=0;
        for(ll next:from[now]){
            if(next==now) continue;
            degree[next]--;
            if(degree[next]==0&&visited[next]==-1){
                que.push(next);
                visited[next]=1;
            }
            else if(ans==-1&&visited[next]==-1){
                que.push(next);
                visited[next]=1;
            }
        }
        state[now]=ans;
        //if(now==tonum("abc")) cout << ans << endl;
    }
    rep(i,n){
        ll x=state[vb[i]];
        if(x==1){
            cout << "Aoki" << endl;
        }
        if(x==0){
            cout << "Draw" << endl;
        }
        if(x==-1){
            cout << "Takahashi" << endl;
        }
    }

}