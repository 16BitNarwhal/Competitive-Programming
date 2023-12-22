#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, L[MM], R[MM];
ll dp[MM][2];
vector<int> adj[MM];
void dfs(int u, int pa) {
  dp[u][0] = dp[u][1] = 0;
  for (int v : adj[u]) {
    if (v==pa) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0] + abs(L[v] - L[u]), dp[v][1] + abs(R[v] - L[u]));
    dp[u][1] += max(dp[v][0] + abs(L[v] - R[u]), dp[v][1] + abs(R[v] - R[u]));
  }
}
void solve() {
  cin >> n;
  for (int i=1;i<=n;i++) adj[i].clear();
  for (int i=1;i<=n;i++)
    cin >> L[i] >> R[i];
  for (int i=0,u,v;i<n-1;i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  cout << max(dp[1][0], dp[1][1]) << '\n'; 
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) solve();
}