#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
vector<int> adj[MM];
int dst[MM];
int main() {
  int t;cin>>t;
  while(t--) {
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) {
      adj[i].clear();
      dst[i]=-1;
    }
    for (int i=0,u,v;i<m;i++) {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    dst[1] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dst[v] != -1) continue;
        dst[v] = dst[u]+1;
        q.push(v);
      }
    }
    vector<int> res[2];
    for (int i=1;i<=n;i++)
      res[dst[i]%2].push_back(i);
    int k = (res[1].size() < res[0].size());
    cout << res[k].size() << '\n';
    for (int i : res[k]) cout << i << ' ';
    cout << '\n';
  }
}