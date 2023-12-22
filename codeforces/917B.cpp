#include <bits/stdc++.h>
using namespace std;
struct ed {
  int v, w;
};
vector<ed> adj[101];
int dp[101][101][26][2];
// max node, lucas node, c code, k turn
int solve(int a, int b, int c, int k) {
  if (dp[a][b][c][k] != -1) return dp[a][b][c][k];
  if (k==0) { // max turn
    int res = 1; // default lucas win (no possible edges)
    for (auto [v, w] : adj[a]) {
      if (w < c) continue;
      res = min(res, solve(v, b, w, !k));
    }
    return dp[a][b][c][k] = res;
  } else { // lucas turn
    int res = 0; // default max win (no possible edges)
    for (auto [v, w] : adj[b]) {
      if (w < c) continue;
      res = max(res, solve(a, v, w, !k));
    }
    return dp[a][b][c][k] = res;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=0,u,v;i<m;i++) {
    cin >> u >> v;
    char c;cin>>c;
    adj[u].push_back({v, (int)(c-'a')});
  }
  memset(dp, -1, sizeof dp);
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      // 0 if max win, 1 if lucas win
      if (solve(i, j, 0, 0)) cout << "B";
      else cout << "A";
    }
    cout << '\n';
  }
}