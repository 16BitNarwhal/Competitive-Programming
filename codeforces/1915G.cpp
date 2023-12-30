#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1010;
struct edge {
  int v;
  ll w;
};
int n, m;
vector<edge> adj[MM];
map<int,ll> dst[MM];
int slow[MM];
int main() {
  int _;cin>>_;
  while(_--) {
    cin >> n >> m;
    for (int i=1;i<=n;i++) adj[i].clear();
    for (int i=1;i<=n;i++) dst[i].clear();
    
    for (int i=0;i<m;i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++) cin >> slow[i];
    
    dst[1][slow[1]] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    pq.push(make_tuple(0, 1, slow[1]));
    
    while (!pq.empty()) {
      tuple<ll, int, int> t = pq.top();
      pq.pop();
      ll d = get<0>(t);
      int u = get<1>(t);
      int s = get<2>(t);
      if (d > dst[u][s]) continue;
      
      if (u==n) {
        cout << d << '\n';
        break;
      }

      for (edge e : adj[u]) {
        int s2 = min(s, slow[e.v]);
        if (dst[e.v].count(s2) == 0 || dst[u][s]+(e.w*s) < dst[e.v][s2]) {
          dst[e.v][s2] = dst[u][s] + (s*e.w);
          pq.push(make_tuple(dst[e.v][s2], e.v, s2));
        }
      }
    }
  }
}