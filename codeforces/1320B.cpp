#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, m, k, dst[MM], path[MM];
// 1: forward, 2: backward
vector<int> adj1[MM], adj2[MM];
bool vis[MM];
int main() {
  cin >> n >> m;
  for (int i=0,u,v;i<m;i++) {
    cin >> u >> v;
    adj1[u].push_back(v);
    adj2[v].push_back(u);
  }
  cin >> k;
  for (int i=0;i<k;i++) 
    cin >> path[i];  
  
  queue<int> q;
  vis[path[k-1]] = 1;
  q.push(path[k-1]);
  dst[path[k-1]] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj2[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      dst[v] = dst[u]+1;
      q.push(v);
    }
  }

  int mn=0, mx=0;
  for (int i=0;i<k-1;i++) {
    int u = path[i];
    if (dst[path[i+1]] > dst[u]-1) {
      mn++, mx++;
    } else {
      bool flag=0;
      for (int v : adj1[u]) {
        if (v != path[i+1]) 
          flag |= (dst[v] == dst[u]-1);
      }
      mx += flag;
    }
  }
  cout << mn << ' ' << mx << '\n';
}