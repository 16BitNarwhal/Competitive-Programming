#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int a[MM], b[MM], vals[MM];
vector<int> adj[MM];
int lo, hi;
bool vis[MM];
vector<vector<int>> vec;
void dfs(int u, int p) { 
  vis[u] = 1;
  p ^= 1;
  vec.back().push_back(u);
  for (int v : adj[u]) {
    if (vis[v]) continue;
    vals[u] = (p&1?lo++:hi--);
    dfs(v, p);
    return;
  }
  // end of cycle
  vals[u] = (p&1?-1:hi--); // odd len chain
  return;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    fill(vis, vis+n+1, 0);
    fill(vals, vals+n+1, 0);
    for (int i=1;i<=n;i++) adj[i].clear();
    vec.clear();
    for (int i=0;i<n;i++) {
      adj[a[i]].push_back(b[i]);
      adj[b[i]].push_back(a[i]);
    }
    lo = 1, hi = n;
    for (int i=1;i<=n;i++) {
      if (vis[i]) continue;
      vec.push_back({});
      dfs(i, 0); 
    }
    for (int i=1;i<=n;i++) {
      if (vals[i]>0) continue;
      vals[i]=lo++;
    }
    ll ans=0;
    for (auto v : vec) {
      for (int i=0;i<v.size();i++) {
        ans += abs(vals[v[i]] - vals[v[(i+1)%v.size()]]);
      }
    }
    cout << ans << '\n';
    
  }
}