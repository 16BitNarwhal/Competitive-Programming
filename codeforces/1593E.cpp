#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+2;
vector<int> adj[MM];
int t, deg[MM], dis[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>t;
  while (t--) {
    int n, k; cin>>n>>k;
    for (int i=0;i<=n;i++) adj[i].clear();
    fill(dis, dis+n+1, 0);
    for (int i=1,u,v;i<n;i++) {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    } 
    queue<int> q;
    for (int i=1;i<=n;i++) {
      deg[i] = adj[i].size();
      if (deg[i]==1) {
        dis[i] = 1;
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        deg[v]--;
        if (deg[v]!=1) continue;
        dis[v] = dis[u]+1;
        q.push(v);
      }
    }
    int res=0;
    for (int i=1;i<=n;i++) {
      res += (dis[i] <= k);
    }
    cout << n-res << '\n';
  }
}