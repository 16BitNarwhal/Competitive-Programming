#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM];
vector<int> adj[MM];
bool vis[MM], can;
void dfs(int u) {
  if (vis[u]) {
    can = false;
    return;
  }
  if (ar[u] != -1) return;
  ar[u] = 1;
  vis[u] = true;
  for (int v : adj[u]) {
    dfs(v);
    if (v > u) {
      ar[u] = max(ar[u], ar[v]+1);
    } else {
      ar[u] = max(ar[u], ar[v]);
    }
  }
  vis[u] = false;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    can = true;
    fill(ar, ar+n+1, -1);
    fill(vis, vis+n+1, false);
    for (int i=1;i<=n;i++) {
      adj[i].clear();
      int m;cin>>m;
      for (int j=0;j<m;j++) {
        int x;cin>>x;
        adj[i].push_back(x); 
      }
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
      dfs(i);
      ans = max(ans, ar[i]);
    }
    if (can) cout << ans << '\n';
    else cout << "-1\n";
  }
}