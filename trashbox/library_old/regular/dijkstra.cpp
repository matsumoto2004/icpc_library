struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;//注意！！！！！！
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis(infで初期化しておくべき)
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis) { //sはスタート地点(0-index)
    int N = G.size();
    dis.resize(N, inf);///////resizeがうまくいかないことがあるらしいので注意
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

//Graph G(n);Vl dis(n,inf);//で宣言
//G[].PB({to,cost})//で辺を足す
//dijkstra(G,s,dis)で開始
//disが書き換えられる