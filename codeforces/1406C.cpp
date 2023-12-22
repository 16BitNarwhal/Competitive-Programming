#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, sz[MM], pa[MM], mn, cent1, cent2;
vector<int> adj[MM];
void dfs(int u, int p) {
  pa[u] = p;
  sz[u] = 1;
  int mx=0;
  for (int v : adj[u]) {
    if (v==p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    mx = max(mx, sz[v]);
  }
  mx = max(mx, n-sz[u]);
  if (mx<mn) {
    mn=mx;
    cent1=u;
    cent2=0;
  } else if (mx==mn) {
    cent2=u;
  }
}
int dfs2(int u, int pa) {
  if (adj[u].size()==1) return u;
  int ret=0;
  for (int v : adj[u]) {
    if (v==pa) continue;
    int x = dfs2(v, u);
    if (x) ret=x;
  }
  return ret;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n;
    cent1=cent2=0;
    mn=1e9;
    for (int i=1;i<=n;i++) adj[i].clear();
    fill(pa, pa+n+1, 0);
    for (int i=1,u,v;i<n;i++) {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1,0);
    if (cent2==0) {
      cout << "1 " << adj[1][0] << "\n";
      cout << "1 " << adj[1][0] << '\n';
      continue;
    }
    if (pa[cent1]!=cent2) swap(cent1, cent2);
    int u = dfs2(cent1, cent2);
    cout << u << ' ' << pa[u] << '\n';
    cout << u << ' ' << cent2 << '\n';
  }
}