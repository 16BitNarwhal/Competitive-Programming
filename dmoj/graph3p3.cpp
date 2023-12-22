#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, w, type;
  bool operator<(const edge &o) const {
    if (o.type != type) return type < o.type;
    return w < o.w;
  };
};
vector<edge> ed;
int rt[101];
int root(int x) {
  if (rt[x]==x) return x;
  return rt[x] = root(rt[x]);
}
void join(int u, int v) {
  int ru = root(u);
  int rv = root(v);
  if (ru==rv) return;
  rt[ru] = rv;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=1;i<=n;i++) rt[i] = i;
  for (int i=0;i<m;i++) {
    int u, v, w, type;
    cin >> u >> v >> w >> type;
    ed.push_back({u, v, w, type});
  }
  sort(ed.begin(), ed.end());
  int ans1=0, ans2=0;
  for (edge e:ed) {
    if (root(e.u)!=root(e.v)) {
      ans1 += e.type;
      ans2 += e.w;
      join(e.u, e.v);
    }
  }
  cout << ans1 << ' ' << ans2 << '\n';
}