#include <bits/stdc++.h>
using namespace std;
int ar[100010];
vector<int> adj[100010];
int main() {
  int t;cin>>t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
      adj[i].clear();
      cin >> ar[i];
    }
    for (int i=0,u,v;i<m;i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (m%2==0) {
      cout << "0\n";
      continue;
    }
    // select at most 2 nodes in a row
    int ans=1e9;
    for (int u=1;u<=n;u++) {
      if (adj[u].size()%2==1) {
        ans = min(ans, ar[u]);
        continue;
      }
      for (int v : adj[u]) {
        // u:even, v:even
        if (adj[v].size()%2==0) 
          ans = min(ans, ar[u]+ar[v]);
      }
    }
    cout << ans << '\n';
  }
}