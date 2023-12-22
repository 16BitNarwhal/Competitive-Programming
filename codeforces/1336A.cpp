#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
int n, k, pa[MM], sz[MM], dst[MM], res[MM];
vector<int> adj[MM];
void dfs(int u, int p) {
  dst[u] = dst[p]+1;
  sz[u] = 1;
  pa[u] = p;
  for (int v : adj[u]) {
    if (v==p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
  res[u] = sz[u] - dst[u];
}
int main() {
  cin >> n >> k;
  for (int i=0,u,v;i<n-1;i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  sort(res+1, res+n+1, greater<int>());
  ll ans=0;
  for (int i=1;i<=n-k;i++)
    ans += res[i];
  cout << ans << '\n';
}