
int main() {
    int n, m; cin >> n >> m;

    vector<vector<long long>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        //a--;b--;//必要に応じて
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n, -1); 
    queue<int> que;

    
    dist[0] = 0;
    que.push(0); 

    
    while (!que.empty()) {
        int v = que.front(); 
        que.pop();

        for (int nv : g[v]) {
            if (dist[nv] != -1) continue; 

            
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

   
}
//o(edge数)