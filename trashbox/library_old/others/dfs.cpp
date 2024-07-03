int n,m;
vector<vector<int>> v(400000);
vector<bool> seen(400000);
void dfs(int k){
    if(!seen[k]){
        seen[k]=true;
        for(auto next:v[k]){
            if(seen[next]) continue;
            dfs(next);
        }
    }
    
}

int main() {

    cin >> n >> m;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rep(i,n){
        if(seen[i]) continue;
        dfs(i);
    }  
}