int main() {
  int n;
  cin >> n;
  int n2 = 1<<n;
  vector<vector<int>> dp(n2,vector<int>(n,INF));
  vector<vector<int>> dist(n,vector<int>(n));
  rep(i,n)rep(j,n) {
      //dist[i][j]を決定
  }
  rep(i,n) {
      //ここで初期値を決定。以下は例
      //if (i == 0) continue;
      //dp[1<<i][i] = dist[0][i];
  }
  rep(i,n2)rep(j,n) {
    if (~i>>j&1) continue;
    rep(k,n) {
      if (i>>k&1) continue;
      chmin(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
    }
  }
  cout << dp[n2-1][0] << endl;
  return 0;
}