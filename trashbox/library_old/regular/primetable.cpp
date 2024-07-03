vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

vector<ll> prime_enumeration(ll n){
    vector<bool> v=prime_table(n);
    vector<ll> ret;
    rrep(i,2,n+1) if(v[i]) ret.push_back(i);
    return ret;
}