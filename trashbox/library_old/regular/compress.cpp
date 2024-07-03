struct Compress{
    Vl v;
    
    void insert(ll x){
        v.push_back(x);
    }
    void init(){
        sort(all(v));
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }
    ll get(ll x){
        return lower_bound(all(v),x)-v.begin();
    }
    ll rev(ll x){
        return v[x];
    }
    ll getmax(){
        return v.size();
    }

};