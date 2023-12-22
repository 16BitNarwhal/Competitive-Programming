#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct E { int u, v, w; } ar[MM];
bool cmp(E a, E b) { return a.w > b.w; } 
int N, M, D, dest[MM], ptr=0, ans;
bool vis[MM];

int main() {
    cin >> N >> M >> D;
    for (int i=0;i<M;i++) cin>>ar[i].u>>ar[i].v>>ar[i].w;
    for (int i=0;i<D;i++) cin>>dest[i];
    sort(ar, ar+M, cmp); vis[1]=1;
    for (int i=0;i<M;i++) {
        vis[ar[i].u] = vis[ar[i].v] = 1;
        ans = ar[i].w;
        while (vis[dest[ptr]]) ptr++;
        if (ptr==D) break;
    }
    cout << ans;
}

// kruskal's
/*
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct edge {
  int u, v, w;
  bool operator<(const edge &o) const {
    return w > o.w;
  }
} ar[MM];
int rt[MM], sz[MM];
int root(int u) {
  if (rt[u]==u) return u;
  return rt[u] = root(rt[u]);
}
int join(int u, int v ) {
  int ru = root(u);
  int rv = root(v);
  rt[rv] = ru;
  sz[ru] += sz[rv];
  return sz[ru];
}
int main() {
  int n, m, D;
  cin >> n >> m >> D;
  for (int i=1;i<=n;i++) rt[i]=i;
  for (int i=0;i<m;i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ar[i] = {u, v, w};
  }
  for (int i=0;i<D;i++) {
    int x;cin>>x;
    sz[x]=1;
  }
  sort(ar, ar+m);
  for (int i=0;i<m;i++) {
    if (root(ar[i].u)!=root(ar[i].v)) {
      int sz = join(ar[i].u, ar[i].v);
      if (sz==D) {
        cout << ar[i].w << '\n';
        return 0;
      }
    }
  } 
}
*/