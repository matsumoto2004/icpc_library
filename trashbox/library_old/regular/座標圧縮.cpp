

vector<long long> compress(vector<long long> v){
    vector<long long> v2=v;
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());

    vector<long long> ret(v.size());
    for(int i=0;i<v.size();i++){
        ret[i]=lower_bound(v2.begin(),v2.end(),v[i])-v2.begin();
    }
    return ret;
}