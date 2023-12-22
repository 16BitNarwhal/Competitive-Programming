#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int adj[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n,m;cin>>n>>m;
    fill(adj, adj+n+1, 0); 
    int ans=0;
    for (int i=0,u,v;i<m;i++) {
      cin >> u >> v;
      if (u!=v) {
        adj[u]=v;
        ans++;
      }
    } 
    int cycle=0;
    for (int i=1;i<=n;i++) {
      if (adj[i]==0) continue; 
      int u = adj[i];
      adj[i] = 0;
      while (u!=0 && u!=i) {
        int v = u;
        u = adj[u];
        adj[v] = 0;
      } 
      if (u==i) ans++;
    }
    cout << ans << '\n';
  }
}