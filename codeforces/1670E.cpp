#include <bits/stdc++.h>
using namespace std;
const int MM = (1<<18); 
int n, p;
map<int, int> edge_val[MM];
pair<int,int> edges[MM];
int node_val[MM], cur;
vector<int> adj[MM];
void dfs(int u, int pa, int x) {
  for (int v : adj[u]) {
    if (v==pa) continue;
    if (x & n) {
      node_val[v] = cur;
      edge_val[u][v] = edge_val[v][u] = cur+n;
    } else {
      node_val[v] = cur+n;
      edge_val[u][v] = edge_val[v][u] = cur;
    }
    cur++;
    dfs(v, u, node_val[v]);
  }
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> p;
    n = (1<<p);
    for (int i=1;i<=n;i++) adj[i].clear(), edge_val[i].clear();
    for (int i=0;i<n-1;i++) {
      int u,v;cin>>u>>v;
      edges[i] = {u, v};
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cur=1;
    node_val[1] = n;
    dfs(1, 0, n);
    cout << "1\n";
    for (int i=1;i<=n;i++) cout << node_val[i] << " "; cout << '\n';
    for (int i=0;i<n-1;i++) {
      int u = edges[i].first, v = edges[i].second;
      cout << edge_val[u][v] << ' ';
    }
    cout << '\n';
  }
}