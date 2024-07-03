// //combination//mint,modが必要
// struct combination {
//   vector<mint> fact, ifact;
//   combination(int n):fact(n+1),ifact(n+1) {
//     assert(n < mod);
//     fact[0] = 1;
//     for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
//     ifact[n] = fact[n].inv();
//     for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
//   }
//   mint operator()(int n, int k) {
//     if (k < 0 || k > n) return 0;
//     return fact[n]*ifact[k]*ifact[n-k];
//   }
// };

vector<ll> fac(3000001); //n!(mod M)
vector<ll> ifac(3000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

// mainに入れる
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<3000000; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }