#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct edge { int v, w; };
int N, M, p[MM], rt[MM]; 
vector<edge> adj[MM];
int find(int u) { 
  return (rt[u]!=u ? rt[u]=find(rt[u]) : u);
}
void dfs(int u, int r, int mn) {
  if (rt[u] == r) return;
  rt[u] = r;
  for (edge e : adj[u])
    if (e.w >= mn) dfs(e.v, r, mn);
}
bool check(int mn) {
  memset(rt, -1, sizeof rt);
  for (int i=1;i<=N;i++) {
    if (rt[i] < 0)
      dfs(i, i, mn);
  }
  for (int i=1;i<=N;i++) {
    if (rt[p[i]] != rt[i]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i=1;i<=N;i++) cin >> p[i];
  for (int i=0, u, v, w;i<M;i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  int l=0, r=1e9+1, ans=0;
  while (l<=r) {
    int m = (l+r)/2;
    if (check(m)) { ans=m; l=m+1; }
    else r=m-1;
  }
  for (int i=1;i<=N;i++) {
    if (p[i]!=i) {
      cout << ans << '\n';
      return 0;
    }
  }
  cout << "-1\n";
}

/**
 * check:
 *  for all i:
 *    if (rt(ar[i]) != rt(i)) return false;
 *  return true;
 *  
 * 
 **/