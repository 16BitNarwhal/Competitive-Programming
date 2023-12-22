// // bellman
// #include <bits/stdc++.h>
// using namespace std;
// typedef long double ld;
// struct edge {
//   int u, v; 
//   ld w;
// } edges[4004];
// map<string, int> mp; 
// int n, m;
// ld dst[505];
// int main() {
//   cin >> n >> m;
//   for (int i=1;i<=n;i++) {
//     string s; cin >> s;
//     mp[s] = i;
//   }
//   for (int i=0;i<m;i++) {
//     string u, v; ld w;
//     cin >> u >> v >> w;
//     edges[i] = {mp[u], mp[v], w};
//   }
//   dst[mp["APPLES"]] = 1;
//   for (int i=0;i<n-1;i++) {
//     for (edge e : edges) {
//       dst[e.v] = max(dst[e.v], dst[e.u] * e.w);
//     }
//   }
//   for (edge e : edges) {
//     if (dst[e.u] * e.w > dst[e.v]) {
//       dst[e.v] = dst[e.u] * e.w;
//       if (e.v==mp["APPLES"]) {
//         cout << "YA\n";
//         return 0;
//       }
//     }
//   }
//   cout << "NAW\n";
// }

// spfa
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, ld> pi;
vector<pi> adj[505];
map<string, int> mp;
int n, m;
ld dst[505];
bool inq[505];
int main() {
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    string s;cin>>s;
    mp[s] = i;
  }
  for (int i=0;i<m;i++) {
    string u, v;ld w;
    cin>>u>>v>>w;
    adj[mp[u]].push_back({mp[v], w});
  }
  dst[mp["APPLES"]] = 1;
  queue<int> q;
  q.push(mp["APPLES"]);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inq[u] = false;
    if (u==mp["APPLES"] && dst[u]>1.0001) {
      cout << "YA\n";
      return 0;
    }
    for (auto [v, w] : adj[u]) {
      if (dst[v] < dst[u] * w) {
        dst[v] = dst[u] * w; 
        if (!inq[v]) { 
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
  cout << "NAW\n";
}