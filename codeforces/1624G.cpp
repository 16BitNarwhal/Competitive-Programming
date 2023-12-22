#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct edge {
  int u, v, w;
} lst[MM];
int n, m, dsu[MM];
int root(int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = root(dsu[u]);
}
void join(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return;
  dsu[u] = v;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n>>m;
    for (int i=0;i<m;i++) {
      cin >> lst[i].u >> lst[i].v >> lst[i].w;
    } 
    int ans = (1<<30)-1;
    for (int k=29;k>=0;k--) {
      ans -= (1<<k);
      // check
      for (int i=1;i<=n;i++) dsu[i]=i;
      for (int i=0;i<m;i++) {
        if ((lst[i].w | ans) == ans) {
          join(lst[i].u, lst[i].v);
        }
      }
      int rt = root(1);
      bool res = true;
      for (int i=1;i<=n;i++) {
        if (root(i) != rt) res = false;
      } 
      if (!res) ans += (1<<k); 
    }
    cout << ans << '\n';
  }
}