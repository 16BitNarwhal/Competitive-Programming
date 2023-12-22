// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int,int> pi;
// #define ff first
// #define ss second
// struct ed {
//   int a, b, w;
//   bool connected = false;
// };
// struct ed2 {
//   int u, v, w;
//   bool operator < (const ed2& o) const {
//     return w < o.w;
//   }
// };
// vector<ed> edges[101];
// int dsu[101];
// int root(int u) {
//   if (dsu[u] == u) return u;
//   return dsu[u] = root(dsu[u]);
// }
// void join(int a, int b) {
//   int ra = root(a);
//   int rb = root(b);
//   if (ra == rb) return;
//   dsu[ra] = rb;
// }
// int main() {
//   int n;cin>>n;
//   vector<ed2> allEd;
//   for (int u=1;u<=n;u++) {
//     int m;cin>>m;
//     vector<int> vec(m);
//     for (auto &j:vec) cin >> j;
//     for (int j=0;j<m;j++) {
//       int w;cin>>w;
//       edges[u].push_back({vec[j], vec[(j+1)%m], w});
//       ed &x = edges[u][j];
//       for (int v=1;v<u;v++) {
//         for (ed &y:edges[v]) {
//           if ((y.a == x.a && y.b == x.b) || 
//               (y.b == x.a && y.a == x.b)) {
//             y.connected = true;
//             x.connected = true;
//             allEd.push_back({u, v, w});
//           }
//         }
//       }
//     }
//   }
//   // mst (not connected to outside)
//   for (int i=1;i<=n;i++) dsu[i] = i;
//   int ans = 0;
//   sort(allEd.begin(), allEd.end());
//   for (auto e : allEd) {
//     if (root(e.u) != root(e.v)) {
//       ans += e.w;
//       join(e.u, e.v);
//     }
//   }
//   int rt = root(1);
//   for (int i=1;i<=n;i++) {
//     if (root(i) != rt) {
//       ans = 1e9;
//       break;
//     }
//   }
//   // mst (connected to outside)
//   int res = 0;
//   for (int u=1;u<=n;u++){
//     for (ed e : edges[u]) {
//       if (!e.connected) allEd.push_back({0, u, e.w});
//     }
//   }
//   // cout << "***\n";
//   // for (auto e : allEd) {
//   //   cout << e.u << " " << e.v << " " << e.w << "\n";
//   // }
//   // cout << "***\n";
//   for (int i=0;i<=n;i++) dsu[i] = i;
//   sort(allEd.begin(), allEd.end());
//   for (auto e : allEd) {
//     if (root(e.u) != root(e.v)) {
//       res += e.w;
//       join(e.u, e.v);
//     }
//   }
//   rt = root(0);
//   for (int i=0;i<=n;i++) {
//     if (root(i) != rt) {
//       res = 1e9;
//       break;
//     }
//   }
//   // cout << ans << ' ' << res << '\n';
//   ans = min(ans, res);
//   cout << ans << '\n';
// }

// prim
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi> adj[1005];
map<pi, vector<int>> mp;
map<pi, int> mpCst;
int n, dst[1005]; bool vis[1005];
bool prim(bool use0=false) {
  memset(dst, 0x3f, sizeof(dst));
  memset(vis, 0, sizeof(vis));
  dst[1] = 0; 
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0,1});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto [v, w] : adj[u]) {
      if (!use0 && v==0) continue; 
      if (vis[v]) continue;
      if (dst[v] > w) {
        dst[v] = w;
        pq.push({dst[v], v});
      }
    }
  }
  if (!use0) {
    for (int i=1;i<=n;i++) {
      if (dst[i]==0x3f3f3f3f) return false;
    }
  }
  return true;
}
int main() { 
  cin >> n;
  for (int i=1;i<=n;i++) {
    int m;cin>>m;
    vector<int> v(m), c(m);
    for (auto &j:v) cin>>j;
    for (auto &j:c) cin>>j;
    for (int j=0;j<m;j++) { 
      int a=v[j], b=v[(j+1)%m];
      
      if (a>b) swap(a,b);
      mp[{a,b}].push_back(i);
      mpCst[{a,b}] = c[j];
    }
  }
  for (auto [p, vec] : mp) {
    int u=vec[0];
    int v=0;
    if (vec.size()==2) 
      v = vec[1];
    adj[u].push_back({v, mpCst[p]});
    adj[v].push_back({u, mpCst[p]});
  }
  int ans = 0x3f3f3f3f;
  if (prim(false)) {
    int sum=0;
    for (int i=1;i<=n;i++) sum += dst[i];
    ans = min(ans, sum);
  }
  if (prim(true)) {
    int sum=0;
    for (int i=0;i<=n;i++) sum += dst[i];
    ans = min(ans, sum);
  }
  cout << ans << '\n';
}