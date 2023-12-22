#include <bits/stdc++.h>
using namespace std;
int dst[101], dst2[101];
vector<int> adj[101]; 
vector<int> ants;
bool bfs(int e, int mx) {
  memset(dst2, -1, sizeof dst2);
  queue<int> q;
  for (int i : ants) {
    dst2[i] = 0;
    q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop(); 
    if (u == e) {
      return true;
    }
    if (dst2[u] >= mx) {
      continue;
    }
    for (int v : adj[u]) {
      if (dst2[v]==-1) {
        dst2[v] = dst2[u] + 1;
        q.push(v);
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int w;cin>>w;
  for (int i=0;i<w;i++) {
    int x;cin>>x;
    ants.push_back(x);
  }
  memset(dst, -1, sizeof dst);
  dst[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();  
    if (bfs(u, dst[u]/4)) {
      continue;
    } 
    if (u == n) {
      cout << dst[u] << '\n';
      return 0;
    }
    for (int v : adj[u]) {
      if (dst[v]==-1) {
        dst[v] = dst[u] + 1;
        q.push(v);
      }
    }
  }
  cout << "sacrifice bobhob314\n";
}