struct Edge{
    long long to;
};
using Graph=vector<vector<Edge>>;

struct LCA{
    vector<vector<ll>> parent;
    vector<ll> dist;
    LCA(const Graph&G,ll root=0){init(G,root);}

    void init(const Graph &G,ll root=0){
        ll v=G.size();
        ll k=1;
        while((1<<k)<v) k++;
        parent.assign(k,vector<ll>(v,-1));
        dist.assign(v,-1);
        dfs(G,root,-1,0);
        for(int i=0;i+1<k;i++){
            for(int j=0;j<v;j++){
                if(parent[i][j]<0){
                    parent[i+1][j]=-1;
                }else{
                    parent[i+1][j]=parent[i][parent[i][j]];
                }
                
            }
        }
        
    }

    void dfs(const Graph &G,ll v,ll p,ll d){
        parent[0][v]=p;
        dist[v]=d;
        for(auto e:G[v]){
            if(e.to!=p) dfs(G,e.to,v,d+1);
        }
    }

    ll query(ll u,ll v){
        if(dist[u]<dist[v]) swap(u,v);
        ll k=parent.size();
        for(int i=0;i<k;i++){
            if(((dist[u]-dist[v])>>i)&1){
                u=parent[i][u];
            }
        }
        if(u==v) return u;
        for(int i=k-1;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u=parent[i][u];
                v=parent[i][v];
            }
        }
        return parent[0][u];
    }

    ll get_dist(ll u,ll v){
        return dist[u]+dist[v]-2*dist[query(u,v)];
    }
    bool is_on_path(int u, int v, int a) { return get_dist(u, a) + get_dist(a, v) == get_dist(u, v); }
    
};