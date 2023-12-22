#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 1010;
struct edge {
  int v;
  double c;
};
struct dist {
  double d;
  int d2;
  bool operator<(const dist& a) const {
    if (d == a.d) return d2 > a.d2;
    return d > a.d;
  }
};
int V, E;
edge from[MM];
dist dst[MM];
vector<edge> adj[MM];
int main() {
  cin >> V >> E;
  for (int i=0;i<E;i++) {
    int u, v;
    double d, s;
    cin >> u >> v >> d >> s;
    adj[u].push_back({v, d/s});
    adj[v].push_back({u, d/s});
  }
  for (int i=1;i<=V;i++) {
    dst[i] = {1e9, V+1};
  }
  priority_queue<pair<dist,int>> pq;
  pq.push({{0,0}, 1});
  dst[1] = {0,0};
  while (!pq.empty()) {
    int u = pq.top().second;
    dist d = pq.top().first;
    pq.pop();
    if (d.d > dst[u].d) continue;
    for (auto& e : adj[u]) {
      int v = e.v;
      double c = e.c;
      dist newd = {d.d + c, d.d2 + 1};
      if (dst[v] < newd) {
        from[v] = {u, c};
        dst[v] = newd;
        pq.push({dst[v], v});
      }
    }
  }
  int u = V;
  double sum=0;
  while (u != 1) {
    sum += (from[u].c/0.75);
    u = from[u].v;
  }
  cout << dst[V].d2 << '\n' << round((sum-dst[V].d)*60) << '\n';
}