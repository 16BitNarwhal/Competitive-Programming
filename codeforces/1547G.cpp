#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+1;
int n,m,vis[MM];
vector<int> adj[MM];  
int main() {
  int t;cin>>t;
  while(t--) {
    cin >> n >> m;
    fill(vis, vis+n+1, 0);
    for (int i=0;i<=n;i++) adj[i].clear();
    for (int i=0,u,v;i<n;i++) {
      cin>>u>>v;
      adj[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int u = q.back(); q.pop();
      for (int v : adj[u]) {
        if (vis[u]>0) continue;
        vis[u]=1;
      }
    }
  }
}