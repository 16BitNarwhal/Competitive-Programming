#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int dsu[MM];
int root(int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = root(dsu[u]);
}
void join(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return;
  if (u < v) dsu[u] = v;
  else dsu[v] = u;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=1;i<=n;i++) dsu[i]=i;
    priority_queue<int> q;
    for (int i=1;i<=n;i++) {
      int x; cin >> x;
      while (!q.empty() && q.top() > x) {
        join(q.top(), x);
        q.pop();
      }
      q.push(dsu[x]);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
      if (dsu[i]==i) ans++;
    }
    cout << ans << '\n';
  }
}