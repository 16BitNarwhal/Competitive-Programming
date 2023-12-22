#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> adj;
map<int, int> pa, dst;
int dfs(int u, int p) { 
  int ret=u;
  dst[u] = 0;
  for (int v : adj[u]) {
    if (v==p) continue;
    pa[v] = u;
    int x = dfs(v, u);
    if (dst[v] + 1 > dst[u]) {
      dst[u] = max(dst[u], dst[v] + 1);
      ret = x;
    }
  }
  return ret;
}
int main() { 
  int n;cin>>n;
  int st=0;
  for (int i=0,u,v;i<n;i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (i==0) st=u;
  } 
  int u = dfs(st, 0); 
  pa.clear();
  u = dfs(u, 0); 
  int v = u;
  while (pa[v] != 0) {
    cout << v << ' ';
    v = pa[v];
  }
  cout << v << '\n';
}