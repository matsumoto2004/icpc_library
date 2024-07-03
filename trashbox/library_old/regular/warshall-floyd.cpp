int d[MAX_V][MAX_V];//距離を管理、おそらくinfでresizeして使うんだと思う
int V;//頂点数

void warshall_floyd() {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
//o(v^3)