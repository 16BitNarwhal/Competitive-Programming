#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll val[MM], dst[MM], x;
bool vis[MM];
vector<ll> adj[MM];
int dfs(int u) {
  if (dst[u]!=0) return dst[u];
  vis[u] = 1;
  dst[u] = 1;
  for (int v : adj[u]) {
    if (val[v] > x) continue;
    if (vis[v]) {
      // cycle
      vis[u] = 0;
      return dst[u] = -1;
    }
    ll d = dfs(v);
    if (d==-1) { vis[u]=0; return -1; }
    dst[u] = max(dst[u], d+1);
  }
  vis[u]=0;
  return dst[u];
}
int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  ll lo=1, hi=1;
  for (int i=1;i<=n;i++) {
    cin >> val[i];
    hi = max(hi, val[i]);
  }
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  ll ans=-1; 
  while (lo <= hi) {
    x = (lo+hi)/2;
    fill(dst, dst+n+1, 0);
    fill(vis, vis+n+1, 0);
    bool ok=false;
    for (int i=1;i<=n;i++) {
      if (val[i] > x) continue;
      ll d = dfs(i); 
      if (d >= k) {
        ok = true;
      } else if (d == -1) {
        ok = true;
      }
    }
    
    if (ok) {
      ans = x;
      hi = x-1;
    } else {
      lo = x+1;
    }
  }
  cout << ans << '\n';
}