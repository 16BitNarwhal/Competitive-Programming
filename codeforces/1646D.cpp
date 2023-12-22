#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 2e5+2;
int n, res[MM];
pi dp[MM][2];
vector<int> adj[MM];
// max(first) min(second)
pi better(pi a, pi b) {
  if (a.first == b.first) {
    return a.second < b.second ? a : b;
  }
  return a.first > b.first ? a : b;
}
pi dfs(int u, int pa, bool can) {
  if (dp[u][can].second != 0) return dp[u][can];
  if (!can) {
    pi cur = {0, 1};
    for (int v : adj[u]) {
      if (v == pa) continue;
      pi tmp = better(dfs(v, u, true), dfs(v, u, false));
      cur.first += tmp.first;
      cur.second += tmp.second;
    }
    return dp[u][can]=cur;
  } else {
    pi cur = {1, adj[u].size()};
    for (int v : adj[u]) {
      if (v==pa) continue;
      pi tmp = dfs(v, u, false);
      cur.first += tmp.first;
      cur.second += tmp.second;
    }
    return dp[u][can]=cur;
  }
}
void build(int u, int pa, pi p) {
  if (p == dp[u][0]) {
    res[u] = 1;
    for (int v : adj[u]) {
      if (v==pa) continue;
      build(v, u, better(dp[v][0], dp[v][1]));
    }
  } else {
    res[u] = adj[u].size();
    for (int v : adj[u]) {
      if (v==pa) continue;
      build(v, u, dp[v][0]);
    }
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n==2) {
    cout << "2 2\n1 1\n";
    return 0;
  }
  pi ans = better(dfs(1, 0, true), dfs(1, 0, false));
  build(1, 0, ans);
  cout << ans.first << ' ' << ans.second << '\n';
  for (int i=1;i<=n;i++) {
    cout << res[i] << ' ';
  }
  return 0;
}
