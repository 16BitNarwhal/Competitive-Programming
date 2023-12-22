#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct edge {
  int v, d;
  bool operator < (const edge &e) const {
    return d < e.d;
  }
};
int n, k, s[MM], ans[MM];
vector<edge> adj[MM];
void dfs(int u, int pl, int pr) {
  sort(adj[u].begin(), adj[u].end());
  int m = adj[u].size(); 
  for (int i=0;i<m;i++) {
    int l = pl;
    if (i>0) l = max(l, (adj[u][i-1].d + adj[u][i].d) / 2);
    int r = pr;
    if (i<m-1) r = min(r, (adj[u][i].d + adj[u][i+1].d) / 2);
    int li = upper_bound(s, s+k, l) - s;
    int ri = upper_bound(s, s+k, r) - s;
    if (ri==k || s[ri] > r) ri--;
    ans[adj[u][i].v] = max(0, ri - li + 1);
    dfs(adj[u][i].v, l, r);
  }
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n-1;i++) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
  }
  for (int i=0;i<k;i++) cin >> s[i];
  sort(s, s+k);
  dfs(1, 0, 1e9);
  ans[1] = k;
  for (int i=1;i<=n;i++) {
    cout << ans[i];
    if (i<n) cout << ' ';
  }
  cout << '\n';
}