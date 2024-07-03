vector<pair<ll,ll>> factor(ll x){
    ll xx=x;
    vector<pair<ll,ll>> ret;
    rrep(i,2,sqrt(x)+1){
        if(xx%i==0){
            ret.PB({i,0});
        }
        while(xx%i==0){
            xx/=i;
            ret[ret.size()-1].S++;
        }
    }
    if(xx!=1) ret.PB({xx,1});
    return ret;
}