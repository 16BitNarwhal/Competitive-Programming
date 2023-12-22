#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k, c;
ll ans, dst[200005][2];
vector<int> adj[200005];
int dfs(int u, int pa, int X, int d=0) {
  dst[u][X] = d;
  int ret = u;
  for (int v : adj[u]) {
    if (v == pa) continue;
    int far = dfs(v, u, X, d+1);
    if (dst[far][X] > dst[ret][X]) ret = far;
  }
  return ret;
}
void dfs2(int u, int pa, int d=0) {
  for (int v : adj[u]) {
    if (v == pa) continue;
    dfs2(v, u, d+1);
  }
  int mx = max(dst[u][0], dst[u][1]);
  ans = max(ans, k*mx - c*d); 
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k >> c;
    memset(dst, 0, sizeof dst);
    for (int i=0;i<=n;i++) {
      adj[i].clear();
    }
    for (int i=1;i<n;i++) {
      int u, v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dst[1][0] = 0; int far1 = dfs(1, 0, 0);
    dst[far1][0] = 0; int far2 = dfs(far1, 0, 0);
    dst[far2][1] = 0; dfs(far2, 0, 1);
    
    ans=0; dfs2(1, 0);
    cout << ans << '\n';
  }
}