#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
  int u, v, id;
  ll w;
  bool operator<(const edge &e) const {
    if (w == e.w) return id < e.id;
    return w < e.w;
  }
} E[200002];
int dsu[100002];
int root(int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = root(dsu[u]);
}
void join(int u, int v) {
  u = root(u);
  v = root(v);
  if (u != v) dsu[u] = v;
}
int main() {
  int n, m; ll d;
  cin >> n >> m >> d;
  for (int i=0;i<m;i++) {
    cin >> E[i].u >> E[i].v >> E[i].w;
    E[i].id = i;
  }
  sort(E, E+m);
  for (int i=1;i<=n;i++) dsu[i] = i;
  int day=0;
  ll mxW=0;
  for (int i=0;i<m;i++) {
    edge e = E[i];
    if (root(e.u) != root(e.v)) {
      join(e.u, e.v);
      mxW = max(mxW, e.w); 
      if (E[i].id >= n-1) {
        day++;
      }
    }
  } 
  if (mxW < d) {
    for (int i=1;i<=n;i++) dsu[i] = i;
    for (int i=0;i<m;i++) {
      edge e = E[i];
      if (root(e.u) != root(e.v)) {
        if (e.w < mxW || (e.w == mxW && E[i].id < n-1)) {
          join(e.u, e.v);
        } else if (E[i].id < n-1 && e.w <= d) {
          day--;
          break;
        }
      }
    }
  }
  cout << day << '\n';
}