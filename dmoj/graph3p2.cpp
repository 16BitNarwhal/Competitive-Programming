#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int n, m, dst[1001];

struct edge {
  int u, v, w;
} edges[100001];
void bellman() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  memset(dst, 0x3f, sizeof(dst));
  dst[1] = 0;
  for (int i=0;i<n-1;i++) {
    for (edge e : edges) {
      dst[e.v] = min(dst[e.u] + e.w, dst[e.v]);
    }
  }
  cout << dst[n] << endl;
}

vector<pi> adj[100001];
bool inq[1001];
void spfa() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }
  memset(dst, 0x3f, sizeof(dst));
  dst[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inq[u] = false;
    for (auto [v, w] : adj[u]) {
      if (dst[v] > dst[u] + w) {
        dst[v] = dst[u] + w;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
  cout << dst[n] << endl;
}
int main() {
  // bellman();
  spfa();
}