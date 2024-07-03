vector<ll> alldiv(ll n){
    vector<ll> vec;
    rrep(i,1,sqrt(n)+1){
        if(n%i==0){
            vec.PB(i);
            if(n/i!=i) vec.PB(n/i);
        }

    }
    sort(all(vec));
    return vec;
}